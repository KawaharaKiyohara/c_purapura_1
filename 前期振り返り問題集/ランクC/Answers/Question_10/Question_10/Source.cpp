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
	//この配列を調べて、男性の数をカウントして、答えをSubmissionAnswer関数に渡しなさい。
	//UserAccountInfoのメンバ変数のgenderの値が1なら男性。

	UserAccountInfo acount[100];
	GenerateUserAccountInfo(acount);

	//男性の数を調べる。
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (acount[i].gender == 1) {
			count++;
		}
	}
	//答え合わせ。
	SubmissionAnswer(count);
	return 0;
}