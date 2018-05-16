#include "stdafx.h"
#include "Enemy.h"


SEnemy g_enemyArray[MAX_ENEMY];	//エネミーの配列。

void EnemyInitialyze(int enemyNo, int posX, int posY)
{
	g_enemyArray[enemyNo].initPosX = posX;
	g_enemyArray[enemyNo].initPosY = posY;
	g_enemyArray[enemyNo].posX = posX;
	g_enemyArray[enemyNo].posY = posY;
}
void EnemyUpdate(int enemyNo)
{
	//ステートによって処理を分岐。
	//このような処理を有限状態機械と呼ぶ。
	//敵でもプレイヤーでもゲームの進行などでも良く使うパターンです。
	//しっかり使えるようになろう。
	if (g_enemyArray[enemyNo].state == EnemyState_Haikai) {
		//徘徊。
		//プレイヤーとの距離が一定値以下になったら、追跡状態になるぞい。
		if (fabsf(playerPosX - g_enemyArray[enemyNo].posX) < 3
			&& fabsf(playerPosY - g_enemyArray[enemyNo].posY) < 3
			) {
			//プレイヤーとの距離が一定値以下になったので、
			//追跡ステートに遷移。
			g_enemyArray[enemyNo].state = EnemyState_Tuiseki;
		}
	}
	else if (g_enemyArray[enemyNo].state == EnemyState_Tuiseki) {
		//追跡。
		g_enemyArray[enemyNo].waitCount--;
		if (g_enemyArray[enemyNo].waitCount == 0) { //ウェイトが0になったら移動する。
			//プレイヤーの位置目指して、パス検索。
			std::vector<Vector2> root;
			g_pathFinding.FindRoot(
				root,
				{ g_enemyArray[enemyNo].posX , g_enemyArray[enemyNo].posY },
				{ playerPosX, playerPosY }
			);
			if (!root.empty()) {
				g_enemyArray[enemyNo].posX = root[0].x;
				g_enemyArray[enemyNo].posY = root[0].y;
			}
			g_enemyArray[enemyNo].waitCount = 5;
		}
		if (fabsf(playerPosX - g_enemyArray[enemyNo].posX) > 4
			&& fabsf(playerPosY - g_enemyArray[enemyNo].posY) > 4
			) {
			//プレイヤーとの距離が一定値以下になったので、
			//帰還ステートに遷移。
			g_enemyArray[enemyNo].state = EnemyState_Return;
		}
	}
	else if (g_enemyArray[enemyNo].state == EnemyState_Return) {
		//初期位置に帰還。
		//初期位置を目指して、パス検索。
		std::vector<Vector2> root;
		g_pathFinding.FindRoot(
			root,
			{ g_enemyArray[enemyNo].posX , g_enemyArray[enemyNo].posY },
			{ g_enemyArray[enemyNo].initPosX, g_enemyArray[enemyNo].initPosY }
		);
		if (!root.empty()) {
			g_enemyArray[enemyNo].posX = root[0].x;
			g_enemyArray[enemyNo].posY = root[0].y;
			if (g_enemyArray[enemyNo].posX == g_enemyArray[enemyNo].initPosX
				&& g_enemyArray[enemyNo].posY == g_enemyArray[enemyNo].initPosY
				) {
				//帰還した。
				g_enemyArray[enemyNo].state = EnemyState_Haikai;
			}
		}
	}
	
}
void EnemyDraw(int enemyNo)
{
	if (g_enemyArray[enemyNo].state == EnemyState_Tuiseki) {
		//追跡中。
		kbcDrawMoji(
			g_enemyArray[enemyNo].posX,
			g_enemyArray[enemyNo].posY,
			'E'
		);
	}
	else {
		kbcDrawMoji(
			g_enemyArray[enemyNo].posX,
			g_enemyArray[enemyNo].posY,
			'e'
		);
	}
}