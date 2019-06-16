#include "Player.h"
#include <iostream>
#include <Windows.h>

Player::Player()
{
	//�����X�e�[�g�͑ҋ@�B
	ChangeState(&idleState);
}
void Player::ChangeState(IPlayerState* nextState)
{
	//�ҋ@��Ԃɐ؂�ւ��B
	if (currentState != nullptr) {
		currentState->Leave();
	}
	currentState = nextState;
	currentState->Enter();

}
void Player::Update()
{
	currentState->Update();
	if (GetAsyncKeyState('J')) {
		if (currentState->IsPossibleJump()) {
			std::cout << "�W�����v���܂����I\n";
		}
	}
	if (currentState->IsInvincible()) {
		std::cout << "���G�ł��I�B\n";
	}
	if (GetAsyncKeyState('A')) {
		ChangeState(&idleState);
	}

	if (GetAsyncKeyState('S')) {
		//�ړ���Ԃɐ؂�ւ��B
		ChangeState(&moveState);
	}

	if (GetAsyncKeyState('D')) {
		//���S��Ԃɐ؂�ւ��B
		ChangeState(&deathState);
	}
}
