#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;



int main()
{
	//GenerateInteger関数はランダムな100個の整数値を作成して、それをvalue配列に格納します。
	//この配列を値で昇順(小さい順)に並ぶようにソートを行いなさい。
	//ソートアルゴリズムの一つのバブルソートのアルゴリズムは下記のページで解説されています。
	//https://www.codereading.com/algo_and_ds/algo/bubble_sort.html

	int values[100];
	GenerateInteger(values);

	//ここから並び替えるアルゴリズムを実装する。
	for (int i = 0; i < 99; i++) {
		for (int j = 99; j > i; j--) {
			if (values[j - 1] > values[j] ) {
				int temp = values[j - 1];
				values[j - 1] = values[j];
				values[j] = temp;
			}
		}
	}
	//答え合わせ。
	SubmissionAnswer(values);
	return 0;
}