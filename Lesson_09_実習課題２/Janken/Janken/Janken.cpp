// Janken.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include "JankenGame.h"

using namespace std;

/*!
 *@brief	メイン関数。
 */
int main()
{
	//JankenGameクラスの変数を定義する。
	JankenGame jg;

	//じゃんけんゲームを実行。
	jg.Run();
	
	return 0;
}


