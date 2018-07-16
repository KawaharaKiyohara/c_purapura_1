#pragma once
#include <random>
#include <Windows.h>

struct Vector2;

//ランクをチェックする。
void CheckRank();
void AdvanceDrillProgress();
void GeneratePositions(Vector2 positions[]);
void SubmissionAnswer(int answer);
