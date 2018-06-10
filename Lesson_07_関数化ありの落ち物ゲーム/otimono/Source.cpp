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

void DrawScore(SPlayer player[2])
{
	char scoreText[256];
	sprintf_s(scoreText, "Player1�@�X�R�A %d", player[0].score);
	kbcDrwaMojiRetu(0, 18, scoreText);
	
	sprintf_s(scoreText, "Player2�@�X�R�A %d", player[1].score);
	kbcDrwaMojiRetu(0, 19, scoreText);
}
//�v���C���[��`��B
void DrawPlayer(SPlayer& player)
{
	kbcDrawMoji(player.posX, player.posY, 'P');
}
//�v���C���[�̈ړ������B
//����1�@player		�v���C���[�̃A�h���X�B�֐������Ńv���C���[�̒l��ύX���āA
//					������Ăяo�����̃v���C���[�ɔ��f���������Ƃ��͎Q�Ƃ�n���B
//����2  playerNo	�v���C���[�̔ԍ��B
void MovePlayer(SPlayer& player, int playerNo) 
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
//�v���C���[�Ɨ������̏Փ˔���
void CheckHitPlayerAndOtimono( SPlayer& player )
{
	for (int i = 0; i < otimonoArray.size(); i++) {
		if (otimonoArray[i].posX == player.posX
			&& otimonoArray[i].posY == player.posY
			) {
			otimonoArray[i].dead = 1;
			//�Q�b�g�o���Ă�����J�E���g�A�b�v�B
			player.score++;
		}
	}
}
//�w�i��`��B
void DrawBackground()
{
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
}
int main()
{
	//�������������B
	srand((unsigned)time(NULL));
	//�v���C���[�B
	SPlayer player[2];
	player[0].posX = 3;
	player[0].posY = 15;
	player[0].score = 0;

	player[1].posX = 12;
	player[1].posY = 15;
	player[1].score = 0;

	//��������Q�[�����[�v�B
	while (true) {
		//1�t���[���̊J�n�B
		kbcBeginFrame();
		//�w�i��`��B
		DrawBackground();
		//�v���C���[�̏����B
		for (int i = 0; i < 2; i++) {
			MovePlayer(player[i], i);
			//�������Ƃ̏Փ˔���B
			CheckHitPlayerAndOtimono(player[i]);
			//�v���C���[�P��`�悷��B
			DrawPlayer(player[i]);
		}
		//�������̕`�揈���B
		DrawOtimono();
		//�������̈ړ������B
		MoveOtimono();
		//�X�R�A��\������B
		DrawScore(player);
		//1�t���[���̏I���B
		kbcEndFrame();
	}

	return 0;
}