#include <iostream>
#include "lib.h"

using namespace std;

//日にち情報。
struct Date {
	int month;	//月
	int day;	//日
};

//ユーザーアカウントの情報を表す構造体。
struct UserAccountInfo {
	int gender;		//性別。0が女性、1が男性。
	int age;		//年齢。
	Date birthday;	//生年月日。
};



int main()
{
	//GenerateUserAccountInfo関数は100人のユーザーアカウントをランダムに生成して、
	//それを、account配列に格納します。
	//この配列を調べて、男性成人の数、女性成人の数、4月または7月生まれで女性の人数をカウントしなさい。
	//誕生月は下記のように調べることができます。
	//
	//　８月生まれを検索するサンプルコード
	//  for( int i = 0; i < 100; i++){
	//		if( account[i].birthday.month == 8 ){
	//			//何かしらのコードを書く。
	//		}
	//	}
	UserAccountInfo account[100];
	GenerateUserAccountInfo(account);

	//男性成人の数、女性成人の数、未成年の数をそれぞれカウントする。
	int manCount = 0;		//男性の数。
	int womanCount = 0;		//女性の数。
	int woman_birthday_4_7 = 0;	//未成年の数。
	for (int i = 0; i < 100; i++) {
		//４月 or ７月生まれの女性の人数をカウントする。
		if (account[i].gender == 0) {
			if (account[i].birthday.day == 4
				|| account[i].birthday.day == 7
				) {
				woman_birthday_4_7++;
			}
		}
		//成人女性を調べる。
		if (account[i].gender == 0 && account[i].age >= 20) {
			womanCount++;
		}
		//成人男性を調べる。
		if (account[i].gender == 1 && account[i].age >= 20) {
			manCount++;
		}
	}
	//答え合わせ。
	SubmissionAnswer(manCount, womanCount, woman_birthday_4_7);
	return 0;
}