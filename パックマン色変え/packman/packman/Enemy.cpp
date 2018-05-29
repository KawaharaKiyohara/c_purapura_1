#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"

CEnemy g_enemyArray[MAX_ENEMY];	//エネミーの配列。

void CEnemy::Initialyze( int x, int y)
{
	initPosX = x;
	initPosY = y;
	posX = x;
	posY = y;
}
void CEnemy::Update()
{
	//ステートによって処理を分岐。
	//このような処理を有限状態機械と呼ぶ。
	//敵でもプレイヤーでもゲームの進行などでも良く使うパターンです。
	//しっかり使えるようになろう。
	if (state == EnemyState_Haikai) {
		//徘徊。
		//プレイヤーとの距離が一定値以下になったら、追跡状態になるぞい。
		if (fabsf(g_player.posX - posX) < 3
			&& fabsf(g_player.posY - posY) < 3
			) {
			//プレイヤーとの距離が一定値以下になったので、
			//追跡ステートに遷移。
			state = EnemyState_Tuiseki;
		}
	}
	else if (state == EnemyState_Tuiseki) {
		//追跡。
		waitCount--;
		if( waitCount == 0) { //ウェイトが0になったら移動する。
			//プレイヤーの位置目指して、パス検索。
			std::vector<Vector2> root;
			g_pathFinding.FindRoot(
				root,
				{ posX , posY },
				{ g_player.posX, g_player.posY }
			);
			if (!root.empty()) {
				posX = root[0].x;
				posY = root[0].y;
			}
			waitCount = 5;
		}
		if (fabsf(g_player.posX - posX) > 4
			&& fabsf(g_player.posY - posY) > 4
			) {
			//プレイヤーとの距離が一定値以下になったので、
			//帰還ステートに遷移。
			state = EnemyState_Return;
		}
	}
	else if (state == EnemyState_Return) {
		//初期位置に帰還。
		//初期位置を目指して、パス検索。
		std::vector<Vector2> root;
		g_pathFinding.FindRoot(
			root,
			{ posX , posY },
			{ initPosX, initPosY }
		);
		if (!root.empty()) {
			posX = root[0].x;
			posY = root[0].y;
			if (posX == initPosX
				&& posY == initPosY
				) {
				//帰還した。
				state = EnemyState_Haikai;
			}
		}
	}
	
}
void CEnemy::Draw()
{
	if (state == EnemyState_Tuiseki) {
		//追跡中。
		kbcDrawMoji(
			posX,
			posY,
			'E',
			enStringColor_Red
		);
	}
	else {
		kbcDrawMoji(
			posX,
			posY,
			'e',
			enStringColor_DarkRed
		);
	}
}