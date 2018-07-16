
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
const int QUESTION_NO = 5;
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

	Sphere characterSphere;
	characterSphere.position = { 20.0f, 15.0f };
	characterSphere.radius = 60.0f; 
	g_count = 0;
	//ここから球と球の衝突判定を実装する。
	for (int i = 0; i < 100; i++) {
		Vector2 diff;
		diff.x = characterSphere.position.x - sphere[i].position.x;
		diff.y = characterSphere.position.y - sphere[i].position.y;
		float len = sqrt(diff.x * diff.x + diff.y * diff.y);

		if (len < characterSphere.radius + sphere[i].radius	) {
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