#include "PlayerStateIdle.h"
#include <iostream>

PlayerStateIdle::PlayerStateIdle()
{
	std::cout << "�ҋ@��Ԃɐ؂�ւ������B\n";
}
PlayerStateIdle::~PlayerStateIdle()
{
	std::cout << "�ҋ@��Ԃ��I�������B\n";
}
void PlayerStateIdle::Update()
{
	std::cout << "�ҋ@��Ԓ��ł��B\n";
}
