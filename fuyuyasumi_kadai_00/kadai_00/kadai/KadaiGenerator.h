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
	std::mt19937 m_mtRandom; //メルセンヌツイスタを使用した乱数。
	int m_a;
	int m_b;
};

