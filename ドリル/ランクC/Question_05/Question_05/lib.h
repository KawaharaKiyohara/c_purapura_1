#pragma once
#include <random>
#include <Windows.h>

std::random_device rd;


const int RANK_NO = 1;
const int QUESTION_NO = 5;
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


int g_answer;
static inline void GenerateScore(int score[])
{
	CheckRank();
	g_answer = 0;
	std::mt19937 mt(rd());
	for (int i = 0; i < 39; i++) {
		score[i] = mt() % 100;
		if (score[i] <= 50) {
			g_answer++;
		}
	}
	score[39] = 50;	//境界チェックのために最後に必ず50を入れる。
					//<=と<の使い分けを覚えるために。
	g_answer++;
}
static inline void SubmissionAnswer(int answer)
{
	if (answer != g_answer) {
		MessageBox(NULL,  "不正解(´・ω・｀)", "結果はっぴょー", MB_OK);
	}
	else {
		MessageBox(NULL, "正解(　･`ω･´)\n", "結果はっぴょー", MB_OK);
		AdvanceDrillProgress();
	}
}