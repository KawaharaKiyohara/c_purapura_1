#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;



int main()
{
	//GenerateInteger�֐��̓����_����1000000�̐����l���쐬���āA�����value�z��Ɋi�[���܂��B
	//���̔z���l�ŏ���(��������)�ɕ��Ԃ悤�Ƀ\�[�g���s���Ȃ����B
	//���̔z��̃\�[�g�Ƀo�u���\�[�g���g�p����ƁA�v�Z��1000000 * 500000 = 5000����ƂȂ��Ă��܂��A
	//���낵�����Ԃ��������Ă��܂��܂��B
	//�����ȃ\�[�g�A���S���Y���̂P�ɃN�C�b�N�\�[�g�Ƃ������̂�����܂��B
	//�N�C�b�N�\�[�g�̃A���S���Y���͉��L�̃y�[�W�ŉ������Ă��܂��B
	//https://www.codereading.com/algo_and_ds/algo/quick_sort.html

	static int values[1000000];
	GenerateInteger(values);

	//����������ёւ���A���S���Y������������B
	
	//�������킹�B
	SubmissionAnswer(values);
	return 0;
}