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

	//�j���̐��𒲂ׂ�g���Č�����B
	int count = 0;
	
	//�������킹�B
	SubmissionAnswer(count);
	return 0;
}