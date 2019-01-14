#include <iostream>
#include "MyString.h"
#include "MyStringGenerator.h"
using namespace std;

int main()
{
	bool isOk = true;

	std::random_device rd;
	MyStringGenerator gen;
	char* str = gen.RandomGenerate();
	MyString myStr;
	myStr = str;
	//Length関数のテスト。
	int len = strlen(str);
	if (len != myStr.Length()) {
		printf("Length関数の実装が正しくありません。\n");
		isOk = false;
	}
	//Search関数のテスト。
	for (int i = 0; i < 26; i++) {
		char ch = 'A' + i;
		char* hoge = strchr(str, ch);
		if (hoge == nullptr) {
			//見つからなかった。
			if (myStr.Search(ch) != -1) {
				printf("Search関数の実装が正しくありません。\n");
				isOk = false;
				break;
			}
		}
		else {
			std::uintptr_t pos = reinterpret_cast<std::uintptr_t>(hoge)
				- reinterpret_cast<std::uintptr_t>(str);
			if ((int)pos != myStr.Search(ch)) {
				printf("Search関数の実装が正しくありません。\n");
				isOk = false;
				break;
			}
		}
	}
	//Insert関数のテスト。100回もテストすればええでしょう。
	for (int i = 0; i < 100; i++) {
		myStr = str;
		//挿入する位置を決める。
		int insertPos = rd() % len;
		//挿入する文字を決める。
		char ch[2];
		ch[0] = 'a' + (rd() % 26);
		ch[1] = '\0';
		std::string stdString = str;
		stdString.insert((size_t)insertPos, ch);
		myStr.Insert(insertPos, ch[0]);
		if (!(myStr == stdString.c_str())) {
			printf("Insert関数の実装が正しくありません。\n");
			isOk = false;
			break;
		}
	}

	if (isOk) {
		printf("全課題クリア！！！！\n(*ﾉωﾉ)\n");
	}
	return 0;
}