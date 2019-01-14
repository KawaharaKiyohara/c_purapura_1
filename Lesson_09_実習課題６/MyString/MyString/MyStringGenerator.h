#pragma once
#include <vector>
#include <memory>
#include <random>

/// <summary>
/// �����_���ȕ�����𐶐�����N���X�B
/// </summary>
class MyStringGenerator
{
public:
	MyStringGenerator();
	~MyStringGenerator();
	/// <summary>
	/// ������������_���ɐ�������B
	/// </summary>
	/// <returns></returns>
	char* RandomGenerate();
private:
	std::mt19937 m_mt;
	std::vector<std::unique_ptr<char[]>> m_stringList;
};

