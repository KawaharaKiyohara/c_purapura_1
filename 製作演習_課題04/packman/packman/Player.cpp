#include "stdafx.h"
#include "Player.h"
#include "Enemy.h"
#include "Food.h"

SPlayer g_player;

void PlayerUpdate()
{
	//�ړ��O�̍��W��ۑ��B
	int oldPosX = g_player.posX;
	int oldPosY = g_player.posY;
	if (GetAsyncKeyState(VK_LEFT) != 0) {
		//���Ɉړ��B
		g_player.posX--;
	}
	else if (GetAsyncKeyState(VK_RIGHT) != 0) {
		//�E�Ɉړ��B
		g_player.posX++;
	}
	else if (GetAsyncKeyState(VK_UP) != 0) {
		//��Ɉړ��B
		g_player.posY--;
	}
	else if (GetAsyncKeyState(VK_DOWN) != 0) {
		//���Ɉړ��B
		g_player.posY++;
	}
	//�ړ�����`�F�b�N�B
	//�ǔ���
	if (g_map[g_player.posY][g_player.posX] == 1) {
		//�ǂȂ̂ŁA���W��߂��B
		g_player.posX = oldPosX;
		g_player.posY = oldPosY;

	}
	//�G�Ƃ̏Փ˔���B
	for (int no = 0; no < g_enemyNum; no++) {
		if (g_enemyArray[no].posX == g_player.posX
			&& g_enemyArray[no].posY == g_player.posY
			) {
			//�G�ƂԂ������B
			g_player.isDead = 1;	//���S�t���O�𗧂Ă�B
		}
	}
	//�H�ו��Ƃ̏Փ˔���B
	for (int no = 0; no < g_foodNum; no++) {
		if (g_foodArray[no].posX == g_player.posX
			&& g_foodArray[no].posY == g_player.posY
			) {
			//�H�ו��ƂԂ������B
			//�H�ו��̎��S�t���O�𗧂Ă�B
			g_foodArray[no].isDead = 1;

		}
	}
}

void PlayerDraw()
{
	kbcDrawMoji(g_player.posX, g_player.posY, 'P');
}