#pragma once
# include <random>

class KadaiGenerator
{
public:
	KadaiGenerator();
	~KadaiGenerator();
	void Generate(int* a);
	void CheckAnswer(int* b);
private:
	std::mt19937 m_mtRandom; //�����Z���k�c�C�X�^���g�p���������B
	int m_a[100];
};

