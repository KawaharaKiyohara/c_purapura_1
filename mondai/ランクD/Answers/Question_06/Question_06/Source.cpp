#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore関数はint型の配列のaの各要素にランダムな値を代入します。。
	//変数cにa[0]とa[1]とa[2]を加算した結果を代入しなさい。
	int a[3];
	GenerateScore(a);
	
	int c = a[0] + a[1] + a[2];

	//答え合わせ。
	SubmissionAnswer(c);
	return 0;
}