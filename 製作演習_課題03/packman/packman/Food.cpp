#include "stdafx.h"
#include "Food.h"


SFood g_foodArray[MAX_FOOD];	//�H�ו��̔z��B

void FoodInitialyze(int foodNo, int posX, int posY)
{
	g_foodArray[foodNo].posX = posX;
	g_foodArray[foodNo].posY = posY;
}
void FoodUpdate(int foodNo)
{
}
void FoodDraw(int foodNo)
{
	if (g_foodArray[foodNo].isDead == 0) {
		//���S���Ă��Ȃ��B
		kbcDrawMoji(
			g_foodArray[foodNo].posX,
			g_foodArray[foodNo].posY,
			'.'
		);
	}
}