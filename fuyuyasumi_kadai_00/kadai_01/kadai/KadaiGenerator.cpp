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
		if (m_a[i] % 2 == 0) {
			//�����B
			if (b[i] != 1) {
				printf("�Ԉ���Ă��(�L�E�ցE�M)\n");
				return;
			}
		}
		else {
			//��B
			if (b[i] != 2) {
				printf("�Ԉ���Ă��(�L�E�ցE�M)\n");
				return;
			}
		}
	}
	printf("�ۑ�N���A�I�I�I\n");
}
