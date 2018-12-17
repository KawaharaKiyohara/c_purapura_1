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
void KadaiGenerator::CheckAnswer(int* b)
{
	for (int i = 0; i < 100; i++) {
		int total = 0;
		if (m_a[i] % 2 == 0) {
			//2の倍数
			total += 2;
		}
		if (m_a[i] % 3 == 0) {
			//3の倍数。
			total += 3;
		}
		if (m_a[i] % 5 == 0) {
			//5の倍数。
			total += 5;
		}
		if (b[i] != total) {
			printf("間違っているよ(´・ω・｀)\n");
			return;
		}
	}
	printf("課題クリア！！！\n");
}
