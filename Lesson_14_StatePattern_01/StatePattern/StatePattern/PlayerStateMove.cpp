#include "PlayerStateMove.h"
#include <iostream>

PlayerStateMove::PlayerStateMove()
{
	std::cout << "移動状態に切り替わったよ。\n";
}
PlayerStateMove::~PlayerStateMove()
{
	std::cout << "移動状態が終わったよ。\n";
}
void PlayerStateMove::Update()
{
	std::cout << "移動状態です。\n";
}

