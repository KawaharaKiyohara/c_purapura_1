#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore関数は40人の成績をランダムに生成して、
	//それを、score配列に格納します。
	//この配列を調べて50点以上の点(50点を含む)をとった生徒の数をcount変数に記録しなさい。
	//そしてその結果をAnswer関数に渡しなさい。
	//答えがあっていれば、正解のメッセージボックスが表示されます。

	int score[40];
	GenerateScore(score);

	int count = 0;

	//答え合わせ。
	SubmissionAnswer(count);
	return 0;
}