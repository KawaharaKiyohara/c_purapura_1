#pragma once
# include <random>

class KadaiGenerator
{
public:
	KadaiGenerator();
	~KadaiGenerator();
	void Generate(int& a, int& b);
	void CheckAnswer(int add, int sub, int mul, int div, int sur);
private:
	std::mt19937 m_mtRandom; //�����Z���k�c�C�X�^���g�p���������B
	int m_a;
	int m_b;
};

