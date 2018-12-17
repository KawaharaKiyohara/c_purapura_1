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
void KadaiGenerator::Generate(int& a, int& b)
{
	a = m_mtRandom() % 1000;
	b = m_mtRandom() % 10;
	m_a = a;
	m_b = b;
}
void KadaiGenerator::CheckAnswer(int add, int sub, int mul, int div, int sur)
{
	bool success = true;
	if (add != (m_a + m_b)) {
		printf("�����Z�̌��ʂ��Ԉ���Ă��܂��B\n");
		success = false;
	}
	if(sub != (m_a - m_b)) {
		printf("�����Z�̌��ʂ��Ԉ���Ă��܂��B\n");
		success = false;
	}
	if (mul != (m_a * m_b)) {
		printf("�|���Z�̌��ʂ��Ԉ���Ă��܂��B\n");
		success = false;
	}
	if (div != (m_a / m_b)) {
		printf("����Z�̌��ʂ��Ԉ���Ă��܂��B\n");
		success = false;
	}
	if (sur != (m_a % m_b)) {
		printf("�������]��̌��ʂ��Ԉ���Ă��܂��B\n");
		success = false;
	}
	if (success == true) {
		printf("�ۑ�N���A�I�I�I\n");
	}
}
