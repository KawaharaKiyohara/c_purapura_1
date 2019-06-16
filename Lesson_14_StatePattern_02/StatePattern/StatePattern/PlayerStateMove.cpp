#include "PlayerStateMove.h"
#include <iostream>

void PlayerStateMove::Enter()
{
	std::cout << "移動状態に切り替わったよ。\n";
}
void PlayerStateMove::Leave()
{
	std::cout << "移動状態が終わったよ。\n";
}
void PlayerStateMove::Update()
{
	std::cout << "移動状態です。\n";
}

