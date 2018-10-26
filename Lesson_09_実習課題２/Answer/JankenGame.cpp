#include "pch.h"
#include "JankenGame.h"
#include <iostream>
#include <random>

using namespace std;


void JankenGame::DispResultMessage(int result)
{
	//勝敗に応じたメッセージを格納する
	const char* message[] = {
		"あなたの勝ちです\n\n",
		"引き分けです\n\n",
		"あなたの負けです\n\n",
	};
	cout << message[result];
}

void JankenGame::DispComNoTe()
{
	const char* str[] = {
		"コンピューターの手はグーです。\n",
		"コンピューターの手はチョキです。\n",
		"コンピューターの手はパーです。\n",
	};
	cout << str[comNoTe];
}

void JankenGame::DispPlayerNoTe()
{
	const char* str[] = {
		"プレイヤーの手はグーです。\n",
		"プレイヤーの手はチョキです。\n",
		"プレイヤーの手はパーです。\n",
	};
	cout << str[playerNoTe];
}


void JankenGame::Run()
{
	//メルセンヌツイスタアルゴリズムを使った乱数生成器を初期化する。
	random_device rnd;
	mt19937 mtRnd(rnd());

	//ゲームループ。
	while (true) {

		//comの手を0～2の範囲でランダムに決定する。
		comNoTe = mtRnd() % 3;

		//プレイヤーの手を入力させる。
		cout << "手を選択してください。0:グー、1:チョキ、2:パー\n";
		cin >> playerNoTe;

		//勝敗テーブル。
		//0だとあなたの勝ち、1だと引き分け、2だとあなたの負け。
		const int resultTbl[3][3] = {
			{1, 0, 2 },
			{2, 1, 0 },
			{0, 2, 1 },
		};
		//Comの手を表示。
		DispComNoTe();

		//プレイヤーの手を表示。
		DispPlayerNoTe();

		////////////////////////////////////////////////////////////
		//実習課題
		//DispResultMessage関数に渡す引数を考えよう！
		//この関数の仕様は下記のとおりです。
		//下記のように引数に整数の0を渡すと、「あなたの勝ちです。」と表示されます。
		//  DispResultMessage( 0 );
		//
		//下記のように引数に整数の1を渡すと、「引き分けです。」と表示されます。
		//  DispResultMessage( 1 );
		//
		//下記のように引数に整数の2を渡すと、「あなたの負けです。」と表示されます。
		//  DispResultMessage( 2 );
		//
		//ヒント　resultTblを使います。
		//
		////////////////////////////////////////////////////////////
		DispResultMessage( /*resultTbl[playerNoTe][comNoTe]*/ );
	}
}
