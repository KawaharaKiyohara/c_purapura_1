#define  _CRT_SECURE_NO_WARNINGS //おまじない。
#include "MyString.h"
#include <string>


MyString::MyString()
{
}


MyString::~MyString()
{
	//確保したメモリはちゃんと開放する！
	if (m_string != nullptr) {
		//m_stringにアドレスが入っていたら開放する。
		free(m_string);
	}
}

void MyString::operator=(const char* str)
{
	if (m_string != nullptr) {
		//m_stringにアドレスが入っていたら開放する。
		free(m_string);
	}
	//コピー元の文字列の長さを調べる。
	int len = strlen(str);

	//コピーすることが可能なメモリを動的に確保する。
	//malloc関数は確保するメモリのサイズを引数に受け取ります。
	//戻り値は、確保したメモリのアドレスを返してきます。
	m_string = (char*)malloc(len + 1);

	//文字列を確保したメモリにコピーする。
	strcpy(
		m_string,	//コピー先のメモリの先頭アドレス。
		str			//コピー元の文字列の先頭アドレス。
	);
}
void MyString::Copy(const char* str)
{
	if (m_string != nullptr) {
		//m_stringにアドレスが入っていたら開放する。
		free(m_string);
	}
	//コピー元の文字列の長さを調べる。
	int len = strlen(str);

	//コピーすることが可能なメモリを動的に確保する。
	//malloc関数は確保するメモリのサイズを引数に受け取ります。
	//戻り値は、確保したメモリのアドレスを返してきます。
	m_string = (char*)malloc( len + 1 );

	//文字列を確保したメモリにコピーする。
	strcpy(
		m_string,	//コピー先のメモリの先頭アドレス。
		str			//コピー元の文字列。
	);
}
void MyString::Add(const char* str)
{
	///////////////////////////////////////////////////// 
	//① 連結後の文字列の長さを計算する。
	///////////////////////////////////////////////////// 
	int len = strlen(str);
	//元の文字列の長さを加算する。
	len += strlen(m_string);

	/////////////////////////////////////////////////////
	//② 新しい文字列を記憶するための、メモリを確保する。
	/////////////////////////////////////////////////////
	char* newStr = (char*)malloc( len + 1 );

	/////////////////////////////////////////////////////
	//③ 文字列連結
	/////////////////////////////////////////////////////
	//まず、newStrにm_stringが指している文字列をコピーする。
	strcpy(newStr, m_string);
	//続いて文字列を連結させる。
	strcat(newStr,str);

	/////////////////////////////////////////////////////
	//④ m_stringが指している古い文字列を解放して、
	//   新しい文字列のアドレスを代入する。
	/////////////////////////////////////////////////////
	//古い文字列のアドレスを解放する。
	free(m_string);
	//m_string新しく確保した
	//文字列のアドレスを代入する。
	m_string = newStr;
}
//+=演算子をオーバーロード。
void MyString::operator+=(const char* str)
{
	///////////////////////////////////////////////////// 
	//① 連結後の文字列の長さを計算する。
	///////////////////////////////////////////////////// 
	int len = strlen(str);
	//元の文字列の長さを加算する。
	len += strlen(m_string);

	/////////////////////////////////////////////////////
	//② 新しい文字列を記憶するための、メモリを確保する。
	/////////////////////////////////////////////////////
	char* newStr = (char*)malloc(len + 1);

	/////////////////////////////////////////////////////
	//③ 文字列連結
	/////////////////////////////////////////////////////
	//まず、newStrにm_stringが指している文字列をコピーする。
	strcpy(newStr, m_string);
	//続いて文字列を連結させる。
	strcat(newStr, str);

	/////////////////////////////////////////////////////
	//④ m_stringが指している古い文字列を解放して、
	//   新しい文字列のアドレスを代入する。
	/////////////////////////////////////////////////////
	//古い文字列のアドレスを解放する。
	free(m_string);
	//m_string新しく確保した
	//文字列のアドレスを代入する。
	m_string = newStr;
}
//==演算子をオーバーロード。
bool MyString::operator==(const char* str)
{
	//文字列の比較はstrcmpを使う。
	int result = strcmp(m_string, str);

	if (result == 0) {
		//strcmpの戻り値が0なら文字列は等しいので、trueを返す。
		return true;
	}
	//ここに来たということは、等しくないということなので
	//falseを返す。
	return false;
}
/// <summary>
/// m_stringが指している文字列の長さを求める関数。
/// </summary>
/// <remarks>
/// m_stringが指している文字列が"Hello"であれば、5を返します。
/// m_stringが指している文字列が"Hello World"であれば10を返します。
/// </remarks>
/// <returns>m_stringが指している文字列の長さ</returns>
int MyString::Length()
{
	return strlen(m_string);
}

/// <summary>
/// m_stringが指している文字列から、引数で渡された
/// 文字(ch)がある位置を返す関数です。
/// 位置は一番最初に見つかった位置を返します。
/// なお、見つからなかった場合は-1を返してください。
/// </summary>
/// <remarks>
/// m_stringに"Hello"が設定されている場合に、
///		・chに'l'が渡された場合は2を返します。
///		・chに'H'が渡された場合は0を返します。
///		・chに'a'が渡された場合は-1を返します。
/// 　　　→見つからなかった。
/// </remarks>
/// <param name="ch">検索する文字</param>
/// <returns>
/// 文字が見つかった位置。
/// 見つからなかった場合は、-1を返します。
/// </returns>
int MyString::Search(char ch)
{
	//MyString::Length関数を使って、m_stringの長さを求める。
	int len = Length();
	//先頭から一文字づつ調べていく。
	for (int i = 0; i < len; i++) {
		if (m_string[i] == ch) {
			//見つかったので、位置を返す。
			return i;
		}
	}
	//ここに来たということは見つからなかった。
	return -1;
}
/// <summary>
/// m_stringが指している文字列に、指定された場所(insertPos)に指定された文字(ch)を挿入します。
/// </summary>
/// <remarks>
/// m_stringに"Hello"が設定されている場合に、
///		・insertPosに2、chに'a'が渡された場合は、m_stringが指している文字列は"Heallo"になります。
///		・insertPosに0、chに'b'が渡された場合は、m_stringが指している文字列は"bHello"になります。
/// </remarks>
/// <param name="insertPos"></param>
/// <param name="ch"></param>
void MyString::Insert(int insertPos, char ch)
{
	//古い文字列の長さを計算する。
	int len = strlen(m_string);
	//新しい文字列を記録するために必要なメモリを確保する。
	//ヌル文字＋追加の文字なので、＋２。
	char* newStr = (char*)malloc(strlen(m_string) + 2);
	int i = 0;
	for (i = 0; i < len; i++) {
		if (i < insertPos) {
			//挿入位置より手前はそのままコピー。
			newStr[i] = m_string[i];
		}
		else if (i >= insertPos) {
			//挿入位置と同じor挿入位置より後ろは、ずらしてコピー。
			newStr[i + 1] = m_string[i];
		}
	}
	//挿入位置にコピー。
	newStr[insertPos] = ch;
	//最後にヌル文字を追加して、m_stringが指している文字列のアドレスを変える。
	newStr[i+1] = '\0';
	if (m_string != nullptr) {
		free(m_string);
	}
	m_string = newStr;
	return;
}