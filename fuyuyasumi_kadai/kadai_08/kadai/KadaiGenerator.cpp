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
void KadaiGenerator::CheckAnswer(int total_k, int total_b, int total_c)
{
	int total_k_a, total_b_a, total_c_a;
	total_k_a = total_b_a = total_c_a = 0;

	for (int i = 0; i < 100; i++) {
		if (m_a[i] == 'k') {
			total_k_a++;
		}
		if (m_a[i] == 'b') {
			total_b_a++;
		}
		if (m_a[i] == 'c') {
			total_c_a++;
		}
		if (m_a[i] == 'z') {
			total_k_a -= 10;
			total_b_a -= 10;
			total_c_a -= 10;
		}
	}
	if (total_k == total_k_a
		&& total_b == total_b_a
		&& total_c == total_c_a) {
		printf("�ۑ�N���A�I�I�I\n");
	}
	else {
		printf("�Ԉ���Ă����(�L�E�ցE�M)\n");
	}
}
