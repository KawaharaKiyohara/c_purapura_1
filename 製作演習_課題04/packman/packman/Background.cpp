#include "stdafx.h"
#include "Background.h"


//２次元配列。教科書のp.256から配列に関する記述があります。多次元配列はp.269

void DrawBackground()
{
	//二次元配列のmapを参照して、背景を描画していく。
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {
			if (g_map[y][x] == 0) {
				//2次元配列のmap[y][x]に0が入っていたら、
				//座標x, yの場所に空白文字を描画する。
				kbcDrawMoji(x, y, ' ');
			}
			else if (g_map[y][x] == 1) {
				//2次元配列のmap[y][x]に1が入っていたら、
				//座標x, yの場所に@を描画する。
				kbcDrawMoji(x, y, '@');
			}
		}
	}
}