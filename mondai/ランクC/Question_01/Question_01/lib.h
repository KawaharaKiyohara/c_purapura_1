#pragma once
#include <random>
#include <Windows.h>

std::random_device rd;

const int RANK_NO = 1;
const int QUESTION_NO = 1;
//�����N���`�F�b�N����B
static inline void CheckRank()
{
	FILE* fp = nullptr;
	fopen_s(&fp, "../../../bin/progress.txt", "r");
	if (fp == nullptr) {
		MessageBox(NULL, "���̖��ɒ��ގ��i�͂Ȃ��I(`�E�ցL�E ��)�m\n", "�o�����I", MB_OK);
		exit(0);
	}
	char text[256];
	fgets(text, 256, fp);
	int questionNo = atoi(text);
	int currentQuestionNo = RANK_NO * 100 + QUESTION_NO;
	if (currentQuestionNo > questionNo) {
		MessageBox(NULL, "���̖��ɒ��ގ��i�͂Ȃ��I(`�E�ցL�E ��)�m\n", "�o�����I", MB_OK);
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
		MessageBox(NULL, "�t�@�C���̕ۑ��Ɏ��s���܂����BPC���ċN���Ƃ����Ă݂Ă��������B(�L�E�ցE�M)\n", "���߂�Ȃ���", MB_OK);
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
		MessageBox(NULL,  "�s����(�L�E�ցE�M)", "���ʂ͂��҂�[", MB_OK);
	}
	else {
		MessageBox(NULL, "����(�@�`�֥�L)\n", "���ʂ͂��҂�[", MB_OK);
		AdvanceDrillProgress();
	}
}