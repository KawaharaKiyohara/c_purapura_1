#pragma once
#include <random>
#include <Windows.h>

struct UserAccountInfo;

//�����N���`�F�b�N����B
void CheckRank();
void AdvanceDrillProgress();
void GenerateUserAccountInfo(UserAccountInfo account[]);
void SubmissionAnswer(int answer);
