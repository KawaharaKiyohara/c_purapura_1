#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore�֐���40�l�̐��т������_���ɐ������āA�����
	//score�z��Ɋi�[���܂��B
	//���̔z��𗘗p���Ă̕��ϓ_���v�Z���āAavg�ɑ�����Ȃ����B
	//�����Ă��̌��ʂ�Answer�֐��ɓn���Ȃ����B
	//�����������Ă���΁A�����̃��b�Z�[�W�{�b�N�X���\������܂��B
	//�Ȃ��A�����_�͐؂�̂ĂɂȂ�܂��B
	int score[40];
	GenerateScore(score);

	int avg = 0;
	for (int i = 0; i < 40; i++) {
		avg += score[i];
	}
	avg /= 40;
	//�������킹�B
	SubmissionAnswer(avg);
	return 0;
}