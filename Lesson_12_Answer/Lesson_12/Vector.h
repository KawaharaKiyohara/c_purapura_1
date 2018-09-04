#pragma once
class Vector
{
public:
	Vector();
	~Vector();
	
	//ベクトルの各要素を表示する関数。
	void Display();

	//ベクトルの長さを求める関数。
	//戻り値　ベクトルの長さ。
	float Length();

	//ベクトルとスカラーの掛け算を行う。
	//引数　s ベクトルに乗算するスカラー。
	void Multiply( float s );
	

	void Div( float s );

	float x;
	float y;
	float z;
};

