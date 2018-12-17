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
		if (m_a[i] % 2 == 0) {
			//偶数。
			if (b[i] != 1) {
				printf("間違ってるよ(´・ω・｀)\n");
				return;
			}
		}
		else {
			//奇数。
			if (b[i] != 2) {
				printf("間違ってるよ(´・ω・｀)\n");
				return;
			}
		}
	}
	printf("課題クリア！！！\n");
}
