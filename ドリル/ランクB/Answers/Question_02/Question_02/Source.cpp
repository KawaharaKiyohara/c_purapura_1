#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;

//2�����̃x�N�g���\���́B
struct Vector2 {
	float x;
	float y;
};


int main()
{
	//GeneratePosition�֐��̓����_����100�̍��W���쐬���āA�����positions�z��Ɋi�[���܂��B
	//���̔z���x���W�̐��l�̒l�ŏ���(��������)�ɕ��Ԃ悤�Ƀ\�[�g���s���Ȃ����B
	//�\�[�g�A���S���Y���̈�̃o�u���\�[�g�̃A���S���Y���͉��L�̃y�[�W�ŉ������Ă��܂��B
	//https://www.codereading.com/algo_and_ds/algo/bubble_sort.html

	Vector2 positions[100];
	GeneratePositions(positions);
	//����������ёւ���A���S���Y������������B
	for (int i = 0; i < 99; i++) {
		for (int j = 99; j > i; j--) {
			if (positions[j - 1].x > positions[j].x ) {
				Vector2 temp = positions[j - 1];
				positions[j - 1] = positions[j];
				positions[j] = temp;
			}
		}
	}
	//�������킹�B
	SubmissionAnswer(positions);
	return 0;
}