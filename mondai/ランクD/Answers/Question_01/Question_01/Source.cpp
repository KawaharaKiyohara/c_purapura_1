#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore�֐��͕ϐ�a��b�Ƀ����_���Ȑ��l�������܂��B
	//�ϐ�c��a-b�̒l�������Ȃ����B
	int a, b;
	GenerateScore(a, b);
	
	int c = 0;
	c = a - b;

	//�������킹�B
	SubmissionAnswer(c);
	return 0;
}