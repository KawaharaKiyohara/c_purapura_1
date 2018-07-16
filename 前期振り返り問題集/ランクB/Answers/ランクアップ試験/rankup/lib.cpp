
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

const char* saveFilePath = "../../../../bin/progress.txt";
int questionNo;
int currentQuestionNo;
//�����N���`�F�b�N����B
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
		MessageBox(NULL, "�t�@�C���̕ۑ��Ɏ��s���܂����BPC���ċN���Ƃ����Ă݂Ă��������B(�L�E�ցE�M)\n", "���߂�Ȃ���", MB_OK);
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

	//�L�����N�^�̍��W�B
	Vector2 characerPosition = { 20.0f, 15.0f };
	memcpy(g_answers, sphere, sizeof(g_answers));
	//�܂��̓L�����Ƃ̋������v�Z����B
	float toCharaLength[100];
	for (int i = 0; i < 100; i++) {
		Vector2 diff;
		diff.x = characerPosition.x - g_answers[i].position.x;
		diff.y = characerPosition.y - g_answers[i].position.y;
		toCharaLength[i] = sqrt(diff.x * diff.x + diff.y * diff.y);
	}

	//�\�[�g����B
	for (int i = 0; i < 99; i++) {
		for (int j = 99; j > i; j--) {
			if (toCharaLength[j - 1] > toCharaLength[j]) {
				//C++�W���A���S���Y����swap�֐����g�p����B
				std::swap(toCharaLength[j], toCharaLength[j - 1]);
				std::swap(g_answers[j], g_answers[j - 1]);
			}
		}
	}
}
void SubmissionAnswer(Sphere sphere[])
{
	if (memcmp(sphere, g_answers, sizeof(g_answers) )!= 0) {
		MessageBox(NULL, "�s����(�L�E�ցE�M)", "���ʂ͂��҂�[", MB_OK);
	}
	else {
		MessageBox(NULL, "����(�@�`�֥�L)\n", "���ʂ͂��҂�[", MB_OK);
		AdvanceDrillProgress();
	}
}