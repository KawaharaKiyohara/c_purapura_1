#pragma once
#include <vector>
#include <memory>
#include <random>

/// <summary>
/// ランダムな文字列を生成するクラス。
/// </summary>
class MyStringGenerator
{
public:
	MyStringGenerator();
	~MyStringGenerator();
	/// <summary>
	/// 文字列をランダムに生成する。
	/// </summary>
	/// <returns></returns>
	char* RandomGenerate();
private:
	std::mt19937 m_mt;
	std::vector<std::unique_ptr<char[]>> m_stringList;
};

