#include "stdafx.h"
#include "Food.h"


CFood g_foodArray[MAX_FOOD];	//�H�ו��̔z��B

void CFood::Initialyze( int x, int y)
{
	posX = x;
	posY = y;
}

void CFood::Draw()
{
	if (isDead == 0) {
		//���S���Ă��Ȃ��B
		kbcDrawMoji(
			posX,
			posY,
			'.',
			enStringColor_Green
		);
	}
}