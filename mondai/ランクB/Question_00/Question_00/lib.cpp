
#include "lib.h"

//2次元のベクトル構造体。
struct Vector2 {
	float x;
	float y;
};
std::random_device rd;

const int RANK_NO = 2;
const int QUESTION_NO = 0;
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
void GeneratePositions(Vector2 positions[])
{
	CheckRank();
	g_answer = 0;
	Vector2 characterPosition = { 20.0f, 30.0f };
	std::mt19937 mt(rd());
	for (int i = 0; i < 100; i++) {
		float t = (float)(mt() % 100000) / 100000.0f;
		positions[i].x = -100.0f * t + 100.0f * (1.0f - t);
		t = (float)(mt() % 100000) / 100000.0f;
		positions[i].y = -100.0f * t + 100.0f * (1.0f - t);

		Vector2 diff;
		diff.x = characterPosition.x - positions[i].x;
		diff.y = characterPosition.y - positions[i].y;
		float len = sqrt(diff.x * diff.x + diff.y * diff.y);
		if (len >= 50.0f) {
			g_answer++;
		}
	}
}
void SubmissionAnswer(int answer)
{
	if (g_answer != answer) {
		MessageBox(NULL, "不正解(´・ω・｀)", "結果はっぴょー", MB_OK);
	}
	else {
		MessageBox(NULL, "正解(　･`ω･´)\n", "結果はっぴょー", MB_OK);
		AdvanceDrillProgress();
	}
}