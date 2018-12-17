#include "pch.h"
#include "KadaiGenerator.h"


KadaiGenerator::KadaiGenerator()
{
	std::random_device rd;
	//�������������B
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
			//2�̔{��
			total += 2;
		}
		if (m_a[i] % 3 == 0) {
			//3�̔{���B
			total += 3;
		}
		if (m_a[i] % 5 == 0) {
			//5�̔{���B
			total += 5;
		}
		if (b[i] != total) {
			printf("�Ԉ���Ă����(�L�E�ցE�M)\n");
			return;
		}
	}
	printf("�ۑ�N���A�I�I�I\n");
}
