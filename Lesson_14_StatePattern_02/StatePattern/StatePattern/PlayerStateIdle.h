#pragma once
#include "IPlayerState.h"

class PlayerStateIdle : public IPlayerState
{
public:
	virtual void Enter();
	virtual void Leave();
	virtual void Update();
	//ジャンプできる？
	virtual bool IsPossibleJump()
	{
		//飛べる。
		return true;
	}
	//無敵？
	virtual bool IsInvincible()
	{
		//無敵ではない。
		return false;
	}
};

