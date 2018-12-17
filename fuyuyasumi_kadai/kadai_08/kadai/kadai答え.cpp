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
/// 'k'ならtotal_kに１を加算、'b'ならtotal_bに1を加算、'c'ならtotal_cに1を加算しなさい。
/// ただし、'z'が出てきたら、total_k、total_b、total_cから10減算しなさい。
/// 
/// 例
///   a[0]が'k'なら、total_kに1を加算する。
///   a[1]が'b'なら、total_bに1を加算する。
///   a[2]が'c'なら、total_cに1を加算する。
///   a[3]が'z'なら、total_k、total_b、total_cから10減算。
///   a[4]が'f'なら、何もしない。
/// 　　　・
/// 　　　・
/// 　　　・
///   a[n]が'k'なら、total_kに1を加算する。
///   
/// </summary>
/// <returns></returns>
int main()
{
	KadaiGenerator gene;
	//配列aと定義。
	char a[100] = { 0 };
	int total_k, total_b, total_c;
	total_k = total_b = total_c = 0;

	//配列aにランダムな値を設定する。
	gene.Generate(a);

	//ここから、
	for (int i = 0; i < 100; i++) {
		if (a[i] == 'k') {
			total_k++;
		}
		if (a[i] == 'b') {
			total_b++;
		}
		if (a[i] == 'c') {
			total_c++;
		}
		if (a[i] == 'z') {
			total_k -= 10;
			total_b -= 10;
			total_c -= 10;
		}
	}

	
	//ここまでの間にプログラムを追加しなさい。

	//答え合わせ。
	gene.CheckAnswer(total_k, total_b, total_c);
}

