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
	//���̎��AcharacterPosition����A50�ȏ㗣��Ă���W�̐����J�E���g�B
	//�Q�_�Ԃ̋����͉��L�̂悤�Ȍv�Z�ŋ��߂邱�Ƃ��ł��܂��B
	//
	/*0�Ԗڂ̓_�ƃL�����N�^�[�Ƃ̋������v�Z����T���v���R�[�h�B
	
		//�L�����N�^�[����0�Ԗڂ̓_�Ɍ������ĐL�т�x�N�g�����v�Z����B
		Vector2 diff;
		diff.x = characterPosition.x - positions[0].x;
		diff.y = characterPosition.y - positions[0].y;
		//�O�����̒藝���g���āAdiff�̑傫�������߂�B
		float t = diff.x * diff.x + diff.y * diff.y;
		//sqrt��C����̕W���֐��ŁA�����œn���ꂽ�����̕��������v�Z���Ă���܂��B
		float dist = sqrt( t );
	*/
	//�����_���ɍ��W���쐬�B
	Vector2 positions[100];
	GeneratePositions(positions);

	//�L�����̍��W�B
	Vector2 characterPosition = {20.0f, 30.0f};
	int count = 0;
	//�������狗���𒲂ׂ�R�[�h���L�q����B





	//�������킹�B
	SubmissionAnswer(count);
	return 0;
}