
#include "lib.h"

//日にち情報。
struct Date {
	int month;	//月
	int day;	//日
};

//ユーザーアカウントの情報を表す構造体。
struct UserAccountInfo {
	int gender;		//性別。0が女性、1が男性。
	int age;		//年齢。
	Date birthday;	//誕生日。
};

std::random_device rd;

const int RANK_NO = 1;

const char* saveFilePath = "../../../bin/progress.txt";
int questionNo;
int currentQuestionNo;
//ランクをチェックする。
void CheckRank()
{
	//ランクアップ試験はランクチェックはしない。
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
	int nextQuestionNo = (RANK_NO+1) * 100;
	sprintf_s(text, "%d", nextQuestionNo);
	fwrite(text, strlen(text) + 1, 1, fp);
	fclose(fp);

}

int g_answer_00;
int g_answer_01;
int g_answer_02;
void GenerateUserAccountInfo(UserAccountInfo account[])
{
	CheckRank();
	g_answer_00 = 0;
	g_answer_01 = 0;
	g_answer_02 = 0;
	std::mt19937 mt(rd());
	for (int i = 0; i < 100; i++) {
		account[i].gender = mt() % 2;
		account[i].age = mt() % 80;
		//４月 or ７月生まれの女性の人数をカウントする。
		if (account[i].gender == 0) {
			if (account[i].birthday.day == 4
				|| account[i].birthday.day == 7
				) {
				g_answer_02++;
			}
		}
		//成人女性を調べる。
		if (account[i].gender == 0 && account[i].age >= 20) {
			g_answer_01++;
		}
		//成人男性を調べる。
		if (account[i].gender == 1 && account[i].age >= 20) {
			g_answer_00++;
		}
	}
}
void SubmissionAnswer(int answer_00, int answer_01, int answer_02)
{
	if (g_answer_00 != answer_00
		|| g_answer_01 != answer_01
		|| g_answer_02 != answer_02
	) {
		MessageBox(NULL, "不正解(´・ω・｀)", "結果はっぴょー", MB_OK);
	}
	else {
		MessageBox(NULL, "正解(　･`ω･´)\n", "結果はっぴょー", MB_OK);
		AdvanceDrillProgress();
	}
}