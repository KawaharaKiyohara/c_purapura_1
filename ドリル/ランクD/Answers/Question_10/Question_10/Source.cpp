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

	int tmp = a[0]; //a[0]�̒l���o�b�N�A�b�v����B
	a[0] = a[1];    //a[0]��a[1]�̒l��������B
	a[1] = tmp;     //a[1]�Ƀo�b�N�A�b�v������Ă���a[0]�̒l��������B

	//�������킹�B
	SubmissionAnswer(a);
	return 0;
}