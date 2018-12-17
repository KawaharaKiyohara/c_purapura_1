// kadai_00.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include "KadaiGenerator.h"

/// <summary>
/// 課題_01
/// 数値演算の基礎
/// 配列aにはランダムな数値が設定されています。
/// この配列aに格納されている値を調べて、その値が偶数なら1を、奇数なら2を下記の配列bに設定しなさい。
/// 
/// 例
///   a[0]が偶数なら、b[0]に1を代入する。
///   a[1]が奇数なら、b[1]に2を代入する。
///   a[2]が偶数なら、b[2]に1を代入する。
/// 　　　・
/// 　　　・
/// 　　　・
///   a[n]が偶数なら、b[n]に1を代入する。
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


	//ここまでの間にプログラムを追加しなさい。

	//答え合わせ。
	gene.CheckAnswer(b);
}

