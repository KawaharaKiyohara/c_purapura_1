#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore関数はint型の配列のaの各要素にランダムな値を代入します。
	//GenerateScore関数の呼び出しの後で、交換のアルゴリズムを使って、a[0]とa[1]の値を
	//交換しなさい。
	int a[2];
	GenerateScore(a);
	//ここから交換のアルゴリズムを書いて、a[0]とa[1]を入れ替える。
	//下記は交換のアルゴリズムの解説動画。音が出るので注意。
	//https://www.youtube.com/watch?v=Y-nZ8dYaY-A&feature=youtu.be

	int tmp = a[0]; //a[0]の値をバックアップする。
	a[0] = a[1];    //a[0]にa[1]の値を代入する。
	a[1] = tmp;     //a[1]にバックアップを取っていたa[0]の値を代入する。

	//答え合わせ。
	SubmissionAnswer(a);
	return 0;
}