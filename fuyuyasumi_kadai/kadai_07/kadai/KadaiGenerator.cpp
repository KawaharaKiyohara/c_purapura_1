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
	//��������A

	for (int i = 0; i < 100; i++) {
		if (m_a[i] == 'k' || m_a[i] == 'b' || m_a[i] == 'c') {
			if (b[i] != 1) {
				printf("�Ԉ���Ă����(�L�E�ցE�M)\n");
				return;
			}
		}
		else {
			if (b[i] != 2) {
				printf("�Ԉ���Ă����(�L�E�ցE�M)\n");
				return;
			}
		}
	}
	
	printf("�ۑ�N���A�I�I�I\n");
}
