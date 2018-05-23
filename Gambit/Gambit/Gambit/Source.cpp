#include <iostream>
#include "consoleLib.h"
#include <time.h>
#include <stdlib.h>


using namespace std;
//////////////////////////////////////////////////////
// �\���̂Ȃ�
//////////////////////////////////////////////////////

/*!
*@brief	�L�����N�^�[�\���́B
*@details	�L�����N�^�[�̃p�����[�^����ɂ܂Ƃ߂āA�V�����^�Ƃ��܂��B
*/
struct Character {
	string	name;				//���O�B
	int		maxHP;				//�ő�q�b�g�|�C���g�B
	int		hp;					//�q�b�g�|�C���g�B
	int		mp;					//�}�W�b�N�|�C���g�B
	int		atk;				//�U���́B
	int		def;				//�h��́B
	float	hate;				//�w�C�g�B	���̒l�������قǁA�G�ɑ_���₷���Ȃ�܂��B
	int		buffCount;			//�o�t�J�E���g�B	�X�N���g�A�o�C�L���g��������ƁA�J�E���g���T�ɂȂ�܂��B�O�ɂȂ�ƃo�t���؂�܂��B
	int		tensinoInori = 0;	//�V�g�̋F�肪�������Ă��邩�ǂ����B���ꂪ�������Ă���ꍇ�B���S���Ă��������܂��B�q�[���[�̂ݎg�p�\�B
	int		commandCount = 2;	//1�^�[���ōs����s�����B�������m�͂R��s����B
	int		baseAtk;	//��{�U���́B
	int		baseDef;	//��{�h��́B
};

#include "AICommand.h"


/*----------------------------------------------------------------------
//�q�[���[���g�p�ł���֐��錾�̈ꗗ�B
----------------------------------------------------------------------*/
/*!
 *@brief	�U������B
 *@param[in]	siro	�������m
 *@param[in]	target	�U���Ώۂ̃L�����N�^�B
 */
void CommandAttack(Character& siro, Character& target);
/*!
 *@brief	��������B
 *@details
 * �w�C�g�����܂��āA��������_���₷���Ȃ�܂��B
 *@param[in]	siro	�������m
 *@param[in]	target	�U���Ώۂ̃L�����N�^�B
 */
void CommandChouhatu(Character& siro);
/*!
 *@brief	�V��
 *@details
 * �H�H�H�H�H�H
 *@param[in]	siro	�������m
 */
void CommandAsobu(Character& siro);
/*!
 *@brief	�z�C�~(�񕜎���)��������B
 *@param[in]	siro	�������m
 *@param[in]	target	���@��������ΏہB
 */
void CommandHoimi(Character& siro, Character& target);
/*!
 *@brief	�X�N���g(�h��̓A�b�v����)��������B
 *@param[in]	siro	�������m
 *@param[in]	target	���@��������ΏہB
 */
void CommandSukuruto(Character& siro, Character& target);
/*!
 *@brief	�U�I���N(�h������)��������B
 *@param[in]	siro	�������m
 *@param[in]	target	���@��������ΏہB
 */
void CommandZaoriku(Character& siro, Character& target);
/*!
 *@brief	�o�C�L���g(�U���̓A�b�v����)��������B
 *@param[in]	siro	�������m
 *@param[in]	target	���@��������ΏہB
 */
void CommandBaikiruto(Character& siro, Character& target);
/*!
 *@brief	�V�g�̋F���������B
 *@details
 * �������m���g�ɂ��������邱�Ƃ��Ȃ��A����ȋF��B
 * ��x�������S���Ă������I�ɑh������A�������m�̉��`�B
 *@param[in]	siro	�������m
 */
void CommandTenshiNoInori(Character& siro);


/*----------------------------------------------------------------------
//���C���֐��B
----------------------------------------------------------------------*/
int main()
{
	//�������������B
	srand((unsigned)time(NULL));

	//�^�[�����B
	int turnNo = 1;
	//�R�}���h�I��������H 1 �ŃR�}���h�I��
	int isSelectCommand = 1;
	//���R�m(DPS)�B�����[�T���B
	//���R�m�͑ϋv�͂����ȖڂŁA�U���͂������B
	Character ryu_san;

	//�����Đ�m(�^���N)�B
	//�펀�͑ϋv�͂����߂����A�U���͂͒Ⴂ�B
	Character sensi;

	//�����Ĕ������m(�q�[���[)
	//�ϋv�̓����[�T����荂�߂����A�펀���Ⴂ�B
	//�B��̃q�[���[�B
	Character siro;

	//�Ō�ɖ����l�B
	Character zoma;

	//�L�����̃X�e�[�^�X������������B
	InitCharacterState(ryu_san, sensi, siro, zoma);

	//��������Q�[�����[�v�B
	while (true) {
		//1�t���[���̊J�n�B
		kbcBeginFrame();
		//�w�i��`��B
		DrawBackground();

		//�L�����N�^�[�̃X�e�[�^�X��`��B
		DrawCharacterStateAll(ryu_san, sensi, siro, zoma, turnNo);
		
		//���Ԃɂ��L�����N�^�[�̃X�e�[�^�X�̍X�V�����B
		UpdateCharacterState(sensi, ryu_san, siro, zoma);
		
		
		if (isSelectCommand == 1 && zoma.hp > 0) {
			//�`�h���R�}���h��I�𒆁B
			//������AI
			AIMaou(zoma, ryu_san, sensi, siro);
			//�����[�T����AI�B
			AIRyusan(ryu_san, zoma);
			//�펀��AI
			AISensi(sensi);
			/////////////////////////////////////////////////////
			//��������q�[���[��AI���L�q���悤�B
			//�]��DPS�Ǝ����b�̃^���N����삷��񂾁B
			//�Ⴆ�΂���ȃR�[�h�B
			
			//�������m��HP��1000�ȉ��ɂȂ�����
			if (siro.hp < 1000) {
				//�������m���g�Ƀz�C�~��������B
				CommandHoimi(siro, siro);
			}
			//�펀��HP��2000�ȉ��ɂȂ�����
			if (sensi.hp < 2000) {
				//�펀�Ƀz�C�~��������
				CommandHoimi(siro, siro);
			}
			//�����[�T����HP��0�ɂȂ�����U�I���N�B
			if (ryu_san.hp == 0) {
				CommandZaoriku(siro, ryu_san);
			}
			/////////////////////////////////////////////////////

			//�R�}���h�I���I���B
			isSelectCommand = 0;
		}
		//�R�}���h���������B
		ExecuteCommand(zoma, sensi, ryu_san, siro, isSelectCommand, turnNo);
		
		// �����܂ł̊ԂɃQ�[���̃v���O�����������Ă����Ă�//////////////////////
		
		//1�t���[���̏I���B
		kbcEndFrame();
		
	}

	return 0;
}