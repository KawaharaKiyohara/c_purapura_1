
#include "lib.h"

//���ɂ����B
struct Date {
	int month;	//��
	int day;	//��
};

//���[�U�[�A�J�E���g�̏���\���\���́B
struct UserAccountInfo {
	int gender;		//���ʁB0�������A1���j���B
	int age;		//�N��B
	Date birthday;	//�a�����B
};

std::random_device rd;

const int RANK_NO = 1;

const char* saveFilePath = "../../../bin/progress.txt";
int questionNo;
int currentQuestionNo;
//�����N���`�F�b�N����B
void CheckRank()
{
	//�����N�A�b�v�����̓����N�`�F�b�N�͂��Ȃ��B
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

int g_answer_00;
int g_answer_01;
int g_answer_02;
void GenerateUserAccountInfo(UserAccountInfo account[])
{
	CheckRank();
	g_answer_00 = 0;
	g_answer_01 = 0;
	g_answer_02 = 0;
	std::mt19937 mt(rd());
	for (int i = 0; i < 100; i++) {
		account[i].gender = mt() % 2;
		account[i].age = mt() % 80;
		//�S�� or �V�����܂�̏����̐l�����J�E���g����B
		if (account[i].gender == 0) {
			if (account[i].birthday.day == 4
				|| account[i].birthday.day == 7
				) {
				g_answer_02++;
			}
		}
		//���l�����𒲂ׂ�B
		if (account[i].gender == 0 && account[i].age >= 20) {
			g_answer_01++;
		}
		//���l�j���𒲂ׂ�B
		if (account[i].gender == 1 && account[i].age >= 20) {
			g_answer_00++;
		}
	}
}
void SubmissionAnswer(int answer_00, int answer_01, int answer_02)
{
	if (g_answer_00 != answer_00
		|| g_answer_01 != answer_01
		|| g_answer_02 != answer_02
	) {
		MessageBox(NULL, "�s����(�L�E�ցE�M)", "���ʂ͂��҂�[", MB_OK);
	}
	else {
		MessageBox(NULL, "����(�@�`�֥�L)\n", "���ʂ͂��҂�[", MB_OK);
		AdvanceDrillProgress();
	}
}