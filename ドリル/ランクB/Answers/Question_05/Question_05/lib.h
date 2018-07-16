#pragma once
#include <random>
#include <Windows.h>

struct Sphere;

//ランクをチェックする。
void CheckRank();
void AdvanceDrillProgress();
void GenerateSpheres(Sphere aabb[]);
void SubmissionAnswer(int ount);
