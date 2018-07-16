#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;

//2�����̃x�N�g���\���́B
struct Vector2 {
	float x;
	float y;
};

	//���B
	struct Sphere {
		Vector2	position;	//���̒��S���W�B
		float radius;		//���̔��a�B
	};

int main()
{
	// �y���z
	//	���̂̔z����L�����N�^�[�ɋ߂����ԂɂȂ�悤�ɕ��ёւ��Ȃ����B
	//
	// �y�v���O�����̐����z
	//  GenerateSpheres�֐��̓����_����100�̋��̂��쐬���āA�����spheres�z��Ɋi�[���܂��B	
	//  characterPosition�̓L�����N�^�[�̍��W��\���B
	//	characterPosition��spheres�Ƃ̋������v�Z���āA���̋������߂����Ԃ�sphere�z����\�[�g���Ȃ����B
	//

	//�����_���ɋ��̂�100�쐬����B
	Sphere spheres[100];
	GenerateSpheres(spheres);
	
	//�L�����N�^�̍��W�B
	Vector2 characerPosition = { 20.0f, 15.0f };

	//��������\�[�g����v���O��������������B
	//�܂��̓L�����Ƃ̋������v�Z����B
	float toCharaLength[100];
	for (int i = 0; i < 100; i++) {
		Vector2 diff;
		diff.x = characerPosition.x - spheres[i].position.x;
		diff.y = characerPosition.y - spheres[i].position.y;
		toCharaLength[i] = sqrt(diff.x * diff.x + diff.y * diff.y);
	}

	//�\�[�g����B
	for (int i = 0; i < 99; i++) {
		for (int j = 99; j > i; j--) {
			if (toCharaLength[j - 1] > toCharaLength[j]) {
				//C++�W���A���S���Y����swap�֐����g�p����B
				swap(toCharaLength[j], toCharaLength[j - 1]);
				swap(spheres[j], spheres[j - 1]);
			}
		}
	}

	//�������킹�B
	SubmissionAnswer(spheres);
	return 0;
}