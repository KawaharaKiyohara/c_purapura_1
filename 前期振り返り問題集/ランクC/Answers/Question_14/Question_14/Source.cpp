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
	//この配列を調べて、成人女性(２０歳以上)の数をカウントして、答えをSubmissionAnswer関数に渡しなさい。
	//UserAccountInfoのメンバ変数のageが年齢で、UserAccountInfoのメンバ変数のgenderが0なら男性です。

	UserAccountInfo account[100];
	GenerateUserAccountInfo(account);

	//成人女性の数を数える。。
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (account[i].age >= 20
			&& account[i].gender == 0
		) {
			count++;
		}
	}
	//答え合わせ。
	SubmissionAnswer(count);
	return 0;
}