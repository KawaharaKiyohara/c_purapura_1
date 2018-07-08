//cppファイルは#include stdafx.hを必ずソースの先頭に書いてね！！！
#include "stdafx.h"	　
#include <iostream>

/////////////////////////////////////////////////////
// 構造体
/////////////////////////////////////////////////////

//プレイヤークラス。
class Player {
public:
	//ここからメンバ変数。
	int posX;	//X座標。
	int posY;	//Y座標。
	int Hp;		//ヒットポイント(今回は使ってない。)
	//ここからメンバ関数。
	//移動関数。
	void Move();
	//描画関数。
	void Draw();
};

//エネミークラス。
class Enemy {
public:
	//ここからメンバ変数。
	int posX;
	int posY;
	//ここからメンバ関数。
	//移動関数。
	void Move(Player player);
	//描画関数。
	void Draw();
};
/////////////////////////////////////////////////////
// 関数定義
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//Player::Move関数の定義。
/////////////////////////////////////////////////////
void Player::Move()
{
	if (GetAsyncKeyState(VK_LEFT) != 0) {
		posX--;
	}
	if (GetAsyncKeyState(VK_RIGHT) != 0) {
		posX++;
	}
	if (GetAsyncKeyState(VK_UP) != 0) {
		posY--;
	}
	if (GetAsyncKeyState(VK_DOWN) != 0) {
		posY++;
	}
}

/////////////////////////////////////////////////////
//Player::Draw関数の定義。
/////////////////////////////////////////////////////
void Player::Draw()
{
	kbcDrawMoji(posX, posY, 'P');
}

/////////////////////////////////////////////////////
//Enemy::Move関数の定義。
/////////////////////////////////////////////////////
void Enemy::Move(Player pl) 
{
	if (pl.posX < posX) {
		posX--;
	}
	if (pl.posX > posX){
		posX++;
	}
	if (pl.posY < posY) {
		posY--;
	}
	if (pl.posY > posY) {
		posY++;
	}
}
/////////////////////////////////////////////////////
//Enemy::Draw関数の定義。
/////////////////////////////////////////////////////
void Enemy::Draw()
{
	kbcDrawMoji( posX,  posY, 'E' );
}
/*!----------------------------------------------------
*@brief	メイン関数。
----------------------------------------------------*/
int main()
{
	//プレイヤー
	Player player;
	player.posX = 0;
	player.posY = 0; 
	player.Hp = 100;

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

		//プレイヤーのMove関数とDraw関数を呼び出す。
		player.Move();
		player.Draw();
	

		//エネミーのMove関数とDraw関数を呼び出す。
		for (int i = 0; i < 4; i++) {
			enemy[i].Move(player);
			enemy[i].Draw();
		}

		//1フレームの終了。
		kbcEndFrame();
	}

	return 0;
}