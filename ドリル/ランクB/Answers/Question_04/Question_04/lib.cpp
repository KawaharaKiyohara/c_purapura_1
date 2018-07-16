
#include "lib.h"

//2次元のベクトル構造体。
struct Vector2 {
	float x;
	float y;
};


//軸並行バウンディングボックス。
struct AABB {
	Vector2	vMax;	//箱の最大x座標と、最大y座標。
	Vector2	vMin;	//箱の最小x座標と、最大y座標。
};

std::random_device rd;

const int RANK_NO = 2;
const int QUESTION_NO = 4;
const char* saveFilePath = "../../../../bin/progress.txt";
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


int g_count;
void GenerateAABBs(AABB aabbs[])
{
	CheckRank();
	std::mt19937 mt(rd());
	for (int i = 0; i < 100; i++) {
		float t = (float)(mt() % 100000) / 100000.0f;
		aabbs[i].vMax.x = 20.0f * t + 100.0f * (1.0f - t);
		t = (float)(mt() % 100000) / 100000.0f;
		aabbs[i].vMax.y = 20.0f * t + 100.0f * (1.0f - t);

		t = (float)(mt() % 100000) / 100000.0f;
		aabbs[i].vMin.x = 10.0f * t + -100.0f * (1.0f - t);
		t = (float)(mt() % 100000) / 100000.0f;
		aabbs[i].vMin.y = 10.0f * t + -100.0f * (1.0f - t);
	}

	AABB aabb;
	aabb.vMax = { 30.0f, 30.0f };	//AABBの最大値を決定。
	aabb.vMin = { -30.0f, -30.0f };	//AABBの最小値を決定。
	g_count = 0;
	//ここからAABBとAABBの衝突判定を実装する。
	for (int i = 0; i < 100; i++) {
		if (aabb.vMax.x > aabbs[i].vMin.x	
			&& aabb.vMax.y > aabbs[i].vMin.y
			&& aabb.vMin.x < aabbs[i].vMax.x
			&& aabb.vMin.y < aabbs[i].vMax.y
			) {
			//衝突してるね。
			g_count++;
		}
	}
}
void SubmissionAnswer(int count)
{
	if (g_count != count) {
		MessageBox(NULL, "不正解(´・ω・｀)", "結果はっぴょー", MB_OK);
	}
	else {
		MessageBox(NULL, "正解(　･`ω･´)\n", "結果はっぴょー", MB_OK);
		AdvanceDrillProgress();
	}
}