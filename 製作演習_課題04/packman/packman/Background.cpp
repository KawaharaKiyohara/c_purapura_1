#include "stdafx.h"
#include "Background.h"


//�Q�����z��B���ȏ���p.256����z��Ɋւ���L�q������܂��B�������z���p.269

void DrawBackground()
{
	//�񎟌��z���map���Q�Ƃ��āA�w�i��`�悵�Ă����B
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {
			if (g_map[y][x] == 0) {
				//2�����z���map[y][x]��0�������Ă�����A
				//���Wx, y�̏ꏊ�ɋ󔒕�����`�悷��B
				kbcDrawMoji(x, y, ' ');
			}
			else if (g_map[y][x] == 1) {
				//2�����z���map[y][x]��1�������Ă�����A
				//���Wx, y�̏ꏊ��@��`�悷��B
				kbcDrawMoji(x, y, '@');
			}
		}
	}
}