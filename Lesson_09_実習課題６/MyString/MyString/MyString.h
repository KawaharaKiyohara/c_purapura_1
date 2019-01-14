#pragma once
class MyString
{
public:
	MyString();
	~MyString();

	//������Z�q���I�[�o�[���[�h�B
	void operator=(const char* str);
	//������̃R�s�[���s�������o�֐��B
	void Copy(const char* str);
	//������̘A�����s�������o�֐��B
	//��������str��m_string�̌��ɘA�������B
	void Add(const char* str);
	//+=���Z�q���I�[�o�[���[�h�B
	void operator+=(const char* str);
	//==���Z�q���I�[�o�[���[�h�B
	bool operator==(const char* str);
	//m_string���w���Ă��镶����̒��������߂�֐��B
	int Length();
	//m_string���w���Ă��镶���񂩂�Ach���L�^����Ă���
	//�ʒu����������֐��B
	int Search(char ch);
	//m_string���w���Ă��镶����ɕ�����}������֐��B
	void Insert(int insertPos, char ch);

	//������̐擪�A�h���X���L�^���邽�߂̃����o�ϐ���ǉ�����B
	//�ꉞnullptr�ŏ��������Ă����B
	char* m_string = nullptr;	
};

