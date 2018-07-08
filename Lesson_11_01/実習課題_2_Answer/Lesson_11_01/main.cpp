//cppファイルは#include stdafx.hを必ずソースの先頭に書いてね！！！
#include "stdafx.h"	　
#include <iostream>

/////////////////////////////////////////////////////
// 構造体
/////////////////////////////////////////////////////

//Hands-On 1 Player構造体を作成しよう。
struct Player {
	int posX;
	int posY;
	int Hp;
};
//実習１ Enemy構造体を作成しよう。
//       Enemy構造体はメンバ変数に、int型のposXとposYを保持しているだけの構造体です。
struct Enemy {
	int posX;
	int posY;
};
/////////////////////////////////////////////////////
// 関数
/////////////////////////////////////////////////////
//Hands-On 2 プレイヤーを動かす関数を定義しよう。
//キー入力でプレイヤーを動かす。
void MovePlayer(Player& pl)
{
	if (GetAsyncKeyState(VK_LEFT) != 0) {
		pl.posX--;
	}
	if (GetAsyncKeyState(VK_RIGHT) != 0) {
		pl.posX++;
	}
	if (GetAsyncKeyState(VK_UP) != 0) {
		pl.posY--;
	}
	if (GetAsyncKeyState(VK_DOWN) != 0) {
		pl.posY++;
	}
}
//Hands-On 3 プレイヤーを描画する関数を定義しよう。
void DrawPlayer(Player pl)
{
	kbcDrawMoji(pl.posX, pl.posY, 'P');
}
//実習-3 エネミーを動かす関数を定義しよう。
//		 関数名は自由に決めてください。
//       エネミーはプレイヤーに向かって追いかけてくるように実装してください。
void MoveEnemy(Player pl, Enemy& enemy) 
{
	if (pl.posX < enemy.posX) {
		enemy.posX--;
	}
	if (pl.posX > enemy.posX){
		enemy.posX++;
	}
	if (pl.posY < enemy.posY) {
		enemy.posY--;
	}
	if (pl.posY > enemy.posY) {
		enemy.posY++;
	}
}
//実習-4 エネミーを表示する関数を定義しよう。
//		 関数名は自由に決めてください。

void DrawEnemy(Enemy enemy)
{
	kbcDrawMoji(enemy.posX, enemy.posY, 'E');
}
/*!----------------------------------------------------
*@brief	メイン関数。
----------------------------------------------------*/
int main()
{
	//Hands-On 2 Player構造体の変数playerを追加して初期化しよう。
	//プレイヤー
	Player player;
	player.posX = 0;
	player.posY = 0; 
	player.Hp = 100;

	//実習-2 Enemy構造体の変数enemyを追加して初期化しよう。
	Enemy enemy[4];
	enemy[0].posX = 15;
	enemy[0].posY = 15;

	enemy[1].posX = 10;
	enemy[1].posY = 12;
	
	enemy[2].posX = 5;
	enemy[2].posY = 10;

	enemy[3].posX = 0;
	enemy[3].posY = 8;
	//ここからゲームループ。
	while (true) {
		//1フレームの開始。
		kbcBeginFrame();

		//Hands-On 4 MovePlayer関数とDrawPlayer関数を呼び出すコードを追加しよう。
		MovePlayer(player);
		DrawPlayer(player);

		//実習-5 エネミーを動かす関数と、描画する関数を呼び出すコードを追加しよう。
		for (int i = 0; i < 4; i++) {
			MoveEnemy(player, enemy[i]);
			DrawEnemy(enemy[i]);
		}

		//1フレームの終了。
		kbcEndFrame();
	}

	return 0;
}