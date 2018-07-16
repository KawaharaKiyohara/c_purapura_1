
#include "lib.h"

//2次元のベクトル構造体。
struct Vector2 {
	float x;
	float y;
};


//球。
struct Sphere {
	Vector2	position;	//球の中心座標。
	float radius;		//球の半径。
};

std::random_device rd;

const int RANK_NO = 2;

const char* saveFilePath = "../../../../bin/progress.txt";
int questionNo;
int currentQuestionNo;
//ランクをチェックする。
void CheckRank()
{
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


Sphere g_answers[100];
void GenerateSpheres(Sphere sphere[])
{
	CheckRank();
	std::mt19937 mt(rd());
	for (int i = 0; i < 100; i++) {
		float t = (float)(mt() % 100000) / 100000.0f;
		sphere[i].position.x = -100.0f * t + 100.0f * (1.0f - t);
		t = (float)(mt() % 100000) / 100000.0f;
		sphere[i].position.y = -100.0f * t + 100.0f * (1.0f - t);
		t = (float)(mt() % 100000) / 100000.0f;
		sphere[i].radius = 50.0f * t;
	}

	//キャラクタの座標。
	Vector2 characerPosition = { 20.0f, 15.0f };
	memcpy(g_answers, sphere, sizeof(g_answers));
	//まずはキャラとの距離を計算する。
	float toCharaLength[100];
	for (int i = 0; i < 100; i++) {
		Vector2 diff;
		diff.x = characerPosition.x - g_answers[i].position.x;
		diff.y = characerPosition.y - g_answers[i].position.y;
		toCharaLength[i] = sqrt(diff.x * diff.x + diff.y * diff.y);
	}

	//ソートする。
	for (int i = 0; i < 99; i++) {
		for (int j = 99; j > i; j--) {
			if (toCharaLength[j - 1] > toCharaLength[j]) {
				//C++標準アルゴリズムのswap関数を使用する。
				std::swap(toCharaLength[j], toCharaLength[j - 1]);
				std::swap(g_answers[j], g_answers[j - 1]);
			}
		}
	}
}
void SubmissionAnswer(Sphere sphere[])
{
	if (memcmp(sphere, g_answers, sizeof(g_answers) )!= 0) {
		MessageBox(NULL, "不正解(´・ω・｀)", "結果はっぴょー", MB_OK);
	}
	else {
		MessageBox(NULL, "正解(　･`ω･´)\n", "結果はっぴょー", MB_OK);
		AdvanceDrillProgress();
	}
}