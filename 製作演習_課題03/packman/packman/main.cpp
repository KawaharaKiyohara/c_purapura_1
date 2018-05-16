//cppファイルは#include stdafx.hを必ずソースの先頭に書いてね！！！
#include "stdafx.h"	　
#include "Background.h"
#include "Enemy.h"
#include "Food.h"

/////////////////////////////////////////////////////
// グローバル変数
/////////////////////////////////////////////////////
//マップ定義。
int g_map[16][16] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },	//  0列目
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  1列目
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  2列目
	{ 1, 0, 1, 1, 2, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1 },	//  3列目
	{ 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  4列目
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1 },	//  5列目
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },	//  6列目
	{ 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 2, 0, 1 },	//  7列目
	{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1 },	//  8列目
	{ 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1 },	//  9列目
	{ 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },	// 10列目
	{ 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 11列目
	{ 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },	// 12列目
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 13列目
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1 },	// 14列目
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },	// 15列目

};

//パスファイディング。
CPathFinding g_pathFinding;

//プレイヤー関係のグローバル変数。
int playerIsDead = 0;	//プレイヤーの死亡フラグ。1になったら死亡。
int playerPosX = 7;
int playerPosY = 7;

//敵の数。
int g_enemyNum = 0;

//食べ物の数。
int g_foodNum = 0;

/////////////////////////////////////////////////////
// 関数
/////////////////////////////////////////////////////
/*!----------------------------------------------------
*@brief	ゲームの初期化。
----------------------------------------------------*/
void GameInitialize()
{
	//g_mapをもとに、エネミーと食べ物を初期化していく。
	for ( int x = 0; x < 16; x++ ) {
		for ( int y = 0; y < 16; y++ ) {
			if ( g_map[y][x] == 2 ) {
				//敵だよ。
				EnemyInitialyze( g_enemyNum, x, y );
				g_enemyNum++; //敵の数をインクリメント。
			}
			else if ( g_map[y][x] == 0 ) {
				//食べ物だよ。
				FoodInitialyze( g_foodNum, x, y );
				g_foodNum++;
			}
		}
	}

	//パスファインディングを初期化。
	g_pathFinding.BuildNodes();
}
/*!----------------------------------------------------
*@brief	メイン関数。
----------------------------------------------------*/
int main()
{
	//ゲームを初期化。
	GameInitialize();

	int gameClear = 0;	//ゲームクリアフラグ。
	//ここからゲームループ。
	while (true) {
		//1フレームの開始。
		kbcBeginFrame();
		// ここから ///////////////////////////////////////////////////////////
		if (gameClear == 1) { //ゲームクリア？。
			kbcDrawMojiRetu(0, 0, "げーむくりあ");
		}else if(playerIsDead == 0){	//プレイヤーが死亡していないときの処理。
			//敵の更新。
			for (int no = 0; no < g_enemyNum; no++) {
				EnemyUpdate(no);
			}
			//食べ物の更新。
			for (int no = 0; no < g_foodNum; no++) {
				FoodUpdate(no);
			}
			////////////////////////////////////////////////////////
			// プレイヤーの更新処理。
			////////////////////////////////////////////////////////
			{
				//移動前の座標を保存。
				int oldPosX = playerPosX;
				int oldPosY = playerPosY;
				if (GetAsyncKeyState(VK_LEFT) != 0) {
					//左に移動。
					playerPosX--;
				}
				else if (GetAsyncKeyState(VK_RIGHT) != 0) {
					//右に移動。
					playerPosX++;
				}
				else if (GetAsyncKeyState(VK_UP) != 0) {
					//上に移動。
					playerPosY--;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0) {
					//下に移動。
					playerPosY++;
				}
				//移動先をチェック。
				//壁判定
				if (g_map[playerPosY][playerPosX] == 1) {
					//壁なので、座標を戻す。
					playerPosX = oldPosX;
					playerPosY = oldPosY;
					
				}
				//敵との衝突判定。
				for (int no = 0; no < g_enemyNum; no++) {
					if (g_enemyArray[no].posX == playerPosX
						&& g_enemyArray[no].posY == playerPosY
						) {
						//敵とぶつかった。
						playerIsDead = 1;	//死亡フラグを立てる。
					}
				}
				//食べ物との衝突判定。
				for (int no = 0; no < g_foodNum; no++) {
					if (g_foodArray[no].posX == playerPosX
						&& g_foodArray[no].posY == playerPosY
						) {
						//食べ物とぶつかった。
						//食べ物の死亡フラグを立てる。
						g_foodArray[no].isDead = 1;
						
					}
				}
			}
			//背景を描画。
			DrawBackground();

			//食べ物の描画。
			for (int no = 0; no < g_foodNum; no++) {
				FoodDraw(no);
			}

			//敵の描画処理。
			for (int no = 0; no < g_enemyNum; no++) {
				EnemyDraw(no);
			}
			////////////////////////////////////////////////////////
			// プレイヤーの描画処理。
			////////////////////////////////////////////////////////
			kbcDrawMoji(playerPosX, playerPosY, 'P');
		}
		else {
			//プレイヤーが死亡しているときの処理。
			kbcDrawMojiRetu(0, 0, "げーむおーばー");
		}
		// ここまでの間にゲームのプログラムを書いていってね//////////////////////
		
		//1フレームの終了。
		kbcEndFrame();
	}

	return 0;
}