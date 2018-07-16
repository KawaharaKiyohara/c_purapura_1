
#include "lib.h"

//ユーザーアカウントの情報を表す構造体。
struct UserAccountInfo {
	int gender;		//性別。0が女性、1が男性。
	int age;		//年齢。
};

std::random_device rd;

const int RANK_NO = 1;
const int QUESTION_NO = 10;
const char* saveFilePath = "../../../bin/progress.txt";
int questionNo;
int currentQuestionNo;
//ランクをチェックする。
void CheckRank()
{
	FILE* fp = nullptr;
	fopen_s(&fp, saveFilePath, "r");
	if (fp == nullptr) {
		MessageBox(NULL, "この問題に挑む資格はない！(`・ω´・ ●)ノ\n", "出直せ！", MB_OK);
		exit(0);
	}
	char text[256];
	fgets(text, 256, fp);
	questionNo = atoi(text);
	currentQuestionNo = RANK_NO * 100 + QUESTION_NO;
	if (currentQuestionNo > questionNo) {
		MessageBox(NULL, "この問題に挑む資格はない！(`・ω´・ ●)ノ\n", "出直せ！", MB_OK);
		exit(0);
		fclose(fp);

	}
	fclose(fp);
}
void AdvanceDrillProgress()
{
	if (currentQuestionNo < questionNo) {
		return;
	}
	FILE* fp = nullptr;
	fopen_s(&fp, saveFilePath, "w");
	if (fp == nullptr) {
		MessageBox(NULL, "ファイルの保存に失敗しました。PCを再起動とかしてみてください。(´・ω・｀)\n", "ごめんなさい", MB_OK);
		exit(0);
	}
	char text[256];
	int nextQuestionNo = RANK_NO * 100 + QUESTION_NO + 1;
	sprintf_s(text, "%d", nextQuestionNo);
	fwrite(text, strlen(text) + 1, 1, fp);
	fclose(fp);
}


int g_answer;
void GenerateUserAccountInfo(UserAccountInfo account[])
{
	CheckRank();
	g_answer = 0;
	std::mt19937 mt(rd());
	for (int i = 0; i < 100; i++) {
		account[i].gender = mt() % 2;
		account[i].age = mt() % 80;
		if (account[i].gender == 1) {
			g_answer++;
		}
	}
}
void SubmissionAnswer(int answer)
{
	if (answer != g_answer) {
		MessageBox(NULL, "不正解(´・ω・｀)", "結果はっぴょー", MB_OK);
	}
	else {
		MessageBox(NULL, "正解(　･`ω･´)\n", "結果はっぴょー", MB_OK);
		AdvanceDrillProgress();
	}
}