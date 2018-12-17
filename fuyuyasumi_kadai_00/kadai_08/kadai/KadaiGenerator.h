#pragma once
# include <random>

class KadaiGenerator
{
public:
	KadaiGenerator();
	~KadaiGenerator();
	void Generate(char* a);
	void CheckAnswer(int total_k, int total_b, int total_c);
private:
	std::mt19937 m_mtRandom; //メルセンヌツイスタを使用した乱数。
	char m_a[100];
};

