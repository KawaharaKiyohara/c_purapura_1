#pragma once
#include "IPlayerState.h"

class PlayerStateIdle : public IPlayerState
{
public:
	PlayerStateIdle();
	~PlayerStateIdle();
	virtual void Update();
	//�W�����v�ł���H
	virtual bool IsPossibleJump()
	{
		//��ׂ�B
		return true;
	}
	//���G�H
	virtual bool IsInvincible()
	{
		//���G�ł͂Ȃ��B
		return false;
	}
};

