#include <iostream>
#include "consoleLib.h"
#include <time.h>
#include <stdlib.h>
#include "reel.h"

int main()
{
	//�������������B
	srand((unsigned)time(NULL));

	int reel_1;		//1��ڂ̃��[���B
	int reel_2;		//2��ڂ̃��[���B
	int reel_3;		//3��ڂ̃��[���B
	//���[���P�`�R�̏������B
	//reel_1�Areel_2�Areel_3�ɂ�0�`9�̒l�������_���ɓ���܂��B
	InitReel(reel_1, reel_2, reel_3);

	int kaitenReel_1_flag = 1;	//1��ڂ̃��[������]���Ă��邩�ǂ����̃t���O�B1�Ȃ��]���Ƃ���B
	int kaitenReel_2_flag = 1;	//2��ڂ̃��[������]���Ă��邩�ǂ����̃t���O�B1�Ȃ��]���Ƃ���B
	int kaitenReel_3_flag = 1;	//3��ڂ̃��[������]���Ă��邩�ǂ����̃t���O�B1�Ȃ��]���Ƃ���B
	
	//��������Q�[�����[�v�B
	while (true) {
		//1�t���[���̊J�n�B
		kbcBeginFrame();
		
		//���[���̉�]�����B
		if (kaitenReel_1_flag == 1) {
			//���[���P�̉�]�����B
			KaitenReel( reel_1 );
		}
		if (kaitenReel_2_flag == 1) {
			//���[���Q����]���B
			KaitenReel( reel_2 );
		}
		if (kaitenReel_3_flag == 1) {
			//���[���R����]���B
			KaitenReel( reel_3 );
		}
		//�X���b�g�̃��[���̔ԍ���\������B
		DrawReelNo(reel_1, reel_2, reel_3);

		//��������A
		
		//�����܂ł̊Ԃɉۑ�̃��[�����~�߂�v���O�����ƁA
		//���ʂ�\������v���O�����������I
		//1�t���[���̏I���B
		kbcEndFrame();
	}

	return 0;
}