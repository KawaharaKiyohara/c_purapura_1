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
	//Length�֐��̃e�X�g�B
	int len = strlen(str);
	if (len != myStr.Length()) {
		printf("Length�֐��̎���������������܂���B\n");
		isOk = false;
	}
	//Search�֐��̃e�X�g�B
	for (int i = 0; i < 26; i++) {
		char ch = 'A' + i;
		char* hoge = strchr(str, ch);
		if (hoge == nullptr) {
			//������Ȃ������B
			if (myStr.Search(ch) != -1) {
				printf("Search�֐��̎���������������܂���B\n");
				isOk = false;
				break;
			}
		}
		else {
			std::uintptr_t pos = reinterpret_cast<std::uintptr_t>(hoge)
				- reinterpret_cast<std::uintptr_t>(str);
			if ((int)pos != myStr.Search(ch)) {
				printf("Search�֐��̎���������������܂���B\n");
				isOk = false;
				break;
			}
		}
	}
	//Insert�֐��̃e�X�g�B100����e�X�g����΂����ł��傤�B
	for (int i = 0; i < 100; i++) {
		myStr = str;
		//�}������ʒu�����߂�B
		int insertPos = rd() % len;
		//�}�����镶�������߂�B
		char ch[2];
		ch[0] = 'a' + (rd() % 26);
		ch[1] = '\0';
		std::string stdString = str;
		stdString.insert((size_t)insertPos, ch);
		myStr.Insert(insertPos, ch[0]);
		if (!(myStr == stdString.c_str())) {
			printf("Insert�֐��̎���������������܂���B\n");
			isOk = false;
			break;
		}
	}

	if (isOk) {
		printf("�S�ۑ�N���A�I�I�I�I\n(*Ƀ��)\n");
	}
	return 0;
}