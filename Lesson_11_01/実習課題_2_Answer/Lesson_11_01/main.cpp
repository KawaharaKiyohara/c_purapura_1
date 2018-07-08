//cpp�t�@�C����#include stdafx.h��K���\�[�X�̐擪�ɏ����ĂˁI�I�I
#include "stdafx.h"	�@
#include <iostream>

/////////////////////////////////////////////////////
// �\����
/////////////////////////////////////////////////////

//Hands-On 1 Player�\���̂��쐬���悤�B
struct Player {
	int posX;
	int posY;
	int Hp;
};
//���K�P Enemy�\���̂��쐬���悤�B
//       Enemy�\���̂̓����o�ϐ��ɁAint�^��posX��posY��ێ����Ă��邾���̍\���̂ł��B
struct Enemy {
	int posX;
	int posY;
};
/////////////////////////////////////////////////////
// �֐�
/////////////////////////////////////////////////////
//Hands-On 2 �v���C���[�𓮂����֐����`���悤�B
//�L�[���͂Ńv���C���[�𓮂����B
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
//Hands-On 3 �v���C���[��`�悷��֐����`���悤�B
void DrawPlayer(Player pl)
{
	kbcDrawMoji(pl.posX, pl.posY, 'P');
}
//���K-3 �G�l�~�[�𓮂����֐����`���悤�B
//		 �֐����͎��R�Ɍ��߂Ă��������B
//       �G�l�~�[�̓v���C���[�Ɍ������Ēǂ������Ă���悤�Ɏ������Ă��������B
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
//���K-4 �G�l�~�[��\������֐����`���悤�B
//		 �֐����͎��R�Ɍ��߂Ă��������B

void DrawEnemy(Enemy enemy)
{
	kbcDrawMoji(enemy.posX, enemy.posY, 'E');
}
/*!----------------------------------------------------
*@brief	���C���֐��B
----------------------------------------------------*/
int main()
{
	//Hands-On 2 Player�\���̂̕ϐ�player��ǉ����ď��������悤�B
	//�v���C���[
	Player player;
	player.posX = 0;
	player.posY = 0; 
	player.Hp = 100;

	//���K-2 Enemy�\���̂̕ϐ�enemy��ǉ����ď��������悤�B
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

		//Hands-On 4 MovePlayer�֐���DrawPlayer�֐����Ăяo���R�[�h��ǉ����悤�B
		MovePlayer(player);
		DrawPlayer(player);

		//���K-5 �G�l�~�[�𓮂����֐��ƁA�`�悷��֐����Ăяo���R�[�h��ǉ����悤�B
		for (int i = 0; i < 4; i++) {
			MoveEnemy(player, enemy[i]);
			DrawEnemy(enemy[i]);
		}

		//1�t���[���̏I���B
		kbcEndFrame();
	}

	return 0;
}