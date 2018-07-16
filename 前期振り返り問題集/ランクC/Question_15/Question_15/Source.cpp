#include <iostream>
#include "lib.h"

using namespace std;

//ユーザーアカウントの情報を表す構造体。
struct UserAccountInfo {
	int gender;		//性別。0が女性、1が男性。
	int age;		//年齢。
};



int main()
{
	//GenerateUserAccountInfo関数は100人のユーザーアカウントをランダムに生成して、
	//それを、account配列に格納します。
	//この配列を調べて、男性の数、女性の数、未成年の数、をそれぞれカウントして、答えをSubmissionAnswer関数に渡しなさい。
	//UserAccountInfoのメンバ変数のageが年齢で、UserAccountInfoのメンバ変数のgenderが0なら男性です。

	UserAccountInfo account[100];
	GenerateUserAccountInfo(account);

	//男性の数、女性の数、未成年の数をそれぞれカウントする。
	int manCount = 0;		//男性の数。
	int womanCount = 0;		//女性の数。
	int miseinenCount = 0;	//未成年の数。
	


	//答え合わせ。
	SubmissionAnswer(manCount, womanCount, miseinenCount);
	return 0;
}