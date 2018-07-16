#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;



int main()
{
	//GenerateInteger関数はランダムな1000000個の整数値を作成して、それをvalue配列に格納します。
	//この配列を値で昇順(小さい順)に並ぶようにソートを行いなさい。
	//この配列のソートにバブルソートを使用すると、計算量1000000 * 500000 = 5000億回となってしまい、
	//恐ろしく時間がかかってしまいます。
	//高速なソートアルゴリズムの１つにクイックソートというものがあります。
	//クイックソートのアルゴリズムは下記のページで解説されています。
	//https://www.codereading.com/algo_and_ds/algo/quick_sort.html

	static int values[1000000];
	GenerateInteger(values);

	//ここから並び替えるアルゴリズムを実装する。
	
	//答え合わせ。
	SubmissionAnswer(values);
	return 0;
}