#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();
	void Move();
	void Draw();
	
	int posX;		//�G�l�~�[��X���W�B
	int posY;		//�G�l�~�[��Y���W�B
	int moveDir;	//�G�l�~�[�̈ړ������B
};

