#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"

CEnemy g_enemyArray[MAX_ENEMY];	//�G�l�~�[�̔z��B

void CEnemy::Initialyze( int x, int y)
{
	initPosX = x;
	initPosY = y;
	posX = x;
	posY = y;
}
void CEnemy::Update()
{
	//�X�e�[�g�ɂ���ď����𕪊�B
	//���̂悤�ȏ�����L����ԋ@�B�ƌĂԁB
	//�G�ł��v���C���[�ł��Q�[���̐i�s�Ȃǂł��ǂ��g���p�^�[���ł��B
	//��������g����悤�ɂȂ낤�B
	if (state == EnemyState_Haikai) {
		//�p�j�B
		//�v���C���[�Ƃ̋��������l�ȉ��ɂȂ�����A�ǐՏ�ԂɂȂ邼���B
		if (fabsf(g_player.posX - posX) < 3
			&& fabsf(g_player.posY - posY) < 3
			) {
			//�v���C���[�Ƃ̋��������l�ȉ��ɂȂ����̂ŁA
			//�ǐՃX�e�[�g�ɑJ�ځB
			state = EnemyState_Tuiseki;
		}
	}
	else if (state == EnemyState_Tuiseki) {
		//�ǐՁB
		waitCount--;
		if( waitCount == 0) { //�E�F�C�g��0�ɂȂ�����ړ�����B
			//�v���C���[�̈ʒu�ڎw���āA�p�X�����B
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
			//�v���C���[�Ƃ̋��������l�ȉ��ɂȂ����̂ŁA
			//�A�҃X�e�[�g�ɑJ�ځB
			state = EnemyState_Return;
		}
	}
	else if (state == EnemyState_Return) {
		//�����ʒu�ɋA�ҁB
		//�����ʒu��ڎw���āA�p�X�����B
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
				//�A�҂����B
				state = EnemyState_Haikai;
			}
		}
	}
	
}
void CEnemy::Draw()
{
	if (state == EnemyState_Tuiseki) {
		//�ǐՒ��B
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