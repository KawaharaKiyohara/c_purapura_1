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
void KadaiGenerator::CheckAnswer(int b)
{
	//ここから、
	int b_ans = 0;
	for (int i = 0; i < 100; i++) {
		if (m_a[i] % 2 == 0 || m_a[i] % 3 == 0) {
			//a[i]が2の倍数かつ3の倍数なので、bに1を加算する。
			b_ans++;
		}
	}
	if (b_ans != b) {
		printf("間違っているよ(´・ω・｀)\n");
		return;
	}
	printf("課題クリア！！！\n");
}
