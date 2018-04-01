#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "整数１を入力してください。\n";
	cin >> num1;
	cout << "整数２を入力してください。\n";
	cin >> num2;
	//平均を求める。
	int avg = num1 + num2;	//まず合計をavgに代入して。
	avg = avg / 2;			//avgを2で割った結果をavgに代入する。

	cout << "整数１と整数２の平均値は" << avg << "です。\n";


	return 0;
}