#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore�֐���40�l�̐��т������_���ɐ������āA
	//������Ascore�z��Ɋi�[���܂��B
	//���̔z��𒲂ׂ�50�_��荂���_(50�_�͊܂܂Ȃ�)���Ƃ������k�̐���count�ϐ��ɋL�^���Ȃ����B
	//�����Ă��̌��ʂ�Answer�֐��ɓn���Ȃ����B
	//�����������Ă���΁A�����̃��b�Z�[�W�{�b�N�X���\������܂��B
	//�Ȃ��A�����_�͐؂�̂ĂɂȂ�܂��B
	int score[40];
	GenerateScore(score);

	int count = 0;
	for (int i = 0; i < 40; i++) {
		if (score[i] > 50) {
			count++;
		}
	}
	//�������킹�B
	SubmissionAnswer(count);
	return 0;
}