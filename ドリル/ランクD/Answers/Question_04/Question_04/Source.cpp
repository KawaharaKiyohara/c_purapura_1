#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore�֐��͕ϐ�a��b�Ƀ����_���Ȑ��l�������܂��B
	//a��b�̔�r���s���āA�ϐ�c�ɏ������ق��̒l�������Ȃ����B
	int a, b;
	GenerateScore(a, b);
	
	int c = 0;
	//�������ق��̒l��������B
	if (a < b) {
		c = a;
	}
	else {
		c = b;
	}

	//�������킹�B
	SubmissionAnswer(c);
	return 0;
}