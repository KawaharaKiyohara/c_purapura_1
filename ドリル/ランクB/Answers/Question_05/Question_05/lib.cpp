
#include "lib.h"

//2�����̃x�N�g���\���́B
struct Vector2 {
	float x;
	float y;
};


//���B
struct Sphere {
	Vector2	position;	//���̒��S���W�B
	float radius;		//���̔��a�B
};

std::random_device rd;

const int RANK_NO = 2;
const int QUESTION_NO = 5;
const char* saveFilePath = "../../../../bin/progress.txt";
int questionNo;
int currentQuestionNo;
//�����N���`�F�b�N����B
void CheckRank()
{
	FILE* fp = nullptr;
	fopen_s(&fp, saveFilePath, "r");
	if (fp == nullptr) {
		MessageBox(NULL, "���̖��ɒ��ގ��i�͂Ȃ��I(`�E�ցL�E ��)�m\n", "�o�����I", MB_OK);
		exit(0);
	}
	char text[256];
	fgets(text, 256, fp);
	questionNo = atoi(text);
	currentQuestionNo = RANK_NO * 100 + QUESTION_NO;
	if (currentQuestionNo > questionNo) {
		MessageBox(NULL, "���̖��ɒ��ގ��i�͂Ȃ��I(`�E�ցL�E ��)�m\n", "�o�����I", MB_OK);
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
		MessageBox(NULL, "�t�@�C���̕ۑ��Ɏ��s���܂����BPC���ċN���Ƃ����Ă݂Ă��������B(�L�E�ցE�M)\n", "���߂�Ȃ���", MB_OK);
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
	//�������狅�Ƌ��̏Փ˔������������B
	for (int i = 0; i < 100; i++) {
		Vector2 diff;
		diff.x = characterSphere.position.x - sphere[i].position.x;
		diff.y = characterSphere.position.y - sphere[i].position.y;
		float len = sqrt(diff.x * diff.x + diff.y * diff.y);

		if (len < characterSphere.radius + sphere[i].radius	) {
			//�Փ˂��Ă�ˁB
			g_count++;
		}
	}
}
void SubmissionAnswer(int count)
{
	if (g_count != count) {
		MessageBox(NULL, "�s����(�L�E�ցE�M)", "���ʂ͂��҂�[", MB_OK);
	}
	else {
		MessageBox(NULL, "����(�@�`�֥�L)\n", "���ʂ͂��҂�[", MB_OK);
		AdvanceDrillProgress();
	}
}