#include "PlayerStateDeath.h"
#include <iostream>

void PlayerStateDeath::Enter()
{
	std::cout << "���S��Ԃɐ؂�ւ������B\n";
}
void PlayerStateDeath::Leave()
{
	std::cout << "���S��Ԃ��I�������B\n";
}
void PlayerStateDeath::Update()
{
	std::cout << "���S��Ԃł��B\n";
}
