#include <iostream>
#include "consoleLib.h"
#include "Otimono.h"
#include <algorithm>

std::vector<Otimono>	otimonoArray;	//�������̉ϒ��z��B
int gameCount = 0;

void DrawOtimono()
{
	//�`��B
	for (auto& otimono : otimonoArray) {
		kbcDrawMoji(otimono.posX, otimono.posY, '*');
	}
}
void MoveOtimono()
{
	gameCount++;
	if (gameCount == 10) {
		//30�t���[���o�߂�����V�����������𔭐�������B
		Otimono otimono;
		//��������X���W�������_���Ō���B
		otimono.posX = (rand() % 14) + 1;
		otimono.posY = 0;
		//�Q�[���J�E���g��0�ɖ߂��B
		gameCount = 0;
		otimonoArray.push_back(otimono);
	}
	//�S�Ă̗������𗎉�������B
	for (auto& otimono : otimonoArray) {
		if ((gameCount % 5) == 0) {
			//5�t���[���Ɉ�x��������B
			otimono.posY += 1;
		}
	}
	//���X�g����폜�B	
	otimonoArray.erase(std::remove_if(otimonoArray.begin(), otimonoArray.end(), [&](auto& otimono)->bool {
		return otimono.posY == 18 || otimono.dead == 1;
	}), otimonoArray.end());

}