#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore�֐���int�^�̔z���a�̊e�v�f�Ƀ����_���Ȓl�������܂��B
	//a[0]�`a[2]�𒲂ׂāA��ԏ����Ȑ��l��ϐ�m�ɑ�����Ȃ����B
	int a[3];
	GenerateScore(a);
	
	int m = 0;
	//a[0]��a[1]�̔�r���s���B
	if (a[0] < a[1]) {
		//a[0]�̂ق����������B
		m = a[0];
	}
	else {
		m = a[1];
	}
	//a[0]��a[1]�̔�r���s��������(m)��a[2]�̔�r���s���B
	if (m > a[2]) {
		//a[2]�̂ق����������B
		m = a[2];
	}

	//�������킹�B
	SubmissionAnswer(m);
	return 0;
}