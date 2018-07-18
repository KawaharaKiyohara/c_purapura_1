#pragma once
#include <Windows.h>

/////////////////////////////////////////////////////
// �O���[�o���֐��̊֐��錾�B
/////////////////////////////////////////////////////


/*!----------------------------------------------------
 *@brief	kbcDrawMoji
 *	������`�悷��֐��B
 *@details
 * �p���������`��ł��܂���B���{���\���������ꍇ�́A
 * �ꕶ�����Ƃ��Ă�kbcDrawMojiRetu���g���悤�ɁB
 *
 *@param[in]	posX		������`�悵����X���W�B
 *@param[in]	posY		������`�悵����Y���W�B
 *@param[in]	moji		�`�悵���������B
 *@code
 		//�g�p��
 		//x���W�F1�Ay���W:4�̏ꏊ��A�Ƃ���������`�悷��B
 		kbcDrawMoji( 1, 4, 'A' );
 *@endcode
 ----------------------------------------------------*/
extern bool kbcDrawMoji(int posX, int posY, char moji);

/*!----------------------------------------------------
 *@brief	kbcDrwaMojiRetu
 * �������`�悷��֐��B
 *
 *@param[in]	posX		�������`�悵����X���W�B
 *@param[in]	posY		�������`�悵����Y���W�B
 *@param[in]	mojiretu	�`�悵����������B
 *@code
 		//�g�p��
 		//x���W�F1�Ay���W:4�̏ꏊ��Hello world�Ƃ����������`�悷��B
 		kbcDrwaMojiRetu( 1, 4, "Hello world" );
 *@endcode
 ----------------------------------------------------*/ 
extern void kbcDrawMojiRetu(int startPosX, int posY, const char* mojiretu);

/*!----------------------------------------------------
 *@brief	kbcBeginFrame
 * �t���[���̊J�n�ɌĂяo���֐��B
 ----------------------------------------------------*/
extern void kbcBeginFrame();

/*!----------------------------------------------------
 *@brief	kbcBeginFrame
 * �t���[���̏I���ɌĂяo���֐��B
 ----------------------------------------------------*/
extern void kbcEndFrame();
