#pragma once
#include "IPlayerState.h"


class Player
{
public:
	Player();
	~Player();
	void Update();
private:
	template<class T> void ChangeState();
private:
	IPlayerState* currentState;	//現在のステート。
};

