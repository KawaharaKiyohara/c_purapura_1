#include "stdafx.h"
#include "Food.h"


CFood g_foodArray[MAX_FOOD];	//食べ物の配列。

void CFood::Initialyze( int x, int y)
{
	posX = x;
	posY = y;
}

void CFood::Draw()
{
	if (isDead == 0) {
		//死亡していない。
		kbcDrawMoji(
			posX,
			posY,
			'.',
			enStringColor_Green
		);
	}
}