#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore�֐���int�^�̔z���a�̊e�v�f�Ƀ����_���Ȓl�������܂��B
	//a[0]��a[1]��a[2]�̕��ϒl���v�Z���āA�ϐ�avg�ɑ�����Ȃ����B
	//�����_�͐؂�̂Ăō\���܂���B

	int a[3];
	GenerateScore(a);
	
	int avg = 0;

	//�������킹�B
	SubmissionAnswer(avg);
	return 0;
}