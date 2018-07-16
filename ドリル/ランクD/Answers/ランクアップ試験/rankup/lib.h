#pragma once
#include <random>
#include <Windows.h>

std::random_device rd;

const int RANK_NO = 0;
const char* saveFilePath = "../../../../bin/progress.txt";
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
	int nextQuestionNo = (RANK_NO + 1) * 100;
	sprintf_s(text, "%d", nextQuestionNo);
	fwrite(text, strlen(text) + 1, 1, fp);
	fclose(fp);
}

int g_answer[2];
static inline void GenerateScore(int hoge[])
{
	CheckRank();
	std::mt19937 mt(rd());
	hoge[0] = mt() % 100;
	hoge[1] = mt() % 100;

	if (hoge[0] > hoge[1]) {
		g_answer[1] = hoge[0];
		g_answer[0] = hoge[1];
	}
	else {
		g_answer[0] = hoge[0];
		g_answer[1] = hoge[1];
	}

	
}
static inline void SubmissionAnswer(int answer[])
{
	if (answer[0] != g_answer[0]
		|| answer[1] != g_answer[1] ) {
		MessageBox(NULL,  "�s����(�L�E�ցE�M)", "���ʂ͂��҂�[", MB_OK);
		exit(0);
	}
}
static inline void DispSuccess()
{
	MessageBox(NULL, "����(�@�`�֥�L)\n", "���ʂ͂��҂�[", MB_OK);
	//�h�����̐i����i�߂�B
	AdvanceDrillProgress();
}