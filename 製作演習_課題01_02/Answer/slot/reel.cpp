#include <iostream>
#include "consoleLib.h"
#include <time.h>
#include <stdlib.h>

int kaitenReelCount = 0;
void KaitenReel(int& reel)
{
	if (kaitenReelCount % 5 == 0) {
		//���[���P����]���B
		reel++;				//���[���P�̒l���P���Z�B
		reel = reel % 10;	//reel_1��10�Ŋ��������܂�����B
								//�������邱�ƂŁAreel_1��0�`9�̒l�����[�v���邱�ƂɂȂ�
	}
}

void DrawReelNo(int reel_1, int reel_2, int reel_3)
{
	kaitenReelCount++;
	char text[256];
	sprintf_s(text, "%d %d %d", reel_1, reel_2, reel_3);
	kbcDrawMojiRetu(5, 3, "�ۯ�");
	kbcDrawMojiRetu(5, 5, text);

	kbcDrawMoji(4, 5, '|');
	kbcDrawMoji(4, 4, '-');
	kbcDrawMoji(5, 4, '-');
	kbcDrawMoji(6, 4, '-');
	kbcDrawMoji(6, 5, '|');
	kbcDrawMoji(4, 6, '-');
	kbcDrawMoji(5, 6, '-');
	kbcDrawMoji(6, 6, '-');

	
	
	kbcDrawMoji(7, 4, '-');
	kbcDrawMoji(8, 4, '-');
	kbcDrawMoji(8, 5, '|');	
	kbcDrawMoji(7, 6, '-');
	kbcDrawMoji(8, 6, '-');

	kbcDrawMoji(9, 4, '-');
	kbcDrawMoji(10, 4, '-');
	kbcDrawMoji(10, 5, '|');
	kbcDrawMoji(9, 6, '-');
	kbcDrawMoji(10, 6, '-');
	

	
}

void InitReel(int& reel_1, int& reel_2, int& reel_3)
{
	reel_1 = rand() % 10;
	reel_2 = rand() % 10;
	reel_3 = rand() % 10;
}
