#include "PlayerStateIdle.h"
#include <iostream>

PlayerStateIdle::PlayerStateIdle()
{
	std::cout << "待機状態に切り替わったよ。\n";
}
PlayerStateIdle::~PlayerStateIdle()
{
	std::cout << "待機状態が終わったよ。\n";
}
void PlayerStateIdle::Update()
{
	std::cout << "待機状態中です。\n";
}
