#include <iostream>
#include "Vector.h"
#include <random>

using namespace std;

int main()
{	
	//非決定的な乱数生成機。
	//ベクトルの各要素をランダムに決定するときに使うのさ。
	random_device rd; 

	//要素数3のベクトル型の配列を定義する。
	Vector v[3];  
	
	for ( int i = 0; i < 3; i++ ) {
		//ベクトルの要素を乱数生成機を使ってランダムに決定する。
		//warningでるけど、気にしない。
		//rd()はランダムな整数を返してきます。
		//そして、ランダムに生成した整数を50で割った余りをベクトルの各要素に
		//代入しているので、ベクトルの各要素は0～49までの値となります。
		v[i].x = rd() % 50;
		v[i].y = rd() % 50;
		v[i].z = rd() % 50;
		
		//vの各要素と大きさを表示する。
		cout << "v[" << i << "]" << "の値は？\n";
		v[i].Display();
		cout << "大きさは、" << v[i].Length() << "です\n";
		cout << "\n";
	}
	float maxLen = 0.0f;	//最も小さい距離を記録するための変数。
	float maxVectorNo = 0;	//最も大きいベクトルの番号を記録するための変数。
	//一番大きいベクトルを調べるぞい。
	for ( int i = 0; i < 3; i++ ) {
		//i番目のベクトルの長さを計算する。
		float len = v[i].Length();
		if ( maxLen < len ) {
			//このベクトルの方が大きいので、
			//maxLenとmaxVectorNoを上書きする。
			maxLen = len;
			maxVectorNo = i;
		}
	}
	cout << "最も大きいベクトルは" << maxVectorNo << "番目です。\n";

	float minLen = FLT_MAX;	//最も小さい距離を記録するための変数。
	float minVectorNo = 0;	//最も小さいベクトルの番号を記録するための変数。

	//一番小さいベクトルを調べるぞい。
	for (int i = 0; i < 3; i++) {
		//i番目のベクトルの長さを計算する。
		float len = v[i].Length();
		if (minLen > len) {
			//このベクトルの方が小さいので、
			//minLenとminVectorNoを上書きする。
			minLen = len;
			minVectorNo = i;
		}
	}

	cout << "最も小さいベクトルは" << minVectorNo << "番目です。\n";

	return 0;
}