#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore関数はint型の配列のaの各要素にランダムな値を代入します。
	//a[0]～a[2]を調べて、一番小さな数値を変数mに代入しなさい。
	int a[3];
	GenerateScore(a);
	
	int m = 0;
	//a[0]とa[1]の比較を行う。
	if (a[0] < a[1]) {
		//a[0]のほうが小さい。
		m = a[0];
	}
	else {
		m = a[1];
	}
	//a[0]とa[1]の比較を行った結果(m)とa[2]の比較を行う。
	if (m > a[2]) {
		//a[2]のほうが小さい。
		m = a[2];
	}

	//答え合わせ。
	SubmissionAnswer(m);
	return 0;
}