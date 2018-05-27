#include <iostream>
#include "consoleLib.h"
#include "otimono.h"
#include <time.h>
#include <stdlib.h>


int main()
{
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

	////プレイヤーの座標。コメントアウトして削除
	int playerPosX = 8;
	int playerPosY = 15;

	int getCount = 0;
	//ここからゲームループ。
	while (true) {
		//1フレームの開始。
		kbcBeginFrame();
		// ここから ///////////////////////////////////////////////////////////
		{
			//背景を描画。
			//二次元配列のmapを参照して、背景を描画していく。
			for (int y = 0; y < 16; y++) {
				for (int x = 0; x < 16; x++) {
					if (map[y][x] == 0) {
						//2次元配列のmap[y][x]に0が入っていたら、
						//座標x, yの場所に空白文字を描画する。
						kbcDrawMoji(x, y, ' ');
					}
					else if (map[y][x] == 1) {
						//2次元配列のmap[y][x]に1が入っていたら、
						//座標x, yの場所に@を描画する。
						kbcDrawMoji(x, y, '@');
					}
				}
			}

			if (GetAsyncKeyState(VK_LEFT) != 0) {
				//左のキーが押されたときの処理をここに記述する。
				playerPosX--;
			}
			if (GetAsyncKeyState(VK_RIGHT) != 0) {
				playerPosX++;
			}
			
			//playerの衝突判定。
			if (playerPosX < 1) {
				playerPosX = 1;
			}
			if (playerPosX > 14) {
				playerPosX = 14;
			}
			//落ち物との衝突判定。
			for (int i = 0; i < otimonoArray.size(); i++) {
				if ( otimonoArray[i].posX == playerPosX
					&& otimonoArray[i].posY == playerPosY
				) {
					otimonoArray[i].dead = 1;
					getCount++;
				}
			}
			//プレイヤーを描画する。
			kbcDrawMoji(playerPosX, playerPosY, 'P');

			//落ち物のプログラムを実行。
			OtimonoProgram();

			//スコアを表示する。
			//文字列は教科書のp.284に記載があります。
			//sprintf_sはマイクロソフトが独自に用意したもので、
			//C言語の標準関数のsprintfをセキュア(安全)にしたものです。
			//sprintfの挙動についてはググりましょう。
			char scoreText[256];
			sprintf_s(scoreText, "スコア %d", getCount);
			kbcDrwaMojiRetu(0, 18, scoreText);

			
		}
		// ここまでの間にゲームのプログラムを書いていってね//////////////////////
		
		//1フレームの終了。
		kbcEndFrame();
	}

	return 0;
}