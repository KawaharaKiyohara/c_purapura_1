#include "PlayerStateDeath.h"
#include <iostream>

PlayerStateDeath::PlayerStateDeath()
{
	std::cout << "死亡状態に切り替わったよ。\n";
}
PlayerStateDeath::~PlayerStateDeath()
{
	std::cout << "死亡状態が終わったよ。\n";
}
void PlayerStateDeath::Update()
{
	std::cout << "死亡状態です。\n";
}
