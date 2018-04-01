#include <iostream>
using namespace std;

int main()
{
	int num;
	cout << "出席番号を入力してください。\n";
	cin >> num;
	int groupNo = num % 5;
	cout << "あなたのグループは" << groupNo << "です。\n";
	return 0;
}