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
	//AABB��AABB�Ƃ̏Փ˔���B
	//GenerateAABBs�֐��̓����_����100��AABB���쐬���āA�����aabbs�z��Ɋi�[���܂��B
	//�������ꂽAABB�̂����������A�L�����N�^�[��AABB��\��characterAabb�ƏՓ˂��Ă��邩�J�E���g���Ȃ����B
	//AABB�̏ڂ��������͉��L��URL���Q�ƁB
	//https://qiita.com/HIEMON/items/a392c34b602eb653c337
	//http://d.hatena.ne.jp/taiyakisun/20120205/1328410006
	//
	//�����������ł̃q���g�B
	//���AABB�Aa��b���Փ˂���̂́A���L�̏����𖞂����Ƃ��A
	// a�̍ő�l > b�̍ŏ��l && a�̍ŏ��l < b�̍ő�l
	//

	//�����_����AABB��100�쐬����B
	AABB aabbs[100];
	GenerateAABBs(aabbs);

	AABB characterAabb;
	characterAabb.vMax = { 30.0f, 30.0f };	//AABB�̍ő�l������B
	characterAabb.vMin = { -30.0f, -30.0f };	//AABB�̍ŏ��l������B

	int count = 0;

	//��������AABB��AABB�̏Փ˔������������B
	for (int i = 0; i < 100; i++) {
		if (characterAabb.vMax.x > aabbs[i].vMin.x		//characterAabb�̍ő�x���W��aabbs[i]�̍ŏ�x���W���傫���B
			&& characterAabb.vMax.y > aabbs[i].vMin.y	//characterAabb�̍ő�y���W��aabbs[i]�̍ŏ�y���W���傫���B
			&& characterAabb.vMin.x < aabbs[i].vMax.x	//characterAabb�̍ŏ�x���W��aabbs[i]�̍ő�x���W��菬�����B
			&& characterAabb.vMin.y < aabbs[i].vMax.y	//characterAabb�̍ŏ�x���W��aabbs[i]�̍ő�x���W��菬�����B
			) {
			//�Փ˂��Ă�ˁB
			count++;
		}
	}
	//�������킹�B
	SubmissionAnswer(count);
	return 0;
}