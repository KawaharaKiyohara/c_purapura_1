#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore�֐���40�l�̐��т������_���ɐ������āA
	//������Ascore�z��Ɋi�[���܂��B
	//���̔z��ɑ΂��āA���`�T�����s���āA�ō����_���������āAbestScore�ɋL�^���Ȃ����B
	//�����Ă��̌��ʂ�Answer�֐��ɓn���Ȃ����B
	//�����������Ă���΁A�����̃��b�Z�[�W�{�b�N�X���\������܂��B

	int score[40];
	GenerateScore(score);

	//�ō����_����`�T�����g���Č�����B
	int bestScore = 0;
	for (int i = 0; i < 40; i++) {
		if (score[i] > bestScore) {
			bestScore = score[i];
		}
	}
	//�������킹�B
	SubmissionAnswer(bestScore);
	return 0;
}