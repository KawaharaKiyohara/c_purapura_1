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
/*!
*@brief	�o�C�i���T�����s���B
*@param[in]	values		�T�����s���z��B
*@param[in]	numalue		�z��̗v�f���B
*@param[in]	target		�����ΏۂƂȂ�l�B
*@return true���A���Ă�����A���������B
*/
bool BinarySearch(int value[], int numValues, int target)
{
	int left = 0;
	int right = numValues;
	int mid; 

	while (left <= right) {
		mid = (left + right) / 2; //left��right�̒��Ԃ��N�_�Ƃ���B
		if (value[mid] == target) {
			//���������B
			return true;
		}
		else if (value[mid] < target) { //value[mid]���ڕW�l�����������A�Ƃ������Ƃ�
										//mid��荶�̗v�f�́A���ׂ�value[mid]��菬�����̂ŁA�����������Ȃ��Ă悢�B
			left = mid + 1;
		}
		else {							//value[mid]���ڕW�l�����傫���A�Ƃ������Ƃ�
										//mid���E�̗v�f�́A���ׂ�value[mid]���傫���̂ŁA�����������Ȃ��Ă悢�B
			right = mid - 1; /* adjustment of right(end) key */
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
	//   27�s�ځ`��34�s�ڂ܂ł�100��J��Ԃ���郋�[�v�ł́A����A0�`1999999�̃����_���Ȑ����𐶐����āA   
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
		//�y��������T���̃v���O�����������z
		if (BinarySearch(values, 1000000, t) == true) {
			//���������B
			count++;
		}
	}

	//�������킹�B
	SubmissionAnswer(count);
	return 0;
}