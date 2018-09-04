#include <iostream>
#include "Vector.h"
#include <random>

using namespace std;

int main()
{	
	//�񌈒�I�ȗ��������@�B
	//�x�N�g���̊e�v�f�������_���Ɍ��肷��Ƃ��Ɏg���̂��B
	random_device rd; 

	//�v�f��3�̃x�N�g���^�̔z����`����B
	Vector v[3];  
	
	for ( int i = 0; i < 3; i++ ) {
		//�x�N�g���̗v�f�𗐐������@���g���ă����_���Ɍ��肷��B
		//warning�ł邯�ǁA�C�ɂ��Ȃ��B
		//rd()�̓����_���Ȑ�����Ԃ��Ă��܂��B
		//�����āA�����_���ɐ�������������50�Ŋ������]����x�N�g���̊e�v�f��
		//������Ă���̂ŁA�x�N�g���̊e�v�f��0�`49�܂ł̒l�ƂȂ�܂��B
		v[i].x = rd() % 50;
		v[i].y = rd() % 50;
		v[i].z = rd() % 50;
		
		//v�̊e�v�f�Ƒ傫����\������B
		cout << "v[" << i << "]" << "�̒l�́H\n";
		v[i].Display();
		cout << "�傫���́A" << v[i].Length() << "�ł�\n";
		cout << "\n";
	}
	float maxLen = 0.0f;	//�ł��������������L�^���邽�߂̕ϐ��B
	float maxVectorNo = 0;	//�ł��傫���x�N�g���̔ԍ����L�^���邽�߂̕ϐ��B
	//��ԑ傫���x�N�g���𒲂ׂ邼���B
	for ( int i = 0; i < 3; i++ ) {
		//i�Ԗڂ̃x�N�g���̒������v�Z����B
		float len = v[i].Length();
		if ( maxLen < len ) {
			//���̃x�N�g���̕����傫���̂ŁA
			//maxLen��maxVectorNo���㏑������B
			maxLen = len;
			maxVectorNo = i;
		}
	}
	cout << "�ł��傫���x�N�g����" << maxVectorNo << "�Ԗڂł��B\n";

	float minLen = FLT_MAX;	//�ł��������������L�^���邽�߂̕ϐ��B
	float minVectorNo = 0;	//�ł��������x�N�g���̔ԍ����L�^���邽�߂̕ϐ��B

	//��ԏ������x�N�g���𒲂ׂ邼���B
	for (int i = 0; i < 3; i++) {
		//i�Ԗڂ̃x�N�g���̒������v�Z����B
		float len = v[i].Length();
		if (minLen > len) {
			//���̃x�N�g���̕����������̂ŁA
			//minLen��minVectorNo���㏑������B
			minLen = len;
			minVectorNo = i;
		}
	}

	cout << "�ł��������x�N�g����" << minVectorNo << "�Ԗڂł��B\n";

	return 0;
}