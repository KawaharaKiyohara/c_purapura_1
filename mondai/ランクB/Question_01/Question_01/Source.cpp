#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;



int main()
{
	//GenerateInteger�֐��̓����_����100�̐����l���쐬���āA�����value�z��Ɋi�[���܂��B
	//���̔z���l�ŏ���(��������)�ɕ��Ԃ悤�Ƀ\�[�g���s���Ȃ����B
	//�\�[�g�A���S���Y���̈�̃o�u���\�[�g�̃A���S���Y���͉��L�̃y�[�W�ŉ������Ă��܂��B
	//https://www.codereading.com/algo_and_ds/algo/bubble_sort.html

	int values[100];
	GenerateInteger(values);

	//����������ёւ���A���S���Y������������B



	//�������킹�B
	SubmissionAnswer(values);
	return 0;
}