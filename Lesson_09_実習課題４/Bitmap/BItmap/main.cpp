// Janken.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include "Bitmap.h"

using namespace std;

/*!
 *@brief	メイン関数。
 */
int main()
{
	Bitmap bm;
	bm.Load("test.bmp");
	bm.ConvertMonochrome();
	bm.Save("test2.bmp");
	return 0;
}


