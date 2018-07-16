#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore関数は40人の成績をランダムに生成して、
	//それを、score配列に格納します。
	//この配列を調べて50点より高い点(50点は含まない)をとった生徒の数をcount変数に記録しなさい。
	//そしてその結果をAnswer関数に渡しなさい。
	//答えがあっていれば、正解のメッセージボックスが表示されます。
	//なお、小数点は切り捨てになります。
	int score[40];
	GenerateScore(score);

	int count = 0;
	for (int i = 0; i < 40; i++) {
		if (score[i] > 50) {
			count++;
		}
	}
	//答え合わせ。
	SubmissionAnswer(count);
	return 0;
}