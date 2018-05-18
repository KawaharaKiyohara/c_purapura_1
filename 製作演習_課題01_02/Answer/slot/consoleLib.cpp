#include <iostream>
#include "consoleLib.h"

//マップの高さ。
const int FRAME_BUFFER_HEIGHT = 20;
//マップの幅。
const int FRAME_BUFFER_WIDTH = 20;

static char sFrameBuffer[FRAME_BUFFER_HEIGHT][FRAME_BUFFER_WIDTH];

bool isPressA = false;
bool isTriggerA = false;

void kbcDrawMojiRetu(int startPosX, int posY, const char* mojiretu)
{
	for (int i = 0; mojiretu[i] != '\0'; i++) {
		kbcDrawMoji(startPosX + i, posY, mojiretu[i]);
	}
}
bool kbcDrawMoji(int posX, int posY, char moji)
{
	//フレームバッファの幅と高さを超えていないかチェーック。
	if (posX < FRAME_BUFFER_WIDTH && posY < FRAME_BUFFER_HEIGHT) {
		sFrameBuffer[posY][posX] = moji;
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

	//フレームバッファをクリア。
	memset(sFrameBuffer, 0, sizeof(sFrameBuffer));
}
void kbcEndFrame()
{
	//フレームバッファの内容を画面に表示する。
	for (int i = 0; i < FRAME_BUFFER_HEIGHT; i++) {
		for (int j = 0; j < FRAME_BUFFER_WIDTH; j++) {
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

	isTriggerA = false;

	if (GetAsyncKeyState('A') == 0) {
		isPressA = false;
		isTriggerA = false;
	}
	else {
		if (isPressA == false) {
			isTriggerA = true;
		}

		isPressA = true;
	}
}
int kbcIsTriggerA()
{
	return isTriggerA;
}