#pragma once
class Vector
{
public:
	Vector();
	~Vector();
	
	//�x�N�g���̊e�v�f��\������֐��B
	void Display();

	//�x�N�g���̒��������߂�֐��B
	//�߂�l�@�x�N�g���̒����B
	float Length();

	//�x�N�g���ƃX�J���[�̊|���Z���s���B
	//�����@s �x�N�g���ɏ�Z����X�J���[�B
	void Multiply( float s );
	

	void Div( float s );

	float x;
	float y;
	float z;
};

