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
void KadaiGenerator::CheckAnswer(int b)
{
	//��������A
	int b_ans = 0;
	for (int i = 0; i < 100; i++) {
		if (m_a[i] % 2 == 0 || m_a[i] % 3 == 0) {
			//a[i]��2�̔{������3�̔{���Ȃ̂ŁAb��1�����Z����B
			b_ans++;
		}
	}
	if (b_ans != b) {
		printf("�Ԉ���Ă����(�L�E�ցE�M)\n");
		return;
	}
	printf("�ۑ�N���A�I�I�I\n");
}
