#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;

extern std::mt19937 g_rand;

/*!
 *@brief	���`�T�����s���B
 *@param[in]	values		�T�����s���z��B
 *@param[in]	numalue		�z��̗v�f���B
 *@param[in]	target		�����ΏۂƂȂ�l�B
 *@return true���A���Ă�����A���������B
 */
bool LinearSearch( int values[], int numValue, int target )
{
	//�����ɐ��`�T�������Ă݂悤�B
	for (int i= 0; i < numValue; i++) {
		if (target == values[i]) {
			//���������B
			return true;
		}
	}
	//������Ȃ������B
	return false;
}

int main()
{
	//�y���z
	//   �����_���ɐ������ꂽ1000000�̐����l�̏W���ɁA�ړI�̐��l���܂܂�Ă��邩��1000000�񒲂ׂ�B
	//�y�v���O�����̉���z
	//   GenerateInteger�֐��̓����_����1000000�̐����l���쐬���āA�����value�z��Ɋi�[���܂��B
	//   �܂��A���̔z��͏����Ƀ\�[�g����Ă��܂��B
	//   50�s�ځ`��63�s�ڂ܂ł�1000000��J��Ԃ���郋�[�v�ł́A����A0�`1999999�̃����_���Ȑ����𐶐����āA   
	//�@ �ϐ�t�ɑ�����Ă��܂��B���̕ϐ�t�̒l���z��values�Ɋ܂܂�Ă��邩�ǂ������A���񒲂ׂāA
	//�@ �܂܂�Ă���ꍇ��count���C���N�������g���Ȃ����B�܂��At�̒l��values�Ɋ܂܂�Ă��邱�Ƃ��킩������A
	//�@ �����Ɏ��̒T���Ɉڍs���Ă��������B�܂�A�P��̒T����count�̒l�͍ő��1�������Z����܂���B
	//�@ �܂��A�T���̃A���S���Y���ɐ��`�T�����s�����ꍇ�A����1000000�~500000��̌v�Z���s���邽��
	//   ���Ɏ��Ԃ��������Ă��܂��܂��B�����ȒT���A���S���Y���Ƃ��āA�o�C�i���[�T�[�`������܂��B
	//   �o�C�i���T�[�`�̃A���S���Y���͉��L��URL���Q�Ƃ��Ă��������B
	//   https://www.codereading.com/algo_and_ds/algo/binary_search.html

	static int values[1000000];
	GenerateInteger(values);

	int count = 0;
	//
	for (int i = 0; i < 1000000; i++) {
		//�����_���ɒl�𐶐�����B
		int t = g_rand() % 2000000;
		//���̃R�����g�A�E�g���O���ƁA���`�T�����g���Ď��������o�[�W������������B
		//�ǂꂭ�炢���Ԃ������邩�m�F���Ă݂悤�B
		/*if (LinearSearch(values, 1000000, t) == true) {
			//���������B
			count++;
		}*/
		//*******************************************************
		//�y��������T���̃v���O�����������z
		//*******************************************************

	}

	//�������킹�B
	SubmissionAnswer(count);
	return 0;
}