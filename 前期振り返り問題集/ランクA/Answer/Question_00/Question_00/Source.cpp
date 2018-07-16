#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;


void QuickSort(int value[], int left, int right) 
{
	//
	int pivot, l_hold, r_hold;
	l_hold = left;
	r_hold = right;
	pivot = value[left];	//��l�����߂�B
	while (left < right) {
		//�z��̉E���璲�ׂĂ����āA��l��菬�������̂�������܂�
		//rigth���f�N�������g���Ă����B
		while (value[right] >= pivot && (left < right)){
			right--;
		}
		if (left != right) {
			//��l�����������̂ŁA���[�Ɋ񂹂�B
			value[left] = value[right];
			left++;
		}
		//�����Ĕz��������璲�ׂĂ����āA��l���傫�����̂�������܂�
		//left���C���N�������g���Ă����B
		while ((value[left] <= pivot) && (left < right)) {
			left++;
		}
		if (left != right)
		{
			//��l�����傫���̂ŁA�E�΂Ɋ񂹂�B
			value[right] = value[left];
			right--;
		}
	}
	value[left] = pivot;
	//��������z��𕪉����āA�ׂ����\�[�g���Ă����B
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) {
		QuickSort(value, left, pivot - 1);
	}
	if (right > pivot) {
		QuickSort(value, pivot + 1, right);
	}
}

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
	QuickSort(values, 0, 1000000);

	//�������킹�B
	SubmissionAnswer(values);
	return 0;
}