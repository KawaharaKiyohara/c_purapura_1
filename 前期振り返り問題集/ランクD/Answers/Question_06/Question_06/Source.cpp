#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore�֐���int�^�̔z���a�̊e�v�f�Ƀ����_���Ȓl�������܂��B�B
	//�ϐ�c��a[0]��a[1]��a[2]�����Z�������ʂ������Ȃ����B
	int a[3];
	GenerateScore(a);
	
	int c = a[0] + a[1] + a[2];

	//�������킹�B
	SubmissionAnswer(c);
	return 0;
}