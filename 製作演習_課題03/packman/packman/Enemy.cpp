#include "stdafx.h"
#include "Enemy.h"


SEnemy g_enemyArray[MAX_ENEMY];	//�G�l�~�[�̔z��B

void EnemyInitialyze(int enemyNo, int posX, int posY)
{
	g_enemyArray[enemyNo].initPosX = posX;
	g_enemyArray[enemyNo].initPosY = posY;
	g_enemyArray[enemyNo].posX = posX;
	g_enemyArray[enemyNo].posY = posY;
}
void EnemyUpdate(int enemyNo)
{
	//�X�e�[�g�ɂ���ď����𕪊�B
	//���̂悤�ȏ�����L����ԋ@�B�ƌĂԁB
	//�G�ł��v���C���[�ł��Q�[���̐i�s�Ȃǂł��ǂ��g���p�^�[���ł��B
	//��������g����悤�ɂȂ낤�B
	if (g_enemyArray[enemyNo].state == EnemyState_Haikai) {
		//�p�j�B
		//�v���C���[�Ƃ̋��������l�ȉ��ɂȂ�����A�ǐՏ�ԂɂȂ邼���B
		if (fabsf(playerPosX - g_enemyArray[enemyNo].posX) < 3
			&& fabsf(playerPosY - g_enemyArray[enemyNo].posY) < 3
			) {
			//�v���C���[�Ƃ̋��������l�ȉ��ɂȂ����̂ŁA
			//�ǐՃX�e�[�g�ɑJ�ځB
			g_enemyArray[enemyNo].state = EnemyState_Tuiseki;
		}
	}
	else if (g_enemyArray[enemyNo].state == EnemyState_Tuiseki) {
		//�ǐՁB
		g_enemyArray[enemyNo].waitCount--;
		if (g_enemyArray[enemyNo].waitCount == 0) { //�E�F�C�g��0�ɂȂ�����ړ�����B
			//�v���C���[�̈ʒu�ڎw���āA�p�X�����B
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
			//�v���C���[�Ƃ̋��������l�ȉ��ɂȂ����̂ŁA
			//�A�҃X�e�[�g�ɑJ�ځB
			g_enemyArray[enemyNo].state = EnemyState_Return;
		}
	}
	else if (g_enemyArray[enemyNo].state == EnemyState_Return) {
		//�����ʒu�ɋA�ҁB
		//�����ʒu��ڎw���āA�p�X�����B
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
				//�A�҂����B
				g_enemyArray[enemyNo].state = EnemyState_Haikai;
			}
		}
	}
	
}
void EnemyDraw(int enemyNo)
{
	if (g_enemyArray[enemyNo].state == EnemyState_Tuiseki) {
		//�ǐՒ��B
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