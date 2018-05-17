#include <iostream>
#include "consoleLib.h"
#include <time.h>
#include <stdlib.h>
#include "reel.h"

int main()
{
	//乱数を初期化。
	srand((unsigned)time(NULL));

	int reel_1;		//1列目のリール。
	int reel_2;		//2列目のリール。
	int reel_3;		//3列目のリール。
	//リール１～３の初期化。
	//reel_1、reel_2、reel_3には0～9の値がランダムに入ります。
	InitReel(reel_1, reel_2, reel_3);

	int kaitenReel_1_flag = 1;	//1列目のリールが回転しているかどうかのフラグ。1なら回転中とする。
	int kaitenReel_2_flag = 1;	//2列目のリールが回転しているかどうかのフラグ。1なら回転中とする。
	int kaitenReel_3_flag = 1;	//3列目のリールが回転しているかどうかのフラグ。1なら回転中とする。
	
	//ここからゲームループ。
	while (true) {
		//1フレームの開始。
		kbcBeginFrame();
		
		//リールの回転処理。
		if (kaitenReel_1_flag == 1) {
			//リール１の回転処理。
			KaitenReel( reel_1 );
		}
		if (kaitenReel_2_flag == 1) {
			//リール２が回転中。
			KaitenReel( reel_2 );
		}
		if (kaitenReel_3_flag == 1) {
			//リール３が回転中。
			KaitenReel( reel_3 );
		}
		//スロットのリールの番号を表示する。
		DrawReelNo(reel_1, reel_2, reel_3);

		//ここから、
		
		//ここまでの間に課題のリールを止めるプログラムと、
		//結果を表示するプログラムを書く！
		//1フレームの終了。
		kbcEndFrame();
	}

	return 0;
}