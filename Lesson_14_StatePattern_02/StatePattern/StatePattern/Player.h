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
	PlayerStateIdle idleState;		//待機ステート。
	PlayerStateMove moveState;		//移動ステート。
	PlayerStateDeath deathState;	//死亡ステート。
	IPlayerState* currentState;		//現在のステート。
};

