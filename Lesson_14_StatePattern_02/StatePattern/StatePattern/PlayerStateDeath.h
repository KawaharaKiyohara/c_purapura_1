#pragma once
#include "IPlayerState.h"

class PlayerStateDeath : public IPlayerState
{
public:
	virtual void Enter();
	virtual void Leave();
	virtual void Update();
	//ジャンプできる？
	virtual bool IsPossibleJump()
	{
		//飛べない。
		return false;
	}
	//無敵？
	virtual bool IsInvincible()
	{
		//ある意味で無敵ではない。
		return true;
	}
};

