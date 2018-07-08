//cpp�t�@�C����#include stdafx.h��K���\�[�X�̐擪�ɏ����ĂˁI�I�I
#include "stdafx.h"	�@
#include <iostream>

/////////////////////////////////////////////////////
// �\����
/////////////////////////////////////////////////////

//�v���C���[�N���X�B
class Player {
public:
	//�������烁���o�ϐ��B
	int posX;	//X���W�B
	int posY;	//Y���W�B
	int Hp;		//�q�b�g�|�C���g(����͎g���ĂȂ��B)
	//�������烁���o�֐��B
	//�ړ��֐��B
	void Move();
	//�`��֐��B
	void Draw();
};

//�G�l�~�[�N���X�B
class Enemy {
public:
	//�������烁���o�ϐ��B
	int posX;
	int posY;
	//�������烁���o�֐��B
	//�ړ��֐��B
	void Move(Player player);
	//�`��֐��B
	void Draw();
};
/////////////////////////////////////////////////////
// �֐���`
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//Player::Move�֐��̒�`�B
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
//Player::Draw�֐��̒�`�B
/////////////////////////////////////////////////////
void Player::Draw()
{
	kbcDrawMoji(posX, posY, 'P');
}

/////////////////////////////////////////////////////
//Enemy::Move�֐��̒�`�B
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
//Enemy::Draw�֐��̒�`�B
/////////////////////////////////////////////////////
void Enemy::Draw()
{
	kbcDrawMoji( posX,  posY, 'E' );
}
/*!----------------------------------------------------
*@brief	���C���֐��B
----------------------------------------------------*/
int main()
{
	//�v���C���[
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
	//��������Q�[�����[�v�B
	while (true) {
		//1�t���[���̊J�n�B
		kbcBeginFrame();

		//�v���C���[��Move�֐���Draw�֐����Ăяo���B
		player.Move();
		player.Draw();
	

		//�G�l�~�[��Move�֐���Draw�֐����Ăяo���B
		for (int i = 0; i < 4; i++) {
			enemy[i].Move(player);
			enemy[i].Draw();
		}

		//1�t���[���̏I���B
		kbcEndFrame();
	}

	return 0;
}