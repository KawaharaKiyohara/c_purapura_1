#include "Player.h"
#include <iostream>
#include <Windows.h>
#include "PlayerStateIdle.h"
#include "PlayerStateMove.h"
#include "PlayerStateDeath.h"

Player::Player()
{
	//待機ステートに切り替える。
	ChangeState< PlayerStateIdle>();
}
Player::~Player()
{
	delete currentState;
}
template<class T> void Player::ChangeState()
{
	//待機状態に切り替え。
	if (currentState != nullptr) {
		//現在のステートを破棄する。
		delete currentState;
	}
	//次の状態のインスタンスを作成する。
	currentState = new T;
}
void Player::Update()
{
	//現在の状態によって処理が変わる更新処理を実行。
	currentState->Update();
	if (GetAsyncKeyState('J')) {
		//現在の状態にジャンプ可能か問い合わせを行う。
		if (currentState->IsPossibleJump()) {
			std::cout << "ジャンプしました！\n";
		}
	}
	//現在の状態が無敵か問い合わせを行う。
	if (currentState->IsInvincible()) {
		std::cout << "無敵です！。\n";
	}
	//ここから状態切り替えのコード。
	//これらも状態に依存するなら、各状態クラスに委譲しても良い。
	if (GetAsyncKeyState('A')) {
		ChangeState<PlayerStateIdle>();
	}

	if (GetAsyncKeyState('S')) {
		//移動状態に切り替え。
		ChangeState<PlayerStateMove>();
	}

	if (GetAsyncKeyState('D')) {
		//死亡状態に切り替え。
		ChangeState<PlayerStateDeath>();
	}
}
