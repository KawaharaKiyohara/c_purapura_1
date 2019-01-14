#define  _CRT_SECURE_NO_WARNINGS //���܂��Ȃ��B
#include "MyString.h"
#include <string>


MyString::MyString()
{
}


MyString::~MyString()
{
	//�m�ۂ����������͂����ƊJ������I
	if (m_string != nullptr) {
		//m_string�ɃA�h���X�������Ă�����J������B
		free(m_string);
	}
}

void MyString::operator=(const char* str)
{
	if (m_string != nullptr) {
		//m_string�ɃA�h���X�������Ă�����J������B
		free(m_string);
	}
	//�R�s�[���̕�����̒����𒲂ׂ�B
	int len = strlen(str);

	//�R�s�[���邱�Ƃ��\�ȃ������𓮓I�Ɋm�ۂ���B
	//malloc�֐��͊m�ۂ��郁�����̃T�C�Y�������Ɏ󂯎��܂��B
	//�߂�l�́A�m�ۂ����������̃A�h���X��Ԃ��Ă��܂��B
	m_string = (char*)malloc(len + 1);

	//��������m�ۂ����������ɃR�s�[����B
	strcpy(
		m_string,	//�R�s�[��̃������̐擪�A�h���X�B
		str			//�R�s�[���̕�����̐擪�A�h���X�B
	);
}
void MyString::Copy(const char* str)
{
	if (m_string != nullptr) {
		//m_string�ɃA�h���X�������Ă�����J������B
		free(m_string);
	}
	//�R�s�[���̕�����̒����𒲂ׂ�B
	int len = strlen(str);

	//�R�s�[���邱�Ƃ��\�ȃ������𓮓I�Ɋm�ۂ���B
	//malloc�֐��͊m�ۂ��郁�����̃T�C�Y�������Ɏ󂯎��܂��B
	//�߂�l�́A�m�ۂ����������̃A�h���X��Ԃ��Ă��܂��B
	m_string = (char*)malloc( len + 1 );

	//��������m�ۂ����������ɃR�s�[����B
	strcpy(
		m_string,	//�R�s�[��̃������̐擪�A�h���X�B
		str			//�R�s�[���̕�����B
	);
}
void MyString::Add(const char* str)
{
	///////////////////////////////////////////////////// 
	//�@ �A����̕�����̒������v�Z����B
	///////////////////////////////////////////////////// 
	int len = strlen(str);
	//���̕�����̒��������Z����B
	len += strlen(m_string);

	/////////////////////////////////////////////////////
	//�A �V������������L�����邽�߂́A���������m�ۂ���B
	/////////////////////////////////////////////////////
	char* newStr = (char*)malloc( len + 1 );

	/////////////////////////////////////////////////////
	//�B ������A��
	/////////////////////////////////////////////////////
	//�܂��AnewStr��m_string���w���Ă��镶������R�s�[����B
	strcpy(newStr, m_string);
	//�����ĕ������A��������B
	strcat(newStr,str);

	/////////////////////////////////////////////////////
	//�C m_string���w���Ă���Â��������������āA
	//   �V����������̃A�h���X��������B
	/////////////////////////////////////////////////////
	//�Â�������̃A�h���X���������B
	free(m_string);
	//m_string�V�����m�ۂ���
	//������̃A�h���X��������B
	m_string = newStr;
}
//+=���Z�q���I�[�o�[���[�h�B
void MyString::operator+=(const char* str)
{
	///////////////////////////////////////////////////// 
	//�@ �A����̕�����̒������v�Z����B
	///////////////////////////////////////////////////// 
	int len = strlen(str);
	//���̕�����̒��������Z����B
	len += strlen(m_string);

	/////////////////////////////////////////////////////
	//�A �V������������L�����邽�߂́A���������m�ۂ���B
	/////////////////////////////////////////////////////
	char* newStr = (char*)malloc(len + 1);

	/////////////////////////////////////////////////////
	//�B ������A��
	/////////////////////////////////////////////////////
	//�܂��AnewStr��m_string���w���Ă��镶������R�s�[����B
	strcpy(newStr, m_string);
	//�����ĕ������A��������B
	strcat(newStr, str);

	/////////////////////////////////////////////////////
	//�C m_string���w���Ă���Â��������������āA
	//   �V����������̃A�h���X��������B
	/////////////////////////////////////////////////////
	//�Â�������̃A�h���X���������B
	free(m_string);
	//m_string�V�����m�ۂ���
	//������̃A�h���X��������B
	m_string = newStr;
}
//==���Z�q���I�[�o�[���[�h�B
bool MyString::operator==(const char* str)
{
	//������̔�r��strcmp���g���B
	int result = strcmp(m_string, str);

	if (result == 0) {
		//strcmp�̖߂�l��0�Ȃ當����͓������̂ŁAtrue��Ԃ��B
		return true;
	}
	//�����ɗ����Ƃ������Ƃ́A�������Ȃ��Ƃ������ƂȂ̂�
	//false��Ԃ��B
	return false;
}
/// <summary>
/// m_string���w���Ă��镶����̒��������߂�֐��B
/// </summary>
/// <remarks>
/// m_string���w���Ă��镶����"Hello"�ł���΁A5��Ԃ��܂��B
/// m_string���w���Ă��镶����"Hello World"�ł����10��Ԃ��܂��B
/// </remarks>
/// <returns>m_string���w���Ă��镶����̒���</returns>
int MyString::Length()
{
	return strlen(m_string);
}

