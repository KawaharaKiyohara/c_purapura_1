// kadai_00.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include "KadaiGenerator.h"

/// <summary>
/// 課題_01
/// 配列、for、if文
/// 配列ａにはランダムなアルファベットが設定されます。
/// この配列ａに格納されている文字を調べて、格納されている文字が
/// kなら1、bなら2、cなら3を配列ｂに代入して、'k'、'b'、'c'以外の文字の場合は4を代入しなさい。
/// 
/// 例
///   a[0]が'k'なら、b[0]に1を代入する。
///   a[1]が'b'なら、b[1]に2を代入する。
///   a[2]が'c'なら、b[2]に3を代入する。
///   a[3]が'd'なら、b[3]に4を代入する。
///   a[4]が'z'なら、b[4]に4を代入する。
/// 　　　・
/// 　　　・
/// 　　　・
///   a[n]が'k'なら、b[n]に１を代入する。
///   
/// </summary>
/// <returns></returns>
int main()
{
	KadaiGenerator gene;
	//配列aと定義。
	char a[100] = { 0 };
	int b[100] = { 0 };

	//配列aにランダムな値を設定する。
	gene.Generate(a);

	//ここから、
	for (int i = 0; i < 100; i++) {
		if (a[i] == 'k') {
			b[i] = 1;
		}
		else if (a[i] == 'b') {
			b[i] = 2;
		}
		else if (a[i] == 'c') {
			b[i] = 3;
		}
		else {
			b[i] = 4;
		}
	}



	
	//ここまでの間にプログラムを追加しなさい。

	//答え合わせ。
	gene.CheckAnswer(b);
}

