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

	//�y��������\�[�g����v���O��������������B�z
	


	//�������킹�B
	SubmissionAnswer(spheres);
	return 0;
}