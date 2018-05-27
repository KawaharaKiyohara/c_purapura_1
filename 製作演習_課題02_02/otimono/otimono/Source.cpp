#include <iostream>
#include "consoleLib.h"
#include "otimono.h"
#include <time.h>
#include <stdlib.h>


int main()
{
	//�������������B
	srand((unsigned)time(NULL));

	//�Q�����z��B���ȏ���p.256����z��Ɋւ���L�q������܂��B�������z���p.269
	int map[16][16] = {
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  0���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  1���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  2���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  3���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  4���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  5���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  6���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  7���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  8���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  9���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 10���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 11���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 12���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 13���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 14���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 15���
		
	};

	////�v���C���[�̍��W�B�R�����g�A�E�g���č폜
	int playerPosX = 8;
	int playerPosY = 15;

	int getCount = 0;
	//��������Q�[�����[�v�B
	while (true) {
		//1�t���[���̊J�n�B
		kbcBeginFrame();
		// �������� ///////////////////////////////////////////////////////////
		{
			//�w�i��`��B
			//�񎟌��z���map���Q�Ƃ��āA�w�i��`�悵�Ă����B
			for (int y = 0; y < 16; y++) {
				for (int x = 0; x < 16; x++) {
					if (map[y][x] == 0) {
						//2�����z���map[y][x]��0�������Ă�����A
						//���Wx, y�̏ꏊ�ɋ󔒕�����`�悷��B
						kbcDrawMoji(x, y, ' ');
					}
					else if (map[y][x] == 1) {
						//2�����z���map[y][x]��1�������Ă�����A
						//���Wx, y�̏ꏊ��@��`�悷��B
						kbcDrawMoji(x, y, '@');
					}
				}
			}

			if (GetAsyncKeyState(VK_LEFT) != 0) {
				//���̃L�[�������ꂽ�Ƃ��̏����������ɋL�q����B
				playerPosX--;
			}
			if (GetAsyncKeyState(VK_RIGHT) != 0) {
				playerPosX++;
			}
			
			//player�̏Փ˔���B
			if (playerPosX < 1) {
				playerPosX = 1;
			}
			if (playerPosX > 14) {
				playerPosX = 14;
			}
			//�������Ƃ̏Փ˔���B
			for (int i = 0; i < otimonoArray.size(); i++) {
				if ( otimonoArray[i].posX == playerPosX
					&& otimonoArray[i].posY == playerPosY
				) {
					otimonoArray[i].dead = 1;
					getCount++;
				}
			}
			//�v���C���[��`�悷��B
			kbcDrawMoji(playerPosX, playerPosY, 'P');

			//�������̃v���O���������s�B
			OtimonoProgram();

			//�X�R�A��\������B
			//������͋��ȏ���p.284�ɋL�ڂ�����܂��B
			//sprintf_s�̓}�C�N���\�t�g���Ǝ��ɗp�ӂ������̂ŁA
			//C����̕W���֐���sprintf���Z�L���A(���S)�ɂ������̂ł��B
			//sprintf�̋����ɂ��Ă̓O�O��܂��傤�B
			char scoreText[256];
			sprintf_s(scoreText, "�X�R�A %d", getCount);
			kbcDrwaMojiRetu(0, 18, scoreText);

			
		}
		// �����܂ł̊ԂɃQ�[���̃v���O�����������Ă����Ă�//////////////////////
		
		//1�t���[���̏I���B
		kbcEndFrame();
	}

	return 0;
}