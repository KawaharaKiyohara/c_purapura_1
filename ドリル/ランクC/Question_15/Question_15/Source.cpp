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
	//���̔z��𒲂ׂāA�j���̐��A�����̐��A�����N�̐��A�����ꂼ��J�E���g���āA������SubmissionAnswer�֐��ɓn���Ȃ����B
	//UserAccountInfo�̃����o�ϐ���age���N��ŁAUserAccountInfo�̃����o�ϐ���gender��0�Ȃ�j���ł��B

	UserAccountInfo account[100];
	GenerateUserAccountInfo(account);

	//�j���̐��A�����̐��A�����N�̐������ꂼ��J�E���g����B
	int manCount = 0;		//�j���̐��B
	int womanCount = 0;		//�����̐��B
	int miseinenCount = 0;	//�����N�̐��B
	


	//�������킹�B
	SubmissionAnswer(manCount, womanCount, miseinenCount);
	return 0;
}