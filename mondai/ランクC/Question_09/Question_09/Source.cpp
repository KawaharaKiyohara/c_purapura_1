#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore�֐���40�l�̐��т������_���ɐ������āA
	//������Ascore�z��Ɋi�[���܂��B
	//���̔z��ɑ΂��āA���`�T�����s���āA�Œᓾ�_���������āAworstScore�ɋL�^���Ȃ����B
	//�����Ă��̌��ʂ�Answer�֐��ɓn���Ȃ����B
	//�����������Ă���΁A�����̃��b�Z�[�W�{�b�N�X���\������܂��B

	int score[40];
	GenerateScore(score);

	//�Œᓾ�_����`�T�����g���Č�����B
	int worstScore = 100;

	//�������킹�B
	SubmissionAnswer(worstScore);
	return 0;
}