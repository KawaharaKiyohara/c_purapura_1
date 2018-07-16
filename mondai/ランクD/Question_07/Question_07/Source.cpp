#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore関数はint型の配列のaの各要素にランダムな値を代入します。
	//a[0]とa[1]とa[2]の平均値を計算して、変数avgに代入しなさい。
	//小数点は切り捨てで構いません。

	int a[3];
	GenerateScore(a);
	
	int avg = 0;

	//答え合わせ。
	SubmissionAnswer(avg);
	return 0;
}