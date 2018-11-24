//
#include "stdafx.h"
#include <iostream>
#include "MyStringGenerator.h"
using namespace std;

int MyStrlen(const char* str);
void MyStrcpy(char* dst, const char* src);
bool MyStrcmp(const char* str1, const char* str2);
void MyStrcat(char* str1, const char* str2);
void MyPrint(const char* str);

int main()
{
	MyPrint("********************************\n");
	MyPrint("テスト開始！！！\n");
	MyPrint("********************************\n\n");

	//文字列のランダム生成器のインスタンスを定義。
	//これはkbcの自作クラスやで。
	MyStringGenerator strGene;
	
	//文字列をランダム生成。
	char* str = strGene.RandomGenerate();
	int len = MyStrlen(str);
	
	if (len != strlen(str) ) {
		printf("MyStrlenの実装が間違ってるよ(´・ω・｀)\n" );
		return 0;
	}
	printf("MyStrlenの実装ＯＫ( ´艸｀)\n");
	//文字列をランダム生成。
	str = strGene.RandomGenerate();
	//srcをコピーできる、十分な領域を確保する。
	auto dst = std::make_unique<char[]>(strlen(str) + 1);
	MyStrcpy(dst.get(), str);
	if (strcmp(dst.get(), str) != 0) {
		printf("MyStrcpyの実装が間違ってるよ(´・ω・｀)\n");
		return 0;
	}
	printf("MyStrcpyの実装ＯＫ(≧∇≦*)\n");

	//文字列比較
	str = strGene.RandomGenerate();
	//50%の確率で文字列が異なるようにする。
	char* str2;
	std::random_device rd;
	if (rd() % 2) {
		dst = std::make_unique<char[]>(strlen(str) + 1);
		strcpy(dst.get(), str);
		str2 = dst.get();
	}
	else {
		//こっちは文字列をランダムに生成する。
		str2 = strGene.RandomGenerate();
	}
	bool equal = MyStrcmp(str, str2);
	if (equal == true) {
		if (strcmp(str, str2) != 0) {
			printf("MyStrcmpの実装が間違ってるよ(´・ω・｀)\n");
			return 0;
		}
	}
	else {
		if (strcmp(str, str2) == 0) {
			printf("MyStrcmpの実装が間違ってるよ(´・ω・｀)\n");
			return 0;
		}
	}
	printf("MyStrcmpの実装ＯＫ(*ﾟ▽ﾟ*)\n");
	str = strGene.RandomGenerate();
	char hogehoge[256], hogehoge2[256];
	strcpy(hogehoge, str);
	strcpy(hogehoge2, str);
	str = strGene.RandomGenerate();
	MyStrcat(hogehoge, str);
	strcat(hogehoge2, str);
	if (strcmp(hogehoge, hogehoge2) != 0) {
		printf("MyStrcatの実装が間違ってるよ(´・ω・｀)\n");
		return 0;
	}
	printf("MyStrcatの実装ＯＫ(((o(*ﾟ▽ﾟ*)o)))\n");

	printf("全部クリア！おめでとう！三└(┐卍^o^)卍ﾄﾞｩﾙﾙﾙﾙﾙ\n");

	return 0;
}