/// <summary>
/// m_string���w���Ă��镶���񂩂�A�����œn���ꂽ
/// ����(ch)������ʒu��Ԃ��֐��ł��B
/// �ʒu�͈�ԍŏ��Ɍ��������ʒu��Ԃ��܂��B
/// �Ȃ��A������Ȃ������ꍇ��-1��Ԃ��Ă��������B
/// </summary>
/// <remarks>
/// m_string��"Hello"���ݒ肳��Ă���ꍇ�ɁA
///		�Ech��'l'���n���ꂽ�ꍇ��2��Ԃ��܂��B
///		�Ech��'H'���n���ꂽ�ꍇ��0��Ԃ��܂��B
///		�Ech��'a'���n���ꂽ�ꍇ��-1��Ԃ��܂��B
/// �@�@�@��������Ȃ������B
/// </remarks>
/// <param name="ch">�������镶��</param>
/// <returns>
/// ���������������ʒu�B
/// ������Ȃ������ꍇ�́A-1��Ԃ��܂��B
/// </returns>
int MyString::Search(char ch)
{
	//MyString::Length�֐����g���āAm_string�̒��������߂�B
	int len = Length();
	//�擪����ꕶ���Â��ׂĂ����B
	for (int i = 0; i < len; i++) {
		if (m_string[i] == ch) {
			//���������̂ŁA�ʒu��Ԃ��B
			return i;
		}
	}
	//�����ɗ����Ƃ������Ƃ͌�����Ȃ������B
	return -1;
}
/// <summary>
/// m_string���w���Ă��镶����ɁA�w�肳�ꂽ�ꏊ(insertPos)�Ɏw�肳�ꂽ����(ch)��}�����܂��B
/// </summary>
/// <remarks>
/// m_string��"Hello"���ݒ肳��Ă���ꍇ�ɁA
///		�EinsertPos��2�Ach��'a'���n���ꂽ�ꍇ�́Am_string���w���Ă��镶�����"Heallo"�ɂȂ�܂��B
///		�EinsertPos��0�Ach��'b'���n���ꂽ�ꍇ�́Am_string���w���Ă��镶�����"bHello"�ɂȂ�܂��B
/// </remarks>
/// <param name="insertPos"></param>
/// <param name="ch"></param>
void MyString::Insert(int insertPos, char ch)
{
	//�Â�������̒������v�Z����B
	int len = strlen(m_string);
	//�V������������L�^���邽�߂ɕK�v�ȃ��������m�ۂ���B
	//�k�������{�ǉ��̕����Ȃ̂ŁA�{�Q�B
	char* newStr = (char*)malloc(strlen(m_string) + 2);
	int i = 0;
	for (i = 0; i < len; i++) {
		if (i < insertPos) {
			//�}���ʒu����O�͂��̂܂܃R�s�[�B
			newStr[i] = m_string[i];
		}
		else if (i >= insertPos) {
			//�}���ʒu�Ɠ���or�}���ʒu�����́A���炵�ăR�s�[�B
			newStr[i + 1] = m_string[i];
		}
	}
	//�}���ʒu�ɃR�s�[�B
	newStr[insertPos] = ch;
	//�Ō�Ƀk��������ǉ����āAm_string���w���Ă��镶����̃A�h���X��ς���B
	newStr[i+1] = '\0';
	if (m_string != nullptr) {
		free(m_string);
	}
	m_string = newStr;
	return;
}