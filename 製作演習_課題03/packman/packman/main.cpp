//cpp�t�@�C����#include stdafx.h��K���\�[�X�̐擪�ɏ����ĂˁI�I�I
#include "stdafx.h"	�@
#include "Background.h"
#include "Enemy.h"
#include "Food.h"

/////////////////////////////////////////////////////
// �O���[�o���ϐ�
/////////////////////////////////////////////////////
//�}�b�v��`�B
int g_map[16][16] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },	//  0���
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  1���
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  2���
	{ 1, 0, 1, 1, 2, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1 },	//  3���
	{ 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  4���
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1 },	//  5���
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },	//  6���
	{ 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 2, 0, 1 },	//  7���
	{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1 },	//  8���
	{ 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1 },	//  9���
	{ 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },	// 10���
	{ 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 11���
	{ 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },	// 12���
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 13���
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1 },	// 14���
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },	// 15���

};

//�p�X�t�@�C�f�B���O�B
CPathFinding g_pathFinding;

//�v���C���[�֌W�̃O���[�o���ϐ��B
int playerIsDead = 0;	//�v���C���[�̎��S�t���O�B1�ɂȂ����玀�S�B
int playerPosX = 7;
int playerPosY = 7;

//�G�̐��B
int g_enemyNum = 0;

//�H�ו��̐��B
int g_foodNum = 0;

/////////////////////////////////////////////////////
// �֐�
/////////////////////////////////////////////////////
/*!----------------------------------------------------
*@brief	�Q�[���̏������B
----------------------------------------------------*/
void GameInitialize()
{
	//g_map�����ƂɁA�G�l�~�[�ƐH�ו������������Ă����B
	for ( int x = 0; x < 16; x++ ) {
		for ( int y = 0; y < 16; y++ ) {
			if ( g_map[y][x] == 2 ) {
				//�G����B
				EnemyInitialyze( g_enemyNum, x, y );
				g_enemyNum++; //�G�̐����C���N�������g�B
			}
			else if ( g_map[y][x] == 0 ) {
				//�H�ו�����B
				FoodInitialyze( g_foodNum, x, y );
				g_foodNum++;
			}
		}
	}

	//�p�X�t�@�C���f�B���O���������B
	g_pathFinding.BuildNodes();
}
/*!----------------------------------------------------
*@brief	���C���֐��B
----------------------------------------------------*/
int main()
{
	//�Q�[�����������B
	GameInitialize();

	int gameClear = 0;	//�Q�[���N���A�t���O�B
	//��������Q�[�����[�v�B
	while (true) {
		//1�t���[���̊J�n�B
		kbcBeginFrame();
		// �������� ///////////////////////////////////////////////////////////
		if (gameClear == 1) { //�Q�[���N���A�H�B
			kbcDrawMojiRetu(0, 0, "���[�ނ��肠");
		}else if(playerIsDead == 0){	//�v���C���[�����S���Ă��Ȃ��Ƃ��̏����B
			//�G�̍X�V�B
			for (int no = 0; no < g_enemyNum; no++) {
				EnemyUpdate(no);
			}
			//�H�ו��̍X�V�B
			for (int no = 0; no < g_foodNum; no++) {
				FoodUpdate(no);
			}
			////////////////////////////////////////////////////////
			// �v���C���[�̍X�V�����B
			////////////////////////////////////////////////////////
			{
				//�ړ��O�̍��W��ۑ��B
				int oldPosX = playerPosX;
				int oldPosY = playerPosY;
				if (GetAsyncKeyState(VK_LEFT) != 0) {
					//���Ɉړ��B
					playerPosX--;
				}
				else if (GetAsyncKeyState(VK_RIGHT) != 0) {
					//�E�Ɉړ��B
					playerPosX++;
				}
				else if (GetAsyncKeyState(VK_UP) != 0) {
					//��Ɉړ��B
					playerPosY--;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0) {
					//���Ɉړ��B
					playerPosY++;
				}
				//�ړ�����`�F�b�N�B
				//�ǔ���
				if (g_map[playerPosY][playerPosX] == 1) {
					//�ǂȂ̂ŁA���W��߂��B
					playerPosX = oldPosX;
					playerPosY = oldPosY;
					
				}
				//�G�Ƃ̏Փ˔���B
				for (int no = 0; no < g_enemyNum; no++) {
					if (g_enemyArray[no].posX == playerPosX
						&& g_enemyArray[no].posY == playerPosY
						) {
						//�G�ƂԂ������B
						playerIsDead = 1;	//���S�t���O�𗧂Ă�B
					}
				}
				//�H�ו��Ƃ̏Փ˔���B
				for (int no = 0; no < g_foodNum; no++) {
					if (g_foodArray[no].posX == playerPosX
						&& g_foodArray[no].posY == playerPosY
						) {
						//�H�ו��ƂԂ������B
						//�H�ו��̎��S�t���O�𗧂Ă�B
						g_foodArray[no].isDead = 1;
						
					}
				}
			}
			//�w�i��`��B
			DrawBackground();

			//�H�ו��̕`��B
			for (int no = 0; no < g_foodNum; no++) {
				FoodDraw(no);
			}

			//�G�̕`�揈���B
			for (int no = 0; no < g_enemyNum; no++) {
				EnemyDraw(no);
			}
			////////////////////////////////////////////////////////
			// �v���C���[�̕`�揈���B
			////////////////////////////////////////////////////////
			kbcDrawMoji(playerPosX, playerPosY, 'P');
		}
		else {
			//�v���C���[�����S���Ă���Ƃ��̏����B
			kbcDrawMojiRetu(0, 0, "���[�ނ��[�΁[");
		}
		// �����܂ł̊ԂɃQ�[���̃v���O�����������Ă����Ă�//////////////////////
		
		//1�t���[���̏I���B
		kbcEndFrame();
	}

	return 0;
}