#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore�֐���int�^�̔z���a�̊e�v�f�Ƀ����_���Ȓl�������܂��B
	//GenerateScore�֐��̌Ăяo���̌�ŁA�����̃A���S���Y�����g���āAa[0]��a[1]�̒l��
	//�������Ȃ����B
	int a[2];
	GenerateScore(a);
	//������������̃A���S���Y���������āAa[0]��a[1]�����ւ���B
	//���L�͌����̃A���S���Y���̉������B�����o��̂Œ��ӁB
	//https://www.youtube.com/watch?v=Y-nZ8dYaY-A&feature=youtu.be


	//�������킹�B
	SubmissionAnswer(a);
	return 0;
}