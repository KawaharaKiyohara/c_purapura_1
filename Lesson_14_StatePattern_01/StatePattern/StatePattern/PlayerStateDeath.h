#pragma once
#include "IPlayerState.h"

class PlayerStateDeath : public IPlayerState
{
public:
	PlayerStateDeath();
	~PlayerStateDeath();
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

