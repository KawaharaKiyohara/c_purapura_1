#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore�֐���40�l�̐��т������_���ɐ������āA
	//������Ascore�z��Ɋi�[���܂��B
	//���̔z��𒲂ׂĕ��ϓ_�ȉ�(���ϓ_���܂�)���Ƃ������k�̐���count�ϐ��ɋL�^���Ȃ����B
	//�����Ă��̌��ʂ�Answer�֐��ɓn���Ȃ����B
	//�����������Ă���΁A�����̃��b�Z�[�W�{�b�N�X���\������܂��B

	int score[40];
	GenerateScore(score);

	int count = 0;
	//�܂��͕��ϓ_���v�Z����B
	int avg = 0;
	for (int i = 0; i < 40; i++) {
		avg += score[i];
	}
	avg /= 40;
	//���ϓ_�ȉ��̐��k�̐��𐔂���B
	for (int i = 0; i < 40; i++) {
		if (score[i] <= avg) {
			count++;
		}
	}
	//�������킹�B
	SubmissionAnswer(count);
	return 0;
}