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
void KadaiGenerator::Generate(char* a)
{
	for (int i = 0; i < 100; i++) {
		a[i] = 'a' + m_mtRandom() % 26;
		m_a[i] = a[i];
	}
}
void KadaiGenerator::CheckAnswer(int* b)
{
	

	for (int i = 0; i < 100; i++) {
		char ans = m_a[i] - 'a' + 1;
		if (ans != b[i]) {
			printf("�Ԉ���Ă����(�L�E�ցE�M)\n");
			return;
		}
	}
	printf("�ۑ�N���A�I�I�I\n");
}
