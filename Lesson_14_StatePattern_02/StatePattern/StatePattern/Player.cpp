#include "Player.h"
#include <iostream>
#include <Windows.h>

Player::Player()
{
	//初期ステートは待機。
	ChangeState(&idleState);
}
void Player::ChangeState(IPlayerState* nextState)
{
	//待機状態に切り替え。
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
			std::cout << "ジャンプしました！\n";
		}
	}
	if (currentState->IsInvincible()) {
		std::cout << "無敵です！。\n";
	}
	if (GetAsyncKeyState('A')) {
		ChangeState(&idleState);
	}

	if (GetAsyncKeyState('S')) {
		//移動状態に切り替え。
		ChangeState(&moveState);
	}

	if (GetAsyncKeyState('D')) {
		//死亡状態に切り替え。
		ChangeState(&deathState);
	}
}
