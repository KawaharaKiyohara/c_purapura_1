#include "PlayerStateDeath.h"
#include <iostream>

void PlayerStateDeath::Enter()
{
	std::cout << "Ž€–Só‘Ô‚ÉØ‚è‘Ö‚í‚Á‚½‚æB\n";
}
void PlayerStateDeath::Leave()
{
	std::cout << "Ž€–Só‘Ô‚ªI‚í‚Á‚½‚æB\n";
}
void PlayerStateDeath::Update()
{
	std::cout << "Ž€–Só‘Ô‚Å‚·B\n";
}
