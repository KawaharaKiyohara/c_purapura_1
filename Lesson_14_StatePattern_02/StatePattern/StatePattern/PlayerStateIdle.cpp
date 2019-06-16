#include "PlayerStateIdle.h"
#include <iostream>

void PlayerStateIdle::Enter()
{
	std::cout << "待機状態に切り替わったよ。\n";
}
void PlayerStateIdle::Leave()
{
	std::cout << "待機状態が終わったよ。\n";
}
void PlayerStateIdle::Update()
{
	std::cout << "待機状態中です。\n";
}
