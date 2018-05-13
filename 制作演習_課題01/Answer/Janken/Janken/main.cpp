#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
	//乱数を初期化。
	srand((unsigned)time(NULL));
	
	int battleCount = 0;	//バトルカウントの初期化。
	int playerWinCount = 0;	//プレイヤーの勝利数。
	int comWinCount = 0;	//Comの勝利数。
	int evenCount = 0;		//引き分けの回数。

	//whileは条件部分がtrueの間、処理を繰り返す構文です。
	//このようなずっと回るループがゲームにはあって、
	//これがゲームループと呼ばれるものです。。
	while (true) {
		//COMの手をランダムに決定。
		int com = rand() % 3;	//0がグー、１がチョキ、２がパー。
		//ここからプレイヤーの手を入力させる。
		int player;
		cout << "******************第 " << battleCount + 1 << " 回戦*********************\n";
		cout << "手を選んでください。0 : グー、1：チョキ、2：パー\n";
		cin >> player;

		//プレイヤーの手を表示。
		if (player == 0) {
			cout << "プレイヤーの手はグー。\n";
		}
		else if (player == 1) {
			cout << "プレイヤーの手はチョキ。\n";
		}
		else if (player == 2) {
			cout << "プレイヤーの手はパー。\n";
		}
		//COMの手を表示。
		if (com == 0) {
			cout << "コンピュータの手はグー。\n";
		}
		else if (com == 1) {
			cout << "コンピュータの手はチョキ。\n";
		}
		else if (com == 2) {
			cout << "コンピュータの手はパー。\n";
		}
		
		//playerという変数にプレイヤーの手、comという変数にコンピュータの手の情報が入っている。
		//0がグー、１がチョキ、２がパーです。
		if (( player == 0 && com == 1 )		//プレイヤーがグー、コンピュータがチョキ。
			|| ( player == 1 && com == 2 )	//プレイヤーがチョキ、コンピュータがパー。
			|| ( player == 2 && com == 0 )	//プレイヤーがパー、コンピューターがグー。
		) {
			cout << "あなたの勝ちです。\n";
			playerWinCount++;
		}else if ((player == 1 && com == 0 ) 
			|| (player == 0 && com == 2)
			|| (player == 2 && com == 1 ) 
		){
			//プレイヤーがグー、COMがパー。
			cout << "あなたの負けです。\n";
			comWinCount++;
		}
		else {
			cout << "引き分けです。\n";
			evenCount++;
		}
		cout << "第 " << battleCount + 1 << " 回戦　終了\n";
		cout << "戦績は" << playerWinCount << "勝" << comWinCount << "敗" << evenCount << "分け" << "です。\n";
		battleCount++;
	}
	
	return 0;
}