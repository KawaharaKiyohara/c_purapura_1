#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
	//�������������B
	srand((unsigned)time(NULL));
	
	//while�͏���������true�̊ԁA�������J��Ԃ��\���ł��B
	//���̂悤�ȁA�����Ɖ�郋�[�v���Q�[���ɂ͕K������܂��B
	//���ꂪ�Q�[�����[�v�ƌĂ΂����̂ł��B�B
	while (true) {
		//rand�֐��̓����_���Ȑ����l��Ԃ��Ă��܂��B
		//���̕Ԃ��Ă����l���R�Ŋ��������܂��com�ɑ�����Ă���̂ŁA
		//�ϐ�com�ɂ�0�`2�̒l�������_���ɓ���܂��B
		int com = rand() % 3;	//0���O�[�A�P���`���L�A�Q���p�[�B
	}

	return 0;
}