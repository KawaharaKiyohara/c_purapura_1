#include "stdafx.h"

//マップの高さ。
const int FRAME_BUFFER_HEIGHT = 20;
//マップの幅。
const int FRAME_BUFFER_WIDTH = 20;

//文字バッファ。
static char sFrameBuffer[FRAME_BUFFER_HEIGHT][FRAME_BUFFER_WIDTH];
//カラーバッファ。
static EnStringColor sStringColorBuffer[FRAME_BUFFER_HEIGHT][FRAME_BUFFER_WIDTH];


#define     COL_INTENSITY     0x08     // 高輝度マスク
#define     COL_RED_MASK     0x04     // 赤色ビット
#define     COL_GREEN_MASK 0x02     // 緑色ビット
#define     COL_BLUE_MASK   0x01     //  青色ビット

void SetColor(int col)
{
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);     // コンソールハンドル取得
	WORD attr = 0;     //  API に渡すアトリビュート
	if (col & COL_INTENSITY)       // 高輝度ビットが立っていれば
		attr |= FOREGROUND_INTENSITY;      //  アトリビュートの高輝度ビットを立てる
	if (col & COL_RED_MASK)
		attr |= FOREGROUND_RED;
	if (col & COL_GREEN_MASK)
		attr |= FOREGROUND_GREEN;
	if (col & COL_BLUE_MASK)
		attr |= FOREGROUND_BLUE;
	SetConsoleTextAttribute(hCons, attr);        // 色指定
}


void kbcDrawMojiRetu(int startPosX, int posY, const char* mojiretu, EnStringColor color)
{
	for (int i = 0; mojiretu[i] != '\0'; i++) {
		kbcDrawMoji(startPosX + i, posY, mojiretu[i], color);
	}
}
bool kbcDrawMoji(int posX, int posY, char moji, EnStringColor color)
{
	//フレームバッファの幅と高さを超えていないかチェーック。
	if (posX < FRAME_BUFFER_WIDTH && posY < FRAME_BUFFER_HEIGHT) {
		sFrameBuffer[posY][posX] = moji;
		sStringColorBuffer[posY][posX] = color;
		//描けた
		return true;
	}
	//描けなかった。
	return false;
}
void kbcBeginFrame()
{
	//フォントのサイズの設定。
	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX info = { sizeof info };
	info.dwFontSize.X = 32;
	info.dwFontSize.Y = 32;
	SetCurrentConsoleFontEx(hConsole, 0, &info);

	//コンソールの縦と横の行数を設定。
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwSize = { 9999, 9999 };
	SetConsoleScreenBufferSize(
		hCons,			// HANDLE hConsoleOutput
		dwSize);        // COORD dwSiz

	//コンソールの高さを設定。
	SMALL_RECT consoleWindow = { 0, 0, 20, 20 };
	BOOL ret = SetConsoleWindowInfo(
		hCons, // HANDLE hConsoleOutput
		TRUE,           // BOOL bAbsolute
		&consoleWindow);// CONST SMALL_RECT *lpConsoleWindow

	//文字バッファをクリア。
	memset(sFrameBuffer, 0, sizeof(sFrameBuffer));
	//カラーバッファをクリア。
	memset(sStringColorBuffer, enStringColor_White, sizeof(sStringColorBuffer));
}
void kbcEndFrame()
{
	EnStringColor currentStringColor = enStringColor_White;
	//最初は文字を白にセットする。
	SetColor(currentStringColor);	
	//フレームバッファの内容を画面に表示する。
	for (int i = 0; i < FRAME_BUFFER_HEIGHT; i++) {
		for (int j = 0; j < FRAME_BUFFER_WIDTH; j++) {
			if (currentStringColor != sStringColorBuffer[i][j]) {
				//色が変わった。
				currentStringColor = sStringColorBuffer[i][j];
				SetColor(currentStringColor);
			}
			std::cout << sFrameBuffer[i][j];
		}
		std::cout << "\n";
	}

	//16ミリ秒眠る。
	Sleep(16);

	//標準出力コンソールのハンドルを取得。
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	//標準コンソールのカーソルを0行目、0列に戻す。
	SetConsoleCursorPosition(hCons, pos);

	CONSOLE_CURSOR_INFO cci;
	// CONSOLE_CURSOR_INFO構造体の現在の状態を取得する
	GetConsoleCursorInfo(hCons, &cci);

	// メンバ変数であるbVisibleがカーソルの表示・非表示を制御する変数なので、これをFALSEにする事でカーソルを非表示にできる
	cci.bVisible = FALSE;

	// 変更した構造体情報をコンソールWindowにセットする
	SetConsoleCursorInfo(hCons, &cci);
}