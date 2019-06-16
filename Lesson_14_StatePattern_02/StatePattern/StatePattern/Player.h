#pragma once
#include "IPlayerState.h"
#include "PlayerStateIdle.h"
#include "PlayerStateMove.h"
#include "PlayerStateDeath.h"

class Player
{
public:
	Player();
	void Update();
private:
	void ChangeState(IPlayerState* nextState);
private:
	PlayerStateIdle idleState;		//�ҋ@�X�e�[�g�B
	PlayerStateMove moveState;		//�ړ��X�e�[�g�B
	PlayerStateDeath deathState;	//���S�X�e�[�g�B
	IPlayerState* currentState;		//���݂̃X�e�[�g�B
};

