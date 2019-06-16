#pragma once
#include "IPlayerState.h"

class PlayerStateDeath : public IPlayerState
{
public:
	virtual void Enter();
	virtual void Leave();
	virtual void Update();
	//�W�����v�ł���H
	virtual bool IsPossibleJump()
	{
		//��ׂȂ��B
		return false;
	}
	//���G�H
	virtual bool IsInvincible()
	{
		//����Ӗ��Ŗ��G�ł͂Ȃ��B
		return true;
	}
};

