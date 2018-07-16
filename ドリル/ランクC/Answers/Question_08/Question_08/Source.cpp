#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore関数は40人の成績をランダムに生成して、
	//それを、score配列に格納します。
	//この配列に対して、線形探索を行って、最高得点を検索して、bestScoreに記録しなさい。
	//そしてその結果をAnswer関数に渡しなさい。
	//答えがあっていれば、正解のメッセージボックスが表示されます。

	int score[40];
	GenerateScore(score);

	//最高得点を線形探索を使って見つける。
	int bestScore = 0;
	for (int i = 0; i < 40; i++) {
		if (score[i] > bestScore) {
			bestScore = score[i];
		}
	}
	//答え合わせ。
	SubmissionAnswer(bestScore);
	return 0;
}