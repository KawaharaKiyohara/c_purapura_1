#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore�֐���40�l�̐��т������_���ɐ������āA�����
	//score�z��Ɋi�[���܂��B
	//���̔z��𗘗p���ẴN���X�̍��v�_���v�Z���āAsum�ɑ�����Ȃ����B
	//�����Ă��̌��ʂ�Answer�֐��ɓn���Ȃ����B
	//�����������Ă���΁A�����̃��b�Z�[�W�{�b�N�X���\������܂��B
	//�Ȃ��A�����_�͐؂�̂ĂɂȂ�܂��B
	int score[40];
	GenerateScore(score);
	
	int sum = 0;
	for (int i = 0; i < 40; i++) {
		sum += score[i];
	}
	//�������킹�B
	SubmissionAnswer(sum);
	return 0;
}