#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;

//2�����̃x�N�g���\���́B
struct Vector2 {
	float x;
	float y;
};

//�����s�o�E���f�B���O�{�b�N�X�B
struct AABB {
	Vector2	vMax;	//���̍ő�x���W�ƁA�ő�y���W�B
	Vector2	vMin;	//���̍ŏ�x���W�ƁA�ő�y���W�B
};

int main()
{
	//�_��AABB(�����s�o�E���f�B���O�{�b�N�X)�Ƃ̏Փ˔���B
	//GeneratePosition�֐��̓����_����100�̍��W���쐬���āA�����positions�z��Ɋi�[���܂��B
	//�������ꂽ���W�̂����������A�L�����N�^�[��AABB��\��characterAabb�ƏՓ˂��Ă��邩�J�E���g���Ȃ����B
	//AABB�̏ڂ��������͉��L��URL���Q�ƁB
	//https://qiita.com/HIEMON/items/a392c34b602eb653c337
	//http://d.hatena.ne.jp/taiyakisun/20120205/1328410006
	//
	//�����������ł̃q���g�B
	//�����Ȃ�Ȃ��p�ꂪ�����ē�������邩������܂��񂪁A
	//���͂ƂĂ��ȒP�ł��B��̃y�[�W�̐����ɘf�킳�ꂸ�ɓ���l�������Ȃ��I
	//�f�킳�ꂽ�l��Answer�����Ă݂�̂����������B
	//

	//�����_���ɍ��W��100�쐬����B
	Vector2 positions[100];
	GeneratePositions(positions);

	AABB characterAabb;
	characterAabb.vMax = { 30.0f, 30.0f };	//AABB�̍ő�l������B
	characterAabb.vMin = { -30.0f, -30.0f };	//AABB�̍ŏ��l������B

	int count = 0;

	//��������_��AABB�̏Փ˔������������B
	for (int i = 0; i < 100; i++) {
		if (characterAabb.vMax.x > positions[i].x		//�_��x���W�����̍ő�x���W��菬�����B
			&& characterAabb.vMin.x < positions[i].x	//�_��x���W�����̍ŏ�x���W���傫���B
			&& characterAabb.vMax.y > positions[i].y	//�_��y���W�����̍ő�y���W��菬�����B
			&& characterAabb.vMin.y < positions[i].y	//�_��y���W�����̍ŏ�y���W���傫���B
		) {
			//�Փ˂��Ă�ˁB
			count++;
		}
	}
	//�������킹�B
	SubmissionAnswer(count);
	return 0;
}