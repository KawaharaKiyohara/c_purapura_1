#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector()
{
}
Vector::~Vector()
{
}

void Vector::Display()
{
	cout << "x�̒l��" << x << "�ł��B\n";
	cout << "y�̒l��" << y << "�ł��B\n";
	cout << "z�̒l��" << z << "�ł��B\n";
}
float Vector::Length()
{
	//�@�@�e�v�f�̂Q��̑��a�����߂�B
	float t = x * x + y * y + z * z;
	//�A�@�@�ŋ��߂��l�̕����������߂�B
	float length = sqrt(t);
	//�B�@���������܂����̂ŁA������Ԃ��B
	return length;
}

void Vector::Multiply(float s)
{
	x *= s;
	y *= s;
	z *= s;
}
void Vector::Div(float s)
{
	x /= s;
	y /= s;
	z /= s;
}