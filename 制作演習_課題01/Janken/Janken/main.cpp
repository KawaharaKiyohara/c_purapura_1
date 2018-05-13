#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
	//乱数を初期化。
	srand((unsigned)time(NULL));
	
	//whileは条件部分がtrueの間、処理を繰り返す構文です。
	//このような、ずっと回るループがゲームには必ずあります。
	//これがゲームループと呼ばれるものです。。
	while (true) {
		//rand関数はランダムな整数値を返してきます。
		//その返ってきた値を３で割ったあまりをcomに代入しているので、
		//変数comには0～2の値がランダムに入ります。
		int com = rand() % 3;	//0がグー、１がチョキ、２がパー。
	}

	return 0;
}