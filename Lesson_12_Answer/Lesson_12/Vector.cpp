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
	cout << "xの値は" << x << "です。\n";
	cout << "yの値は" << y << "です。\n";
	cout << "zの値は" << z << "です。\n";
}
float Vector::Length()
{
	//①　各要素の２乗の総和を求める。
	float t = x * x + y * y + z * z;
	//②　①で求めた値の平方根を求める。
	float length = sqrt(t);
	//③　長さが求まったので、長さを返す。
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