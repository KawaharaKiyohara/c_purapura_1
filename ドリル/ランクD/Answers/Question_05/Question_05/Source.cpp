#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore関数はint型の配列のaの各要素にランダムな値を代入します。。
	//変数cにa[0]とa[1]を加算した結果を代入しなさい。
	int a[2];
	GenerateScore(a);
	
	int c = a[0] + a[1];

	//答え合わせ。
	SubmissionAnswer(c);
	return 0;
}