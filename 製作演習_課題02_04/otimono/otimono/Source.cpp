#include <iostream>
#include "consoleLib.h"
#include "otimono.h"
#include <time.h>
#include <stdlib.h>

//�v���C���[�̍\����
struct SPlayer {
	int posX;
	int posY;
	int score;
};

//�v���C���[�̈ړ������B
//����1�@player		�v���C���[�̃A�h���X�B�֐������Ńv���C���[�̒l��ύX���āA
//					������Ăяo�����̃v���C���[�ɔ��f���������Ƃ��͎Q�Ƃ�n���B
//����2  playerNo	�v���C���[�̔ԍ��B
void PlayerMove(SPlayer& player, int playerNo) 
{
	if (playerNo == 0) {
		//1�v���C���[�B
		//�v���C���[�P�̈ړ������B
		if (GetAsyncKeyState(VK_LEFT) != 0) {
			//���̃L�[�������ꂽ�Ƃ��̏����������ɋL�q����B
			player.posX--;
		}
		if (GetAsyncKeyState(VK_RIGHT) != 0) {
			player.posX++;
		}
	}
	else if (playerNo == 1) {
		//2�v���C���[�B
		//�����ăv���C���[�Q�̈ړ������B
		if (GetAsyncKeyState('A') != 0) {
			//���̃L�[�������ꂽ�Ƃ��̏����������ɋL�q����B
			player.posX--;
		}
		if (GetAsyncKeyState('D') != 0) {
			player.posX++;
		}
	}
	//�ǔ���B
	if (player.posX < 1) {
		player.posX = 1;
	}
	if (player.posX > 14) {
		player.posX = 14;
	}

}
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

	//�v���C���[�P�B
	SPlayer player;
	player.posX = 3;
	player.posY = 15;
	player.score = 0;
	//�v���C���[�Q�B
	SPlayer player2;
	player2.posX = 12;
	player2.posY = 15;
	player2.score = 0;
	
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

			//�v���C���[�P�̈ړ������B
			PlayerMove(player, 0);
			
			//�������Ƃ̏Փ˔���B
			for (int i = 0; i < otimonoArray.size(); i++) {
				if ( otimonoArray[i].posX == player.posX
					&& otimonoArray[i].posY == player.posY
				) {
					otimonoArray[i].dead = 1;
					player.score++;
				}
			}
			//�v���C���[��`�悷��B
			kbcDrawMoji(player.posX, player.posY, 'P');

			//�����ăv���C���[�Q�̈ړ������B
			PlayerMove(player2, 1);
			
			//�������Ƃ̏Փ˔���B
			for (int i = 0; i < otimonoArray.size(); i++) {
				if (otimonoArray[i].posX == player2.posX
					&& otimonoArray[i].posY == player2.posY
					) {
					otimonoArray[i].dead = 1;
					player2.score++;
				}
			}
			//�v���C���[��`�悷��B
			kbcDrawMoji(player2.posX, player2.posY, 'L');

			//�������̃v���O���������s�B
			OtimonoProgram();

			//�X�R�A��\������B
			//������͋��ȏ���p.284�ɋL�ڂ�����܂��B
			//sprintf_s�̓}�C�N���\�t�g���Ǝ��ɗp�ӂ������̂ŁA
			//C����̕W���֐���sprintf���Z�L���A(���S)�ɂ������̂ł��B
			//sprintf�̋����ɂ��Ă̓O�O��܂��傤�B
			char scoreText[256];
			sprintf_s(scoreText, "Player1�@�X�R�A %d", player.score);
			kbcDrwaMojiRetu(0, 18, scoreText);

			sprintf_s(scoreText, "Player2�@�X�R�A %d", player2.score);
			kbcDrwaMojiRetu(0, 19, scoreText);

			
		}
		// �����܂ł̊ԂɃQ�[���̃v���O�����������Ă����Ă�//////////////////////
		
		//1�t���[���̏I���B
		kbcEndFrame();
	}

	return 0;
}