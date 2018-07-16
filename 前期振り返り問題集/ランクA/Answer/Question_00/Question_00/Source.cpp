#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;


void QuickSort(int value[], int left, int right) 
{
	//
	int pivot, l_hold, r_hold;
	l_hold = left;
	r_hold = right;
	pivot = value[left];	//基準値を決める。
	while (left < right) {
		//配列の右から調べていって、基準値より小さいものが見つかるまで
		//rigthをデクリメントしていく。
		while (value[right] >= pivot && (left < right)){
			right--;
		}
		if (left != right) {
			//基準値よりも小さいので、左端に寄せる。
			value[left] = value[right];
			left++;
		}
		//続いて配列を左から調べていって、基準値より大きいものが見つかるまで
		//leftをインクリメントしていく。
		while ((value[left] <= pivot) && (left < right)) {
			left++;
		}
		if (left != right)
		{
			//基準値よりも大きいので、右斜に寄せる。
			value[right] = value[left];
			right--;
		}
	}
	value[left] = pivot;
	//ここから配列を分解して、細かくソートしていく。
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) {
		QuickSort(value, left, pivot - 1);
	}
	if (right > pivot) {
		QuickSort(value, pivot + 1, right);
	}
}

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
	QuickSort(values, 0, 1000000);

	//答え合わせ。
	SubmissionAnswer(values);
	return 0;
}