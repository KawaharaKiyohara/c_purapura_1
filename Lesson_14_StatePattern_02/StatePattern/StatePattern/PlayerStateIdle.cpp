#include "PlayerStateIdle.h"
#include <iostream>

void PlayerStateIdle::Enter()
{
	std::cout << "�ҋ@��Ԃɐ؂�ւ������B\n";
}
void PlayerStateIdle::Leave()
{
	std::cout << "�ҋ@��Ԃ��I�������B\n";
}
void PlayerStateIdle::Update()
{
	std::cout << "�ҋ@��Ԓ��ł��B\n";
}
