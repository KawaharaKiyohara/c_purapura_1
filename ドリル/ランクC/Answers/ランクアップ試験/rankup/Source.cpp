#include <iostream>
#include "lib.h"

using namespace std;

//���ɂ����B
struct Date {
	int month;	//��
	int day;	//��
};

//���[�U�[�A�J�E���g�̏���\���\���́B
struct UserAccountInfo {
	int gender;		//���ʁB0�������A1���j���B
	int age;		//�N��B
	Date birthday;	//���N�����B
};



int main()
{
	//GenerateUserAccountInfo�֐���100�l�̃��[�U�[�A�J�E���g�������_���ɐ������āA
	//������Aaccount�z��Ɋi�[���܂��B
	//���̔z��𒲂ׂāA�j�����l�̐��A�������l�̐��A4���܂���7�����܂�ŏ����̐l�����J�E���g���Ȃ����B
	//�a�����͉��L�̂悤�ɒ��ׂ邱�Ƃ��ł��܂��B
	//
	//�@�W�����܂����������T���v���R�[�h
	//  for( int i = 0; i < 100; i++){
	//		if( account[i].birthday.month == 8 ){
	//			//��������̃R�[�h�������B
	//		}
	//	}
	UserAccountInfo account[100];
	GenerateUserAccountInfo(account);

	//�j�����l�̐��A�������l�̐��A�����N�̐������ꂼ��J�E���g����B
	int manCount = 0;		//�j���̐��B
	int womanCount = 0;		//�����̐��B
	int woman_birthday_4_7 = 0;	//�����N�̐��B
	for (int i = 0; i < 100; i++) {
		//�S�� or �V�����܂�̏����̐l�����J�E���g����B
		if (account[i].gender == 0) {
			if (account[i].birthday.day == 4
				|| account[i].birthday.day == 7
				) {
				woman_birthday_4_7++;
			}
		}
		//���l�����𒲂ׂ�B
		if (account[i].gender == 0 && account[i].age >= 20) {
			womanCount++;
		}
		//���l�j���𒲂ׂ�B
		if (account[i].gender == 1 && account[i].age >= 20) {
			manCount++;
		}
	}
	//�������킹�B
	SubmissionAnswer(manCount, womanCount, woman_birthday_4_7);
	return 0;
}