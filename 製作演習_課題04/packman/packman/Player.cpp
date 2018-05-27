#include "stdafx.h"
#include "Player.h"
#include "Enemy.h"
#include "Food.h"

SPlayer g_player;

void PlayerUpdate()
{
	//移動前の座標を保存。
	int oldPosX = g_player.posX;
	int oldPosY = g_player.posY;
	if (GetAsyncKeyState(VK_LEFT) != 0) {
		//左に移動。
		g_player.posX--;
	}
	else if (GetAsyncKeyState(VK_RIGHT) != 0) {
		//右に移動。
		g_player.posX++;
	}
	else if (GetAsyncKeyState(VK_UP) != 0) {
		//上に移動。
		g_player.posY--;
	}
	else if (GetAsyncKeyState(VK_DOWN) != 0) {
		//下に移動。
		g_player.posY++;
	}
	//移動先をチェック。
	//壁判定
	if (g_map[g_player.posY][g_player.posX] == 1) {
		//壁なので、座標を戻す。
		g_player.posX = oldPosX;
		g_player.posY = oldPosY;

	}
	//敵との衝突判定。
	for (int no = 0; no < g_enemyNum; no++) {
		if (g_enemyArray[no].posX == g_player.posX
			&& g_enemyArray[no].posY == g_player.posY
			) {
			//敵とぶつかった。
			g_player.isDead = 1;	//死亡フラグを立てる。
		}
	}
	//食べ物との衝突判定。
	for (int no = 0; no < g_foodNum; no++) {
		if (g_foodArray[no].posX == g_player.posX
			&& g_foodArray[no].posY == g_player.posY
			) {
			//食べ物とぶつかった。
			//食べ物の死亡フラグを立てる。
			g_foodArray[no].isDead = 1;

		}
	}
}

void PlayerDraw()
{
	kbcDrawMoji(g_player.posX, g_player.posY, 'P');
}