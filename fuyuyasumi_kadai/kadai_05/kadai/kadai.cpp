// kadai_00.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include "KadaiGenerator.h"

/// <summary>
/// 課題_05
/// 配列、for、if文
/// 配列aにはランダムな数値が設定されます。
/// この配列aに格納されている値を調べて、
/// ２の倍数または３の倍数の数値が格納されいてる数を数えて、変数にbに設定しなさい。
/// 
/// 例
///   a[0]が２の倍数または3の倍数なら、bに１を加算する。
///   a[3]が２の倍数または3の倍数なら、bに１を加算する。
/// 　　　・
/// 　　　・
/// 　　　・
///   a[n]が２の倍数または3の倍数なら、bに１を加算する。
///   
/// </summary>
/// <returns></returns>
int main()
{
	KadaiGenerator gene;
	//配列aと定義。
	int a[100] = { 0 };
	//変数bを定義。
	int b = 0;

	//配列aにランダムな値を設定する。
	gene.Generate(a);

	//ここから、




	
	//ここまでの間にプログラムを追加しなさい。

	//答え合わせ。
	gene.CheckAnswer(b);
}

