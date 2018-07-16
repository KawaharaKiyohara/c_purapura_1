#pragma once
#include <random>
#include <Windows.h>

struct AABB;

//ランクをチェックする。
void CheckRank();
void AdvanceDrillProgress();
void GenerateAABBs(AABB aabb[]);
void SubmissionAnswer(int ount);
