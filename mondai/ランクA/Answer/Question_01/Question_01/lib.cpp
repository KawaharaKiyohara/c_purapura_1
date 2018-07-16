
#include "lib.h"


std::random_device rd;
std::mt19937 g_rand;
int seed;

const int RANK_NO = 3;
const int QUESTION_NO = 1;
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


int g_answer;
void GenerateInteger(int values[])
{
	seed = rd();
	g_rand.seed(seed);
	CheckRank();
	
	for (int i = 0; i < 1000000; i++) {
		values[i] = g_rand() % 2000000;
		
	}
	std::sort(values, values + 1000000, [](int l, int r) {
		return l < r;
	});
	g_answer = 0;
	for (int i = 0; i < 1000000; i++) {
		//�����_���ɒl�𐶐�����B
		int t = g_rand() % 2000000;
		bool result = std::binary_search(values, values + 1000000, t);
		if (result == true) {
			//���������B
			g_answer++;
		}

	}
	//���������Z�b�g�B
	g_rand.seed(seed);
	g_rand.discard(1000000);
}
void SubmissionAnswer(int answer)
{
	if (g_answer != answer) {
		MessageBox(NULL, "�s����(�L�E�ցE�M)", "���ʂ͂��҂�[", MB_OK);
	}
	else {
		MessageBox(NULL, "����(�@�`�֥�L)\n", "���ʂ͂��҂�[", MB_OK);
		AdvanceDrillProgress();
	}
}