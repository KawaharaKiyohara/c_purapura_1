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




	//答え合わせ。
	SubmissionAnswer(m);
	return 0;
}