#pragma once
class MyString
{
public:
	MyString();
	~MyString();

	//代入演算子をオーバーロード。
	void operator=(const char* str);
	//文字列のコピーを行うメンバ関数。
	void Copy(const char* str);
	//文字列の連結を行うメンバ関数。
	//引き数のstrがm_stringの後ろに連結される。
	void Add(const char* str);
	//+=演算子をオーバーロード。
	void operator+=(const char* str);
	//==演算子をオーバーロード。
	bool operator==(const char* str);
	//m_stringが指している文字列の長さを求める関数。
	int Length();
	//m_stringが指している文字列から、chが記録されている
	//位置を検索する関数。
	int Search(char ch);
	//m_stringが指している文字列に文字を挿入する関数。
	void Insert(int insertPos, char ch);

	//文字列の先頭アドレスを記録するためのメンバ変数を追加する。
	//一応nullptrで初期化しておく。
	char* m_string = nullptr;	
};

