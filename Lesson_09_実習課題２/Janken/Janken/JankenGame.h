#pragma once
/*!
 *@brief	����񂯂�Q�[���N���X�B
 */
class JankenGame
{
public:
	/////////////////////////////////////////////////
	// �������烁���o�֐��̐錾�B
	/////////////////////////////////////////////////
	/*!
	 *@brief	����񂯂�Q�[�������s�B
	 */
	void Run();
	/*!
	 *@brief	����񂯂�̌��ʂ�\������֐��B
	 *@param[in]	result		���ʁB0�Ȃ珟���A1�Ȃ���������A2�Ȃ畉���B
	 *@return		�߂�l�Ȃ�
	 */
	void DispResultMessage(int result);
	/*!
	 *@brief	�R���s���[�^�[�̎��\������֐��B
	 */
	void DispComNoTe();
	/*!
	 *@brief	�v���C���[�̎��\������֐��B
	 */
	void DispPlayerNoTe();
	/////////////////////////////////////////////////
	//�������烁���o�ϐ��B
	/////////////////////////////////////////////////
	int comNoTe = 0;	//COM�̎�B�O�̓O�[�A�P�̓`���L�A�Q�̓p�[�B
	int playerNoTe = 0;	//�v���C���[�̎�
};

