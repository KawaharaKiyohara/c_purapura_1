#pragma once
#include <random>
#include <Windows.h>

std::random_device rd;

const int RANK_NO = 1;
const int QUESTION_NO = 0;
const char* saveFilePath = "../../../../bin/progress.txt";
int questionNo;
int currentQuestionNo;
//�����N���`�F�b�N����B
static inline void CheckRank()
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
	if(currentQuestionNo < questionNo){
		return ;
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

int g_answer;
static inline void GenerateScore(int score[])
{
	CheckRank();
	g_answer = 0;
	std::mt19937 mt(rd());
	for (int i = 0; i < 40; i++) {
		g_answer += score[i] = mt() % 100;
	}

}
static inline void SubmissionAnswer(int answer)
{
	if (answer != g_answer) {
		MessageBox(NULL,  "�s����(�L�E�ցE�M)", "���ʂ͂��҂�[", MB_OK);
	}
	else {
		MessageBox(NULL, "����(�@�`�֥�L)\n", "���ʂ͂��҂�[", MB_OK);
		//�h�����̐i����i�߂�B
		AdvanceDrillProgress();
	}
}