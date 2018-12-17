#include "pch.h"
#include "KadaiGenerator.h"


KadaiGenerator::KadaiGenerator()
{
	std::random_device rd;
	//乱数を初期化。
	m_mtRandom.seed(rd());
}


KadaiGenerator::~KadaiGenerator()
{
}
void KadaiGenerator::Generate(int* a)
{
	for (int i = 0; i < 100; i++) {
		a[i] = m_mtRandom() % 1000;
		m_a[i] = a[i];
	}
}
void KadaiGenerator::CheckAnswer(int total_2, int total_3, int total_5)
{
	int total_2_ans, total_3_ans, total_5_ans;
	total_2_ans = total_3_ans = total_5_ans = 0;

	for (int i = 0; i < 100; i++) {
		if (m_a[i] % 2 == 0) {
			total_2_ans += m_a[i];
		}
		if (m_a[i] % 3 == 0) {
			total_3_ans += m_a[i];
		}
		if (m_a[i] % 5 == 0) {
			total_5_ans += m_a[i];
		}
	}
	if (total_2_ans != total_2
		|| total_3_ans != total_3
		|| total_5_ans != total_5) {
		printf("間違っているよ(´・ω・｀)\n");
		return;
	}
	printf("課題クリア！！！\n");
}
