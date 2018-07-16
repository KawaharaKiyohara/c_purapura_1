#pragma once
#include <random>
#include <Windows.h>

std::random_device rd;

const int RANK_NO = 0;
const int QUESTION_NO = 8;
const char* saveFilePath = "../../../../bin/progress.txt";
int questionNo;
int currentQuestionNo;
//ランクをチェックする。
static inline void CheckRank()
{
	FILE* fp = nullptr;
	fopen_s(&fp, saveFilePath, "r");
	if (fp == nullptr) {
		MessageBox(NULL, "この問題に挑む資格はない！(`・ω´・ ●)ノ\n", "出直せ！", MB_OK);
		exit(0);
	}
	char text[256];
	fgets(text, 256, fp);
	int questionNo = atoi(text);
	int currentQuestionNo = RANK_NO * 100 + QUESTION_NO;
	if (currentQuestionNo > questionNo) {
		MessageBox(NULL, "この問題に挑む資格はない！(`・ω´・ ●)ノ\n", "出直せ！", MB_OK);
		exit(0);
		fclose(fp);

	}
	fclose(fp);
}
void AdvanceDrillProgress()
{
	if(currentQuestionNo < questionNo){
		return ;
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
static inline void GenerateScore(int hoge[])
{
	CheckRank();
	g_answer = 0;
	std::mt19937 mt(rd());
	hoge[0] = mt() % 100;
	hoge[1] = mt() % 100;
	hoge[2] = mt() % 100;
	if (hoge[0] > hoge[1]) {
		//a[0]のほうが大きい。
		g_answer = hoge[0];
	}
	else {
		g_answer = hoge[1];
	}
	if (g_answer < hoge[2]) {
		//a[2]のほうが大きい。
		g_answer = hoge[2];
	}
}
static inline void SubmissionAnswer(int answer)
{
	if (answer != g_answer) {
		MessageBox(NULL,  "不正解(´・ω・｀)", "結果はっぴょー", MB_OK);
	}
	else {
		MessageBox(NULL, "正解(　･`ω･´)\n", "結果はっぴょー", MB_OK);
		//ドリルの進捗を進める。
		AdvanceDrillProgress();
	}
}