#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();
	void Move();
	void Draw();
	
	int posX;		//エネミーのX座標。
	int posY;		//エネミーのY座標。
	int moveDir;	//エネミーの移動方向。
};

