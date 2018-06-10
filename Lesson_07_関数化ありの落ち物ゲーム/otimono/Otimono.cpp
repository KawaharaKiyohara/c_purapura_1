#include <iostream>
#include "consoleLib.h"
#include "Otimono.h"
#include <algorithm>

std::vector<Otimono>	otimonoArray;	//落ち物の可変長配列。
int gameCount = 0;

void DrawOtimono()
{
	//描画。
	for (auto& otimono : otimonoArray) {
		kbcDrawMoji(otimono.posX, otimono.posY, '*');
	}
}
void MoveOtimono()
{
	gameCount++;
	if (gameCount == 10) {
		//30フレーム経過したら新しい落ち物を発生させる。
		Otimono otimono;
		//落ち物のX座標をランダムで決定。
		otimono.posX = (rand() % 14) + 1;
		otimono.posY = 0;
		//ゲームカウントを0に戻す。
		gameCount = 0;
		otimonoArray.push_back(otimono);
	}
	//全ての落ち物を落下させる。
	for (auto& otimono : otimonoArray) {
		if ((gameCount % 5) == 0) {
			//5フレームに一度落下する。
			otimono.posY += 1;
		}
	}
	//リストから削除。	
	otimonoArray.erase(std::remove_if(otimonoArray.begin(), otimonoArray.end(), [&](auto& otimono)->bool {
		return otimono.posY == 18 || otimono.dead == 1;
	}), otimonoArray.end());

}