#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	for (int i = 0; i < 100; i++) {
		//GenerateScore関数はint型の配列のaの各要素にランダムな値を代入します。
		//GenerateScore関数の呼び出しの後で、a[0]とa[1]の比較を行って、a[1]のほうが小さければ、
		//交換のアルゴリズムを使って、a[0]とa[1]の値を交換しなさい。
		//なお、この課題は生成された値が、a[0]のほうが小さくなると偶然クリアできてしまうので、
		//100回チェックを行う。

		int a[2];
		GenerateScore(a);
		//ここから交換のアルゴリズムを書いて、a[1]のほうが小さければ、a[0]とa[1]を入れ替える。
		//下記は交換のアルゴリズムの解説動画。音が出るので注意。
		//https://www.youtube.com/watch?v=Y-nZ8dYaY-A&feature=youtu.be
	



		//答え合わせ。
		SubmissionAnswer(a);
	}

	//結果表示。
	DispSuccess();

	return 0;
}