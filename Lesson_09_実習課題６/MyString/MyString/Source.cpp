#include <iostream>
using namespace std;

int a = 30;

int main()
{
	int a = 10;
	{
		int a = 20;
		a += 20;
	}

	cout << ::a << "\n";

	return 0;
}