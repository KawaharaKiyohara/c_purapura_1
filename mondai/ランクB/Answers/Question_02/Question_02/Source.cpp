#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;

//2次元のベクトル構造体。
struct Vector2 {
	float x;
	float y;
};


int main()
{
	//GeneratePosition関数はランダムな100個の座標を作成して、それをpositions配列に格納します。
	//この配列をx座標の数値の値で昇順(小さい順)に並ぶようにソートを行いなさい。
	//ソートアルゴリズムの一つのバブルソートのアルゴリズムは下記のページで解説されています。
	//https://www.codereading.com/algo_and_ds/algo/bubble_sort.html

	Vector2 positions[100];
	GeneratePositions(positions);
	//ここから並び替えるアルゴリズムを実装する。
	for (int i = 0; i < 99; i++) {
		for (int j = 99; j > i; j--) {
			if (positions[j - 1].x > positions[j].x ) {
				Vector2 temp = positions[j - 1];
				positions[j - 1] = positions[j];
				positions[j] = temp;
			}
		}
	}
	//答え合わせ。
	SubmissionAnswer(positions);
	return 0;
}