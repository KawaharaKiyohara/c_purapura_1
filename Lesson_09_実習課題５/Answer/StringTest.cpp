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
	for (int i = 0; str[i] != '\0'; i++) {
		putchar(str[i]);
	}
}

/// /// <summary>
/// 文字列の長さを求める
/// </summary>
/// <param name="str1">文字列</param>
/// <returns>文字列の長さ。NULL文字は含まない。</returns>
int MyStrlen(const char* str)
{
	int len = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		len++;
	}
	return len;
}
/// <summary>
/// 文字列をコピーする。
/// </summary>
/// <remarks>
/// srcに格納されている文字列をdstにコピーします。
/// dstはsrcをコピーできるだけの領域が十分に確保されているものとします。
/// </remarks>
/// <param name="dst">コピー先</param>
/// <param name="src">コピー元</param>
void MyStrcpy(char* dst, const char* src)
{
	int i = 0;
	for (; src[i] != '\0'; i++) {
		dst[i] = src[i];
	}
	//終端文字を埋め込む。
	dst[i] = '\0';
}
/// <summary>
/// 文字列比較
/// </summary>
/// <param name="str1">文字列１</param>
/// <param name="str2">文字列２</param>
/// <returns>
/// str1とstr2が同じ文字列だったらtrueを返す。
/// str1とstr2が異なる文字列だったらfalseを返す。
/// </returns>
bool MyStrcmp(const char* str1, const char* str2)
{
	int len = (int)strlen(str1);
	if (len != (int)strlen(str2)) {
		//長さが違う時点で違う。
		return false;
	}
	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i]) {
			//違う文字が現れた。
			return false;
		}
	}
	//同じ。
	return true;
}
/// <summary>
/// 文字列連結
/// </summary>
/// <remarks>
/// str1の後ろにstr2が連結される。
/// 例えば、str1が"Hello"、str2が"World"の場合、
/// str1の後ろに"World"が追加されるので、
/// str1は"HelloWorld"という文字列になる。
/// </remarks>
/// <param name="str1"></param>
/// <param name="str2"></param>
void MyStrcat(char* str1, const char* str2)
{
	int len = strlen(str1);
	int i = 0;
	for (; str2[i] != '\0'; i++) {
		str1[len + i] = str2[i];
	}
	//文字列の終端にNULL文字を追加する。
	str1[len + i] = '\0';
}