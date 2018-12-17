// kadai_00.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include "KadaiGenerator.h"

/// <summary>
/// 課題_00
/// 数値演算の基礎
/// ローカル変数のaとbにはランダムな数値が設定されています。
/// この変数aとbを使って、下記の①～⑤の計算を行って、その結果をadd、sub、mul、div、surに代入しなさい。
/// ① 足し算（結果を変数addに代入する。）
/// 　a ＋ b
/// ② 引き算（結果を変数subに代入する。）
/// 　a － b
/// ③ 掛け算（結果を変数mulに代入する。）
/// 　a × b
/// ④ 割り算（結果を変数divに代入する。）
///   a ÷ b
/// ⑤ 割った余り（結果を変数surに代入する。)
///   a ÷ bの余剰。
/// </summary>
/// <returns></returns>
int main()
{
	KadaiGenerator gene;
	//変数aとbを定義。
	int a, b;
	//変数aとbにランダムな値を設定する。
	gene.Generate(a, b);
	//変数add,sub,mul,div, surを定義。
	int add, sub, mul, div, sur;
	add = sub = mul = div = sur = 0;
	//ここから、





	//ここまでの間にプログラムを追加しなさい。

	//答え合わせ。
	gene.CheckAnswer(add, sub, mul, div, sur);
}

