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

void DrawScore(SPlayer player[2])
{
	char scoreText[256];
	sprintf_s(scoreText, "Player1　スコア %d", player[0].score);
	kbcDrwaMojiRetu(0, 18, scoreText);
	
	sprintf_s(scoreText, "Player2　スコア %d", player[1].score);
	kbcDrwaMojiRetu(0, 19, scoreText);
}
//プレイヤーを描画。
void DrawPlayer(SPlayer& player)
{
	kbcDrawMoji(player.posX, player.posY, 'P');
}
//プレイヤーの移動処理。
//引数1　player		プレイヤーのアドレス。関数内部でプレイヤーの値を変更して、
//					それを呼び出し元のプレイヤーに反映させたいときは参照を渡す。
//引数2  playerNo	プレイヤーの番号。
void MovePlayer(SPlayer& player, int playerNo) 
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
//プレイヤーと落ち物の衝突判定
void CheckHitPlayerAndOtimono( SPlayer& player )
{
	for (int i = 0; i < otimonoArray.size(); i++) {
		if (otimonoArray[i].posX == player.posX
			&& otimonoArray[i].posY == player.posY
			) {
			otimonoArray[i].dead = 1;
			//ゲット出来ていたらカウントアップ。
			player.score++;
		}
	}
}
//背景を描画。
void DrawBackground()
{
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
}
int main()
{
	//乱数を初期化。
	srand((unsigned)time(NULL));
	//プレイヤー。
	SPlayer player[2];
	player[0].posX = 3;
	player[0].posY = 15;
	player[0].score = 0;

	player[1].posX = 12;
	player[1].posY = 15;
	player[1].score = 0;

	//ここからゲームループ。
	while (true) {
		//1フレームの開始。
		kbcBeginFrame();
		//背景を描画。
		DrawBackground();
		//プレイヤーの処理。
		for (int i = 0; i < 2; i++) {
			MovePlayer(player[i], i);
			//落ち物との衝突判定。
			CheckHitPlayerAndOtimono(player[i]);
			//プレイヤー１を描画する。
			DrawPlayer(player[i]);
		}
		//落ち物の描画処理。
		DrawOtimono();
		//落ち物の移動処理。
		MoveOtimono();
		//スコアを表示する。
		DrawScore(player);
		//1フレームの終了。
		kbcEndFrame();
	}

	return 0;
}