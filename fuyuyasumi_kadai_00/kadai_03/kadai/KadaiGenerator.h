#pragma once
# include <random>

class KadaiGenerator
{
public:
	KadaiGenerator();
	~KadaiGenerator();
	void Generate(int* a);
	void CheckAnswer(int total_2, int total_3, int total_5);
private:
	std::mt19937 m_mtRandom; //�����Z���k�c�C�X�^���g�p���������B
	int m_a[100];
};

