#include <iostream>
#include "lib.h"

using namespace std;

//���[�U�[�A�J�E���g�̏���\���\���́B
struct UserAccountInfo {
	int gender;		//���ʁB0�������A1���j���B
	int age;		//�N��B
};



int main()
{
	//GenerateUserAccountInfo�֐���100�l�̃��[�U�[�A�J�E���g�������_���ɐ������āA
	//������Aaccount�z��Ɋi�[���܂��B
	//���̔z��𒲂ׂāA�j���̐����J�E���g���āA������SubmissionAnswer�֐��ɓn���Ȃ����B
	//UserAccountInfo�̃����o�ϐ���gender�̒l��1�Ȃ�j���B

	UserAccountInfo acount[100];
	GenerateUserAccountInfo(acount);

	//�j���̐��𒲂ׂ�B
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (acount[i].gender == 1) {
			count++;
		}
	}
	//�������킹�B
	SubmissionAnswer(count);
	return 0;
}