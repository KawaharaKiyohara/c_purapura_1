// kadai_00.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include "KadaiGenerator.h"

/// <summary>
/// 課題_01
/// 配列、for、if文
/// 配列aにはランダムな数値が設定されます。
/// この配列aに格納されている値を調べて、その値が２の倍数なら２を加算、３の倍数ならなら３を加算、５の倍数なら５を加算して配列bに設定しなさい。
/// 
/// 例
///   a[0]が２の倍数なら、b[0]に２を加算する。
///   a[1]が３の倍数なら、b[1]に３を加算する。
///   a[2]が５の倍数なら、b[2]に５を加算する。
///   a[3]が２の倍数かつ３の倍数なら(例えばa[3]が６の時）はb[3]には２＋３の５が設定される。
/// 　　　・
/// 　　　・
/// 　　　・
///   a[n]が２の倍数なら、b[n]に２を加算する。
///   
/// </summary>
/// <returns></returns>
int main()
{
	KadaiGenerator gene;
	//配列aと配列bを定義。
	int a[100] = { 0 };
	int b[100] = { 0 };

	//配列aにランダムな値を設定する。
	gene.Generate(a);

	//ここから、
	for (int i = 0; i < 100; i++) {
		if (a[i] % 2 == 0) {
			b[i] += 2;
		}
		if (a[i] % 3 == 0) {
			b[i] += 3;
		}
		if (a[i] % 5 == 0) {
			b[i] += 5;
		}
	}

	//ここまでの間にプログラムを追加しなさい。

	//答え合わせ。
	gene.CheckAnswer(b);
}

