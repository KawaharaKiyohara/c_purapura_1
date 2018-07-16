
#include "lib.h"

//2�����̃x�N�g���\���́B
struct Vector2 {
	float x;
	float y;
};


//�����s�o�E���f�B���O�{�b�N�X�B
struct AABB {
	Vector2	vMax;	//���̍ő�x���W�ƁA�ő�y���W�B
	Vector2	vMin;	//���̍ŏ�x���W�ƁA�ő�y���W�B
};

std::random_device rd;

const int RANK_NO = 2;
const int QUESTION_NO = 4;
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
	aabb.vMax = { 30.0f, 30.0f };	//AABB�̍ő�l������B
	aabb.vMin = { -30.0f, -30.0f };	//AABB�̍ŏ��l������B
	g_count = 0;
	//��������AABB��AABB�̏Փ˔������������B
	for (int i = 0; i < 100; i++) {
		if (aabb.vMax.x > aabbs[i].vMin.x	
			&& aabb.vMax.y > aabbs[i].vMin.y
			&& aabb.vMin.x < aabbs[i].vMax.x
			&& aabb.vMin.y < aabbs[i].vMax.y
			) {
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