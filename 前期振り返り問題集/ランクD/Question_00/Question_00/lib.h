#pragma once
#include <random>
#include <Windows.h>

std::random_device rd;

const int RANK_NO = 0;
const int QUESTION_NO = 0;
const char* saveFilePath = "../../../bin/progress.txt";
int questionNo;
int currentQuestionNo;
//�����N���`�F�b�N����B
static inline void CheckRank()
{
	
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
static inline void GenerateScore(int& score0, int& score1)
{
	CheckRank();
	g_answer = 0;
	std::mt19937 mt(rd());
	score0 = mt() % 100;
	score1 = mt() % 100;
	g_answer = score0 + score1;
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