#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "�����P����͂��Ă��������B\n";
	cin >> num1;
	cout << "�����Q����͂��Ă��������B\n";
	cin >> num2;
	//���ς����߂�B
	int avg = num1 + num2;	//�܂����v��avg�ɑ�����āB
	avg = avg / 2;			//avg��2�Ŋ��������ʂ�avg�ɑ������B

	cout << "�����P�Ɛ����Q�̕��ϒl��" << avg << "�ł��B\n";


	return 0;
}