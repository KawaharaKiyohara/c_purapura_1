#include "stdafx.h"
#include <iostream>

/// <summary>
/// �������\��
/// </summary>
/// <remarks>
/// �{�֐����ł͕W�����C�u�����̊֐���putchar�֐��̂ݎg�p�\�Ƃ���B
/// </remarks>
/// <param name="str"></param>
void MyPrint( const char* str )
{
	for (int i = 0; str[i] != '\0'; i++) {
		putchar(str[i]);
	}
}

/// /// <summary>
/// ������̒��������߂�
/// </summary>
/// <param name="str1">������</param>
/// <returns>������̒����BNULL�����͊܂܂Ȃ��B</returns>
int MyStrlen(const char* str)
{
	int len = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		len++;
	}
	return len;
}
/// <summary>
/// ��������R�s�[����B
/// </summary>
/// <remarks>
/// src�Ɋi�[����Ă��镶�����dst�ɃR�s�[���܂��B
/// dst��src���R�s�[�ł��邾���̗̈悪�\���Ɋm�ۂ���Ă�����̂Ƃ��܂��B
/// </remarks>
/// <param name="dst">�R�s�[��</param>
/// <param name="src">�R�s�[��</param>
void MyStrcpy(char* dst, const char* src)
{
	int i = 0;
	for (; src[i] != '\0'; i++) {
		dst[i] = src[i];
	}
	//�I�[�����𖄂ߍ��ށB
	dst[i] = '\0';
}
/// <summary>
/// �������r
/// </summary>
/// <param name="str1">������P</param>
/// <param name="str2">������Q</param>
/// <returns>
/// str1��str2�����������񂾂�����true��Ԃ��B
/// str1��str2���قȂ镶���񂾂�����false��Ԃ��B
/// </returns>
bool MyStrcmp(const char* str1, const char* str2)
{
	int len = (int)strlen(str1);
	if (len != (int)strlen(str2)) {
		//�������Ⴄ���_�ňႤ�B
		return false;
	}
	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i]) {
			//�Ⴄ���������ꂽ�B
			return false;
		}
	}
	//�����B
	return true;
}
/// <summary>
/// ������A��
/// </summary>
/// <remarks>
/// str1�̌���str2���A�������B
/// �Ⴆ�΁Astr1��"Hello"�Astr2��"World"�̏ꍇ�A
/// str1�̌���"World"���ǉ������̂ŁA
/// str1��"HelloWorld"�Ƃ���������ɂȂ�B
/// </remarks>
/// <param name="str1"></param>
/// <param name="str2"></param>
void MyStrcat(char* str1, const char* str2)
{
	int len = strlen(str1);
	int i = 0;
	for (; str2[i] != '\0'; i++) {
		str1[len + i] = str2[i];
	}
	//������̏I�[��NULL������ǉ�����B
	str1[len + i] = '\0';
}