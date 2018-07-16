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
	//���Ƌ��Ƃ̏Փ˔���B
	//GenerateSpheres�֐��̓����_����100�̋��̂��쐬���āA�����spheres�z��Ɋi�[���܂��B
	//�������ꂽ���̂̂����������A�L�����N�^�[�����鋅�̂�\��characterSphere�ƏՓ˂��Ă��邩�J�E���g���Ȃ����B
	//
	//�����������ł̃q���g�B
	//
	//��̋��́Aa��b���Փ˂���̂́A���L�̏����𖞂����Ƃ��A
	// a��b�̋�����l�Ƃ����Ƃ��A
	// l < a�̔��a�{b�̔��a
	//

	//�����_���ɋ��̂�100�쐬����B
	Sphere spheres[100];
	GenerateSpheres(spheres);
	
	//�L�����N�^�����鋅�̂����B
	Sphere characterSphere;
	characterSphere.position = {20.0f, 15.0f};
	characterSphere.radius = 60.0f;

	int count = 0;

	//�������狅�Ƌ��̏Փ˔������������B
	for (int i = 0; i < 100; i++) {
		Vector2 diff;
		diff.x = characterSphere.position.x - spheres[i].position.x;
		diff.y = characterSphere.position.y - spheres[i].position.y;
		float len = sqrt(diff.x * diff.x + diff.y * diff.y);

		float r = characterSphere.radius + spheres[i].radius;
		if (len < r) {
			//�Փ˂��Ă�ˁB
			count++;
		}
	}

	//�������킹�B
	SubmissionAnswer(count);
	return 0;
}