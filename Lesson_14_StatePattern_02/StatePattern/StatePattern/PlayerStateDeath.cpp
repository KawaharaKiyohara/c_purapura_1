#include "PlayerStateDeath.h"
#include <iostream>

void PlayerStateDeath::Enter()
{
	std::cout << "死亡状態に切り替わったよ。\n";
}
void PlayerStateDeath::Leave()
{
	std::cout << "死亡状態が終わったよ。\n";
}
void PlayerStateDeath::Update()
{
	std::cout << "死亡状態です。\n";
}
