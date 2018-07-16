#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore関数は変数aとbにランダムな数値を代入します。
	//変数cにa+bの値を代入するようにコードを改造しなさい。
	int a, b;
	GenerateScore(a, b);
	
	int c = 0;


	//答え合わせ。
	SubmissionAnswer(c);
	return 0;
}