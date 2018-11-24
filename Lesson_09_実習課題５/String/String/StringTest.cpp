#include "stdafx.h"
#include <iostream>


/// <summary>
/// 文字列を表示
/// </summary>
/// <remarks>
/// 本関数内では標準ライブラリの関数はputchar関数のみ使用可能とする。
/// </remarks>
/// <param name="str"></param>
void MyPrint( const char* str )
{
}

/// <summary>
/// 文字列の長さを求める
/// </summary>
/// <remarks>
/// 本関数内では標準ライブラリのstrlenは使用不可とする。
/// </remarks>
/// <param name="str1">文字列</param>
/// <returns>文字列の長さ。NULL文字は含まない。</returns>
int MyStrlen(const char* str)
{
	return 0;
}

/// <summary>
/// 文字列をコピーする。
/// </summary>
/// <remarks>
/// srcに格納されている文字列をdstにコピーします。
/// dstはsrcをコピーできるだけの領域が十分に確保されているものとします。
/// また、本関数内では標準ライブラリのstrcpyは使用不可とする。
/// </remarks>
/// <param name="dst">コピー先</param>
/// <param name="src">コピー元</param>
void MyStrcpy(char* dst, const char* src)
{


}
/// <summary>
/// 文字列比較
/// </summary>
/// <remarks>
/// 本関数内では標準ライブラリのstrcmpは使用不可とする。
/// </remarks>
/// <param name="str1">文字列１</param>
/// <param name="str2">文字列２</param>
/// <returns>
/// str1とstr2が同じ文字列だったらtrueを返す。
/// str1とstr2が異なる文字列だったらfalseを返す。
/// </returns>
bool MyStrcmp(const char* str1, const char* str2)
{

	return false;
}
/// <summary>
/// 文字列連結
/// </summary>
/// <remarks>
/// str1の後ろにstr2が連結される。
/// 例えば、str1が"Hello"、str2が"World"の場合、
/// str1の後ろに"World"が追加されるので、
/// str1は"HelloWorld"という文字列になる。
/// 本関数内では標準ライブラリのstrcatは使用不可とする。
/// </remarks>
/// <param name="str1"></param>
/// <param name="str2"></param>
void MyStrcat(char* str1, const char* str2)
{
	
}