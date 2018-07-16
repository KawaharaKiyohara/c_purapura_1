#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;

extern std::mt19937 g_rand;

/*!
 *@brief	線形探索を行う。
 *@param[in]	values		探索を行う配列。
 *@param[in]	numalue		配列の要素数。
 *@param[in]	target		検索対象となる値。
 *@return trueが帰ってきたら、見つかった。
 */
bool LinearSearch( int values[], int numValue, int target )
{
	//試しに線形探索をしてみよう。
	for (int i= 0; i < numValue; i++) {
		if (target == values[i]) {
			//見つかった。
			return true;
		}
	}
	//見つからなかった。
	return false;
}

int main()
{
	//【問題】
	//   ランダムに生成された1000000個の整数値の集合に、目的の数値が含まれているかを1000000回調べる。
	//【プログラムの解説】
	//   GenerateInteger関数はランダムな1000000個の整数値を作成して、それをvalue配列に格納します。
	//   また、この配列は昇順にソートされています。
	//   50行目～の63行目までの1000000回繰り返されるループでは、毎回、0～1999999のランダムな整数を生成して、   
	//　 変数tに代入しています。この変数tの値が配列valuesに含まれているかどうかを、毎回調べて、
	//　 含まれている場合はcountをインクリメントしなさい。また、tの値がvaluesに含まれていることがわかったら、
	//　 すぐに次の探索に移行してください。つまり、１回の探索でcountの値は最大で1しか加算されません。
	//　 また、探索のアルゴリズムに線形探索を行った場合、平均1000000×500000回の計算が行われるため
	//   非常に時間がかかってしまいます。高速な探索アルゴリズムとして、バイナリーサーチがあります。
	//   バイナリサーチのアルゴリズムは下記のURLを参照してください。
	//   https://www.codereading.com/algo_and_ds/algo/binary_search.html

	static int values[1000000];
	GenerateInteger(values);

	int count = 0;
	//
	for (int i = 0; i < 1000000; i++) {
		//ランダムに値を生成する。
		int t = g_rand() % 2000000;
		//下のコメントアウトを外すと、線形探索を使って実装したバージョンを試せる。
		//どれくらい時間がかかるか確認してみよう。
		/*if (LinearSearch(values, 1000000, t) == true) {
			//見つかった。
			count++;
		}*/
		//*******************************************************
		//【ここから探索のプログラムを実装】
		//*******************************************************

	}

	//答え合わせ。
	SubmissionAnswer(count);
	return 0;
}