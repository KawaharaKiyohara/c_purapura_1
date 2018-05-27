#include <iostream>
#include "consoleLib.h"
#include "otimono.h"
#include <time.h>
#include <stdlib.h>

//プレイヤーの構造体
struct SPlayer {
	int posX;
	int posY;
	int score;
};

//プレイヤーの移動処理。
//引数1　player		プレイヤーのアドレス。関数内部でプレイヤーの値を変更して、
//					それを呼び出し元のプレイヤーに反映させたいときは参照を渡す。
//引数2  playerNo	プレイヤーの番号。
void PlayerMove(SPlayer& player, int playerNo) 
{
	if (playerNo == 0) {
		//1プレイヤー。
		//プレイヤー１の移動処理。
		if (GetAsyncKeyState(VK_LEFT) != 0) {
			//左のキーが押されたときの処理をここに記述する。
			player.posX--;
		}
		if (GetAsyncKeyState(VK_RIGHT) != 0) {
			player.posX++;
		}
	}
	else if (playerNo == 1) {
		//2プレイヤー。
		//続いてプレイヤー２の移動処理。
		if (GetAsyncKeyState('A') != 0) {
			//左のキーが押されたときの処理をここに記述する。
			player.posX--;
		}
		if (GetAsyncKeyState('D') != 0) {
			player.posX++;
		}
	}
	//壁判定。
	if (player.posX < 1) {
		player.posX = 1;
	}
	if (player.posX > 14) {
		player.posX = 14;
	}

}
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

	//プレイヤー１。
	SPlayer player;
	player.posX = 3;
	player.posY = 15;
	player.score = 0;
	//プレイヤー２。
	SPlayer player2;
	player2.posX = 12;
	player2.posY = 15;
	player2.score = 0;
	
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

			//プレイヤー１の移動処理。
			PlayerMove(player, 0);
			
			//落ち物との衝突判定。
			for (int i = 0; i < otimonoArray.size(); i++) {
				if ( otimonoArray[i].posX == player.posX
					&& otimonoArray[i].posY == player.posY
				) {
					otimonoArray[i].dead = 1;
					player.score++;
				}
			}
			//プレイヤーを描画する。
			kbcDrawMoji(player.posX, player.posY, 'P');

			//続いてプレイヤー２の移動処理。
			PlayerMove(player2, 1);
			
			//落ち物との衝突判定。
			for (int i = 0; i < otimonoArray.size(); i++) {
				if (otimonoArray[i].posX == player2.posX
					&& otimonoArray[i].posY == player2.posY
					) {
					otimonoArray[i].dead = 1;
					player2.score++;
				}
			}
			//プレイヤーを描画する。
			kbcDrawMoji(player2.posX, player2.posY, 'L');

			//落ち物のプログラムを実行。
			OtimonoProgram();

			//スコアを表示する。
			//文字列は教科書のp.284に記載があります。
			//sprintf_sはマイクロソフトが独自に用意したもので、
			//C言語の標準関数のsprintfをセキュア(安全)にしたものです。
			//sprintfの挙動についてはググりましょう。
			char scoreText[256];
			sprintf_s(scoreText, "Player1　スコア %d", player.score);
			kbcDrwaMojiRetu(0, 18, scoreText);

			sprintf_s(scoreText, "Player2　スコア %d", player2.score);
			kbcDrwaMojiRetu(0, 19, scoreText);

			
		}
		// ここまでの間にゲームのプログラムを書いていってね//////////////////////
		
		//1フレームの終了。
		kbcEndFrame();
	}

	return 0;
}