#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore�֐���40�l�̐��т������_���ɐ������āA
	//������Ascore�z��Ɋi�[���܂��B
	//���̔z��𒲂ׂ�50�_�ȏ�̓_(50�_���܂�)���Ƃ������k�̐���count�ϐ��ɋL�^���Ȃ����B
	//�����Ă��̌��ʂ�Answer�֐��ɓn���Ȃ����B
	//�����������Ă���΁A�����̃��b�Z�[�W�{�b�N�X���\������܂��B

	int score[40];
	GenerateScore(score);

	int count = 0;

	//�������킹�B
	SubmissionAnswer(count);
	return 0;
}