#pragma once
#include <random>
#include <Windows.h>

std::random_device rd;

const int RANK_NO = 1;
const int QUESTION_NO = 1;
//ランクをチェックする。
static inline void CheckRank()
{
	FILE* fp = nullptr;
	fopen_s(&fp, "../../../bin/progress.txt", "r");
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
	CheckRank();
	FILE* fp = nullptr;
	fopen_s(&fp, "../../../bin/progress.txt", "w");
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
int g_avg;
static inline void GenerateScore(int score[])
{
	g_avg = 0;
	std::mt19937 mt(rd());
	for (int i = 0; i < 40; i++) {
		g_avg += score[i] = mt() % 100;
	}
	g_avg /= 40;
}
static inline void SubmissionAnswer(int avg)
{
	if (avg != g_avg) {
		MessageBox(NULL,  "不正解(´・ω・｀)", "結果はっぴょー", MB_OK);
	}
	else {
		MessageBox(NULL, "正解(　･`ω･´)\n", "結果はっぴょー", MB_OK);
		AdvanceDrillProgress();
	}
}