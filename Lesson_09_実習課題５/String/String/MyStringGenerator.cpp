#include "stdafx.h"
#include "MyStringGenerator.h"

MyStringGenerator::MyStringGenerator()
{
	std::random_device rd;
	m_mt.seed(rd());
}


MyStringGenerator::~MyStringGenerator()
{
}

/// <summary>
/// ������������_���ɐ�������B
/// </summary>
/// <returns></returns>
char* MyStringGenerator::RandomGenerate()
{
	int len = m_mt() % 8 + 1;
	auto str = std::make_unique<char[]>(len + 1);
	for (int i = 0; i < len; i++) {
		str[i] = 'A' + (char)(m_mt() % 26);
	}
	//�I�[��NULL������t�^������B
	str[len] = '\0';
	m_stringList.push_back(std::move(str));
	return m_stringList.back().get();
}
