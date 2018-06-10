#include <Windows.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

struct Otimono {
	int posX;
	int posY;
	int dead = 0;
};

//プレイヤーの構造体
struct SPlayer {
	int posX;
	int posY;
	int score;
};


//マップの高さ。
const int FRAME_BUFFER_HEIGHT = 20;
//マップの幅。
const int FRAME_BUFFER_WIDTH = 20;

char sFrameBuffer[FRAME_BUFFER_HEIGHT][FRAME_BUFFER_WIDTH];

int main()
{
	std::vector<Otimono>	otimonoArray;	//落ち物の可変長配列。
	int gameCount = 0;

	//乱数を初期化。
	srand((unsigned)time(NULL));

	//２次元配列。教科書のp.256から配列に関する記述があります。多次元配列はp.269
	int map[16][16] = {
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  0列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  1列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  2列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  3列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  4列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  5列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  6列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  7列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  8列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  9列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 10列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 11列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 12列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 13列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 14列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 15列目
		
	};

	//プレイヤー１。
	SPlayer player[2];
	player[0].posX = 3;
	player[0].posY = 15;
	player[0].score = 0;
	//プレイヤー２。
	player[1].posX = 12;
	player[1].posY = 15;
	player[1].score = 0;
	
	//ここからゲームループ。
	while (true) {
		//1フレームの開始。
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
		//背景を描画。
		//二次元配列のmapを参照して、背景を描画していく。
		for (int y = 0; y < 16; y++) {
			for (int x = 0; x < 16; x++) {
				if (map[y][x] == 0) {
					//2次元配列のmap[y][x]に0が入っていたら、
					//座標x, yの場所に空白文字を描画する。
					if (x < FRAME_BUFFER_WIDTH && y < FRAME_BUFFER_HEIGHT) {
						sFrameBuffer[y][x] = ' ';
					}
				}
				else if (map[y][x] == 1) {
					//2次元配列のmap[y][x]に1が入っていたら、
					//座標x, yの場所に@を描画する。
					if (x < FRAME_BUFFER_WIDTH && y < FRAME_BUFFER_HEIGHT) {
						sFrameBuffer[y][x] = '@';
					}
				}
			}
		}
		//プレイヤー１の移動処理。
		for (int playerNo = 0; playerNo < 2; playerNo++) {
			if (playerNo == 0) {
				//1プレイヤー。
				//プレイヤー１の移動処理。
				if (GetAsyncKeyState(VK_LEFT) != 0) {
					//左のキーが押されたときの処理をここに記述する。
					player[playerNo].posX--;
				}
				if (GetAsyncKeyState(VK_RIGHT) != 0) {
					player[playerNo].posX++;
				}
			}
			else if (playerNo == 1) {
				//2プレイヤー。
				//続いてプレイヤー２の移動処理。
				if (GetAsyncKeyState('A') != 0) {
					//左のキーが押されたときの処理をここに記述する。
					player[playerNo].posX--;
				}
				if (GetAsyncKeyState('D') != 0) {
					player[playerNo].posX++;
				}
			}
			//壁判定。
			if (player[playerNo].posX < 1) {
				player[playerNo].posX = 1;
			}
			if (player[playerNo].posX > 14) {
				player[playerNo].posX = 14;
			}
			//落ち物との衝突判定。
			for (int i = 0; i < otimonoArray.size(); i++) {
				if (otimonoArray[i].posX == player[playerNo].posX
					&& otimonoArray[i].posY == player[playerNo].posY
					) {
					otimonoArray[i].dead = 1;
					//ゲット出来ていたらカウントアップ。
					player[playerNo].score++;
				}
			}
			//プレイヤー１を描画する。
			if (player[playerNo].posX < FRAME_BUFFER_WIDTH && player[playerNo].posY < FRAME_BUFFER_HEIGHT) {
				sFrameBuffer[player[playerNo].posY][player[playerNo].posX] = 'P';		
			}
		}

		//落ち物のプログラムを実行。
		gameCount++;
		if (gameCount == 10) {
			//30フレーム経過したら新しい落ち物を発生させる。
			Otimono otimono;
			//落ち物のX座標をランダムで決定。
			otimono.posX = (rand() % 14) + 1;
			otimono.posY = 0;
			//ゲームカウントを0に戻す。
			gameCount = 0;
			otimonoArray.push_back(otimono);
		}
		//全ての落ち物を落下させる。
		for (auto& otimono : otimonoArray) {
			if ((gameCount % 5) == 0) {
				//5フレームに一度落下する。
				otimono.posY += 1;
			}
		}
		//リストから削除。	
		otimonoArray.erase(std::remove_if(otimonoArray.begin(), otimonoArray.end(), [&](auto& otimono)->bool {
			return otimono.posY == 18 || otimono.dead == 1;
		}), otimonoArray.end());

		//落ち物を描画。
		for (auto& otimono : otimonoArray) {
			if (otimono.posX < FRAME_BUFFER_WIDTH && otimono.posX < FRAME_BUFFER_HEIGHT) {
				sFrameBuffer[otimono.posY][otimono.posX] = '*';
			}
		}

		//スコアを表示する。
		char scoreText[256];
		sprintf_s(scoreText, "Player1　スコア %d", player[0].score);
		for (int i = 0; scoreText[i] != '\0'; i++) {
			sFrameBuffer[18][0 + i] = scoreText[i];
		}
		sprintf_s(scoreText, "Player2　スコア %d", player[1].score);
		for (int i = 0; scoreText[i] != '\0'; i++) {
			sFrameBuffer[19][0 + i] = scoreText[i];
		}
		//1フレームの終了。
		//フレームバッファの内容を画面に表示する。
		for (int i = 0; i < FRAME_BUFFER_HEIGHT; i++) {
			for (int j = 0; j < FRAME_BUFFER_WIDTH; j++) {
				std::cout << sFrameBuffer[i][j];
			}
			std::cout << "\n";
		}
		//32ミリ秒眠る。
		Sleep(16);
		//標準出力コンソールのハンドルを取得。
		hCons = GetStdHandle(STD_OUTPUT_HANDLE);
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

	return 0;
}