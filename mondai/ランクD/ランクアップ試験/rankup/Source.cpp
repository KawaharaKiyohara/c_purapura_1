#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	for (int i = 0; i < 100; i++) {
		//GenerateScore�֐���int�^�̔z���a�̊e�v�f�Ƀ����_���Ȓl�������܂��B
		//GenerateScore�֐��̌Ăяo���̌�ŁAa[0]��a[1]�̔�r���s���āAa[1]�̂ق�����������΁A
		//�����̃A���S���Y�����g���āAa[0]��a[1]�̒l���������Ȃ����B
		//�Ȃ��A���̉ۑ�͐������ꂽ�l���Aa[0]�̂ق����������Ȃ�Ƌ��R�N���A�ł��Ă��܂��̂ŁA
		//100��`�F�b�N���s���B

		int a[2];
		GenerateScore(a);
		//������������̃A���S���Y���������āAa[1]�̂ق�����������΁Aa[0]��a[1]�����ւ���B
		//���L�͌����̃A���S���Y���̉������B�����o��̂Œ��ӁB
		//https://www.youtube.com/watch?v=Y-nZ8dYaY-A&feature=youtu.be
	



		//�������킹�B
		SubmissionAnswer(a);
	}

	//���ʕ\���B
	DispSuccess();

	return 0;
}