#pragma once
#include "IPlayerState.h"

class PlayerStateMove : public IPlayerState
{
public:
	PlayerStateMove();
	~PlayerStateMove();
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
		//���G�ł͂Ȃ�
		return false;
	}
};

