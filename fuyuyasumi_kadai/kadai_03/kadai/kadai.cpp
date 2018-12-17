// kadai_00.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include "KadaiGenerator.h"

/// <summary>
/// 課題_03
/// 配列、for、if文
/// 配列aにはランダムな数値が設定されます。
/// この配列aに格納されている値を調べて、
/// ２の倍数の値の合計を変数total_2に、
/// ３の倍数の値の合計をtotal_3に、
/// ５の倍数の値の合計をtotal_cに設定しなさい。
/// 
/// 例
///   a[0]が２の倍数なら、total_2にa[0]を加算する。
///   a[1]が３の倍数なら、total_3にa[1]を加算する。
///   a[2]が５の倍数なら、total_5にa[2]を加算する。
///   a[3]が２の倍数かつ３の倍数なら、total_2とtotal_3にa[3]を加算加算する。
/// 　　　・
/// 　　　・
/// 　　　・
///   a[n]が２の倍数なら、total_2にa[n]を加算する。
///   
/// </summary>
/// <returns></returns>
int main()
{
	KadaiGenerator gene;
	//配列aと配列bを定義。
	int a[100] = { 0 };
	int b[100] = { 0 };

	//total_2、total_3、total_5の変数定義。
	int total_2, total_3, total_5;
	total_2 = total_3 = total_5 = 0;

	//配列aにランダムな値を設定する。
	gene.Generate(a);

	//ここから、




	
	//ここまでの間にプログラムを追加しなさい。

	//答え合わせ。
	gene.CheckAnswer(total_2, total_3, total_5);
}

