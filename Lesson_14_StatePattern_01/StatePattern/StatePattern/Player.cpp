#include "Player.h"
#include <iostream>
#include <Windows.h>
#include "PlayerStateIdle.h"
#include "PlayerStateMove.h"
#include "PlayerStateDeath.h"

Player::Player()
{
	//�ҋ@�X�e�[�g�ɐ؂�ւ���B
	ChangeState< PlayerStateIdle>();
}
Player::~Player()
{
	delete currentState;
}
template<class T> void Player::ChangeState()
{
	//�ҋ@��Ԃɐ؂�ւ��B
	if (currentState != nullptr) {
		//���݂̃X�e�[�g��j������B
		delete currentState;
	}
	//���̏�Ԃ̃C���X�^���X���쐬����B
	currentState = new T;
}
void Player::Update()
{
	//���݂̏�Ԃɂ���ď������ς��X�V���������s�B
	currentState->Update();
	if (GetAsyncKeyState('J')) {
		//���݂̏�ԂɃW�����v�\���₢���킹���s���B
		if (currentState->IsPossibleJump()) {
			std::cout << "�W�����v���܂����I\n";
		}
	}
	//���݂̏�Ԃ����G���₢���킹���s���B
	if (currentState->IsInvincible()) {
		std::cout << "���G�ł��I�B\n";
	}
	//���������Ԑ؂�ւ��̃R�[�h�B
	//��������ԂɈˑ�����Ȃ�A�e��ԃN���X�ɈϏ����Ă��ǂ��B
	if (GetAsyncKeyState('A')) {
		ChangeState<PlayerStateIdle>();
	}

	if (GetAsyncKeyState('S')) {
		//�ړ���Ԃɐ؂�ւ��B
		ChangeState<PlayerStateMove>();
	}

	if (GetAsyncKeyState('D')) {
		//���S��Ԃɐ؂�ւ��B
		ChangeState<PlayerStateDeath>();
	}
}
