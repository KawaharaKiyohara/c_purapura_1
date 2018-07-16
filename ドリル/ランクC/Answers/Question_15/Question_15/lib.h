#pragma once
#include <random>
#include <Windows.h>

struct UserAccountInfo;

//ランクをチェックする。
void CheckRank();
void AdvanceDrillProgress();
void GenerateUserAccountInfo(UserAccountInfo account[]);
void SubmissionAnswer(int answer_00, int answer_01, int answer_02);
