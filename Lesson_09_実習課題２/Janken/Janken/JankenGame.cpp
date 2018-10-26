#include "pch.h"
#include "JankenGame.h"
#include <iostream>
#include <random>

using namespace std;


void JankenGame::DispResultMessage(int result)
{
	//���s�ɉ��������b�Z�[�W���i�[����
	const char* message[] = {
		"���Ȃ��̏����ł�\n\n",
		"���������ł�\n\n",
		"���Ȃ��̕����ł�\n\n",
	};
	cout << message[result];
}

void JankenGame::DispComNoTe()
{
	const char* str[] = {
		"�R���s���[�^�[�̎�̓O�[�ł��B\n",
		"�R���s���[�^�[�̎�̓`���L�ł��B\n",
		"�R���s���[�^�[�̎�̓p�[�ł��B\n",
	};
	cout << str[comNoTe];
}

void JankenGame::DispPlayerNoTe()
{
	const char* str[] = {
		"�v���C���[�̎�̓O�[�ł��B\n",
		"�v���C���[�̎�̓`���L�ł��B\n",
		"�v���C���[�̎�̓p�[�ł��B\n",
	};
	cout << str[playerNoTe];
}


void JankenGame::Run()
{
	//�����Z���k�c�C�X�^�A���S���Y�����g�������������������������B
	random_device rnd;
	mt19937 mtRnd(rnd());

	//�Q�[�����[�v�B
	while (true) {

		//com�̎��0�`2�͈̔͂Ń����_���Ɍ��肷��B
		comNoTe = mtRnd() % 3;

		//�v���C���[�̎����͂�����B
		cout << "���I�����Ă��������B0:�O�[�A1:�`���L�A2:�p�[\n";
		cin >> playerNoTe;

		//���s�e�[�u���B
		//0���Ƃ��Ȃ��̏����A1���ƈ��������A2���Ƃ��Ȃ��̕����B
		const int resultTbl[3][3] = {
			{1, 0, 2 },
			{2, 1, 0 },
			{0, 2, 1 },
		};
		//Com�̎��\���B
		DispComNoTe();

		//�v���C���[�̎��\���B
		DispPlayerNoTe();

		////////////////////////////////////////////////////////////
		//���K�ۑ�
		//DispResultMessage�֐��ɓn���������l���悤�I
		//���̊֐��̎d�l�͉��L�̂Ƃ���ł��B
		//���L�̂悤�Ɉ����ɐ�����0��n���ƁA�u���Ȃ��̏����ł��B�v�ƕ\������܂��B
		//  DispResultMessage( 0 );
		//
		//���L�̂悤�Ɉ����ɐ�����1��n���ƁA�u���������ł��B�v�ƕ\������܂��B
		//  DispResultMessage( 1 );
		//
		//���L�̂悤�Ɉ����ɐ�����2��n���ƁA�u���Ȃ��̕����ł��B�v�ƕ\������܂��B
		//  DispResultMessage( 2 );
		//
		//�q���g�@resultTbl���g���܂��B
		//
		////////////////////////////////////////////////////////////
		DispResultMessage( /*resultTbl[playerNoTe][comNoTe]*/ );
	}
}
