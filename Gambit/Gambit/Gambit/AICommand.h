#pragma once

#include <deque>



class IAICommand {
public:
	virtual bool Execute() = 0;
};

//�U���R�}���h�N���X�B
class AICommandAttack : public IAICommand {
public:
	Character& m_attacker;		//�U���ҁB
	Character& m_target;			//�^�[�Q�b�g�B
	AICommandAttack(Character& attacker, Character& target) :
		m_attacker(attacker),
		m_target(target)
	{
		
	}
	bool Execute() override
	{
		if (m_attacker.hp > 0) {
			if (m_target.hp > 0) {
				char text[256];
				sprintf_s(text, "%s�̍U���I�I�I", m_attacker.name.c_str());
				kbcDrwaMojiRetu(1, 12, text);
				float hoge = (rand() % 100) / 200.0f;
				int damage = max(0.0f, (m_attacker.atk / 2 + m_attacker.atk * hoge) - m_target.def / 4);
				text[256];
				sprintf_s(text, "%s��%d��Ұ�ޗ^����", m_target.name.c_str(), damage);
				kbcDrwaMojiRetu(1, 13, text);
				m_target.hp -= damage;
				m_target.hate -= 50;	//�w�C�g��������B
				if (m_target.hp < 0) {
					sprintf_s(text, "%s�͎���ł��܂���", m_target.name.c_str());
					kbcDrwaMojiRetu(1, 14, text);
					m_target.hp = 0;
					if (m_target.tensinoInori == 1) {
						//�V�g�̋F�肪�������Ă���B
						sprintf_s(text, "�V�g�̋F��:%s�͐����Ԃ����B", m_target.name.c_str());
						kbcDrwaMojiRetu(1, 15, text);
						m_target.tensinoInori = 0;
						m_target.hp = m_target.maxHP;
					}
					else {
						m_target.hate = 0;
					}
					
				}
			}
			else {
				char text[256];
				sprintf_s(text, "%s�̍U���I�I�I", m_attacker.name.c_str());
				kbcDrwaMojiRetu(1, 12, text);
				text[256];
				sprintf_s(text, "%s�����̏R��I", m_target.name.c_str());
				kbcDrwaMojiRetu(1, 13, text);
			}
			return true;
		}
		
		return false;
	}
};

//�����R�}���h�N���X�B
class AICommandChouhatu : public IAICommand {
public:
	AICommandChouhatu(Character & target) :
		m_target(target) {}
	Character & m_target;		//�������s�������́B
	bool Execute() override
	{
		if (m_target.hp > 0) {
			char text[256];
			sprintf_s(text, "%s�͒������s����", m_target.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			int addHate = 100;
			m_target.hate += addHate;
			sprintf_s(text, "�w�C�g��%d�オ����", addHate);
			kbcDrwaMojiRetu(1, 13, text);
			return true;
		}
		return false;
		
	}
};
//�V�Ԃ��B
class AICommandAsobu : public IAICommand {
public:
	AICommandAsobu(Character& chara) :
		m_chara(chara) {}
	Character m_chara;
	bool Execute() override
	{
		if (m_chara.hp > 0) {
			char text[256];
			sprintf_s(text, "%s�͗V��ł���B", m_chara.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			return true;
		}
		return false;
	}
};

//�񕜃R�}���h�N���X�B
class AICommandHomi : public IAICommand {
public:
	Character & m_kaifuku;		//�U���ҁB
	Character& m_target;		//�^�[�Q�b�g�B
	AICommandHomi(Character& kaifuku, Character& target) :
		m_kaifuku(kaifuku),
		m_target(target)
	{

	}
	bool Execute() override
	{
		if (m_kaifuku.hp > 0) {
			char text[256];
			sprintf_s(text, "%s��βЂ��������I�I�I", m_kaifuku.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			if (m_kaifuku.mp > 30) {
				int repair = 1000;
				text[256];
				sprintf_s(text, "%s��%d�񕜂����B", m_target.name.c_str(), repair);
				kbcDrwaMojiRetu(1, 13, text);
				m_target.hp = min( m_target.maxHP, m_target.hp + repair );
				m_kaifuku.mp -= 30;
			}
			else {
				kbcDrwaMojiRetu(1, 13, "�l�o������Ȃ��B");
			}
			return true;
		}
		return false;
		
	}
};

//�X�N���g�R�}���h�B
class AICommandSukuruto : public IAICommand {
public:
	Character & m_kaifuku;		//�U���ҁB
	Character& m_target;		//�^�[�Q�b�g�B
	AICommandSukuruto(Character& kaifuku, Character& target) :
		m_kaifuku(kaifuku),
		m_target(target)
	{

	}
	bool Execute() override
	{
		if (m_kaifuku.hp > 0) {
			char text[256];
			sprintf_s(text, "%s�ͽ��Ă��������I�I�I", m_kaifuku.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			if (m_kaifuku.mp > 100) {
				
				sprintf_s(text, "%s�͖h��͂��啝�Ɍ��サ���B", m_target.name.c_str());
				kbcDrwaMojiRetu(1, 13, text);
				m_target.def = m_target.baseDef * 1.2;
				m_target.buffCount = 5;
				m_kaifuku.mp -= 100;
			}
			else {
				kbcDrwaMojiRetu(1, 13, "�l�o������Ȃ��B");
			}
			return true;
		}
		return false;

	}
};
//�V�g�̋F��R�}���h�B
class AICommandTenshiNoInori : public IAICommand {
public:
	Character & m_kaifuku;		//�U���ҁB
	
	AICommandTenshiNoInori(Character& kaifuku) :
		m_kaifuku(kaifuku)
	{

	}
	bool Execute() override
	{
		if (m_kaifuku.hp > 0) {
			char text[256];
			sprintf_s(text, "%s�͓V�g�̋F����������I�I�I", m_kaifuku.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			if (m_kaifuku.mp > 100) {
				m_kaifuku.mp -= 100;
				m_kaifuku.tensinoInori = 1;
			}
			else {
				kbcDrwaMojiRetu(1, 13, "�l�o������Ȃ��B");
			}
			return true;
		}
		return false;

	}
};
//�h���R�}���h�B
class AICommandZaoriku : public IAICommand {
public:
	Character & m_kaifuku;		//�U���ҁB
	Character& m_target;		//�^�[�Q�b�g�B
	AICommandZaoriku(Character& kaifuku, Character& target) :
		m_kaifuku(kaifuku),
		m_target(target)
	{

	}
	bool Execute() override
	{
		if (m_kaifuku.hp > 0) {
			char text[256];
			sprintf_s(text, "%s�ͻ޵ظ���������I�I�I", m_kaifuku.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			if (m_kaifuku.mp > 200) {
				sprintf_s(text, "%s�͐����Ԃ����B", m_target.name.c_str());
				kbcDrwaMojiRetu(1, 13, text);
				m_kaifuku.mp -= 100;
				m_target.hp = m_target.maxHP ;
			}
			else {
				kbcDrwaMojiRetu(1, 13, "�l�o������Ȃ��B");
			}
			return true;
		}
		return false;

	}
};


//�o�C�L���g�R�}���h�B
class AICommandBaikiruto : public IAICommand {
public:
	Character & m_kaifuku;		//�U���ҁB
	Character& m_target;		//�^�[�Q�b�g�B
	AICommandBaikiruto(Character& kaifuku, Character& target) :
		m_kaifuku(kaifuku),
		m_target(target)
	{

	}
	bool Execute() override
	{
		if (m_kaifuku.hp > 0) {
			char text[256];
			sprintf_s(text, "%s���޲��Ă��������I�I�I", m_kaifuku.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			if (m_kaifuku.mp > 100) {

				sprintf_s(text, "%s�͍U���͂��啝�Ɍ��サ���B", m_target.name.c_str());
				kbcDrwaMojiRetu(1, 13, text);
				m_target.atk = m_target.baseAtk * 1.2;
				m_target.buffCount = 5;
				m_kaifuku.mp -= 100;
			}
			else {
				kbcDrwaMojiRetu(1, 13, "�l�o������Ȃ��B");
			}
			return true;
		}
		return false;

	}
};

std::deque<IAICommand*>	aiCommandList;

//�R�}���h���������I�I�I
int ExecuteCommand()
{
	if (aiCommandList.empty()) {
		//�R�}���h�Ȃ��Ȃ�����I
		return 0;
	}
	while (true) {
		IAICommand* command = aiCommandList.front();
		aiCommandList.pop_front();
		if (command->Execute()) {
			break;
		}
		if (aiCommandList.empty()) {
			//�R�}���h�Ȃ��Ȃ�����I
			return 0;
		}
	}
	return aiCommandList.size();
}

void CommandAttack(Character& attacker, Character& target) 
{
	if (attacker.commandCount == 0) {
		return;
	}
	attacker.commandCount--;
	if (attacker.hp > 0) {
		aiCommandList.push_back(new AICommandAttack(attacker, target));
	}
}

void CommandChouhatu( Character& target)
{
	if (target.commandCount == 0) {
		return;
	}
	target.commandCount--;
	if (target.hp > 0) {
		aiCommandList.push_back(new AICommandChouhatu(target));
	}
}
void CommandAsobu(Character& chara)
{
	if (chara.commandCount == 0) {
		return;
	}
	chara.commandCount--;
	if (chara.hp > 0) {
		aiCommandList.push_back(new AICommandAsobu(chara));
	}
}
void CommandHoimi(Character& kaifukusya, Character& target)
{
	if (kaifukusya.commandCount == 0) {
		return;
	}
	kaifukusya.commandCount--;
	if (kaifukusya.hp > 0) {
		aiCommandList.push_back(new AICommandHomi(kaifukusya, target));
	}
}

void CommandSukuruto(Character& kaifukusya, Character& target)
{
	if (kaifukusya.commandCount == 0) {
		return;
	}
	kaifukusya.commandCount--;
	if (kaifukusya.hp > 0) {
		aiCommandList.push_back(new AICommandSukuruto(kaifukusya, target));
	}
}

void CommandZaoriku(Character& kaifukusya, Character& target)
{
	if (kaifukusya.commandCount == 0) {
		return;
	}
	kaifukusya.commandCount--;
	if (kaifukusya.hp > 0) {
		aiCommandList.push_back(new AICommandZaoriku(kaifukusya, target));
	}
}
void CommandBaikiruto(Character& kaifukusya, Character& target)
{
	if (kaifukusya.commandCount == 0) {
		return;
	}
	kaifukusya.commandCount--;
	if (kaifukusya.hp > 0) {
		aiCommandList.push_back(new AICommandBaikiruto(kaifukusya, target));
	}
}
void CommandTenshiNoInori(Character& kaifukusya)
{
	if (kaifukusya.commandCount == 0) {
		return;
	}
	kaifukusya.commandCount--;
	if (kaifukusya.hp > 0) {
		aiCommandList.push_back(new AICommandTenshiNoInori(kaifukusya));
	}
}

//////////////////////////////////////////////////////
// �֐���`�B
//////////////////////////////////////////////////////

/*!----------------------------------------------------------------------
*@brief	�펀��AI
----------------------------------------------------------------------*/
void AISensi(Character& sensi)
{
	//�펀��1/2�̊m���Œ������s���B�I
	for (int i = 0; i < 2; i++) {

		int t = rand() % 2;
		if (t == 0) {
			CommandChouhatu(sensi);
		}
		else {
			CommandAsobu(sensi);
		}
	}

}
/*!----------------------------------------------------------------------
*@brief	���[�T����AI
----------------------------------------------------------------------*/
void AIRyusan(Character& ryu_san, Character& zoma)
{
	//�Ȃ���Ȃ���Ȃ���[�[�[�[�I�I�I
	CommandAttack(ryu_san, zoma);
	CommandAttack(ryu_san, zoma);
}
/*!----------------------------------------------------------------------
*@brief	������AI
----------------------------------------------------------------------*/
void AIMaou(Character& zoma, Character& ryu_san, Character& sensi, Character& siro)
{
	for (int i = 0; i < 2; i++) {
		float hateSum = ryu_san.hate + sensi.hate + siro.hate;

		float t = rand() % 100 / 100.0f;
		if (t < ryu_san.hate / hateSum) {
			//�����[�T��������
			CommandAttack(zoma, ryu_san);
			return;
		}
		t -= ryu_san.hate / hateSum;
		if (t < sensi.hate / hateSum) {
			//�펀������
			CommandAttack(zoma, sensi);
			return;
		}

		//�q�[��������B
		CommandAttack(zoma, siro);
	}
	

}

/*!----------------------------------------------------------------------
*@brief	�L�����̃X�e�[�^�X�̏������B
----------------------------------------------------------------------*/
void InitCharacterState(Character& ryu_san, Character& sensi, Character& siro, Character& zoma)
{
	//�L�����N�^�[�̃p�����[�^��ݒ肷��B
	//�܂��͗��R�m(DPS)�B�����[�T���B
	//���R�m�͑ϋv�͂����ȖڂŁA�U���͂������B
	ryu_san.name = "ح���";
	ryu_san.maxHP = 1200;
	ryu_san.hp = ryu_san.maxHP;
	ryu_san.atk = 800;
	ryu_san.baseAtk = ryu_san.atk;
	ryu_san.def = 100;
	ryu_san.baseDef = ryu_san.def;
	ryu_san.hate = 100;
	ryu_san.mp = 0;
	ryu_san.buffCount = 0;

	//�����Đ�m(�^���N)�B
	//�펀�͑ϋv�͂����߂����A�U���͂͒Ⴂ�B
	sensi.name = "�ݼ";
	sensi.hp = 3000;
	sensi.maxHP = sensi.hp;
	sensi.atk = 200;
	sensi.baseAtk = sensi.atk;
	sensi.def = 800;
	sensi.baseDef = sensi.def;
	sensi.hate = 600;
	sensi.mp = 0;
	sensi.buffCount = 0;

	//�����Ĕ������m(�q�[���[)
	//�ϋv�̓����[�T����荂�߂����A�펀���Ⴂ�B
	//�B��̃q�[���[�B
	siro.name = "��";
	siro.hp = 1500;
	siro.maxHP = siro.hp;
	siro.atk = 300;
	siro.baseAtk = siro.atk;
	siro.def = 200;
	siro.baseDef = siro.def;
	siro.hate = 100;
	siro.mp = 6000;
	siro.buffCount = 0;

	//�Ō�ɖ����l�B
	zoma.name = "�喂���ް�";
	zoma.hp = 30000;
	zoma.maxHP = zoma.hp;
	zoma.atk = 1400;
	zoma.baseAtk = zoma.atk;
	zoma.def = 500;
	zoma.baseDef = zoma.def;
	zoma.hate = 0;
	zoma.mp = 9999999;
}
/*!----------------------------------------------------------------------
*@brief	�X�e�[�^�X��`�悷��B
----------------------------------------------------------------------*/
void DrawCharacterState(int baseXPos, Character& chara)
{
	kbcDrwaMojiRetu(baseXPos, 0, chara.name.c_str());
	char str[256];
	sprintf_s(str, "HP:%d", chara.hp);
	kbcDrwaMojiRetu(baseXPos, 1, str);

	sprintf_s(str, "MP:%d", chara.mp);
	kbcDrwaMojiRetu(baseXPos, 2, str);
	
	sprintf_s(str, "HATE:%d", (int)chara.hate);
	kbcDrwaMojiRetu(baseXPos, 3, str);
	
	sprintf_s(str, "BUFF:%d", chara.buffCount);
	kbcDrwaMojiRetu(baseXPos, 4, str);
}
/*!----------------------------------------------------------------------
*@brief	�L�����N�^�[�̃X�e�[�^�X��S�`��
----------------------------------------------------------------------*/
void DrawCharacterStateAll(Character& ryu_san, Character& sensi, Character& siro, Character& zoma, int turnNo)
{
	DrawCharacterState(1, ryu_san);
	DrawCharacterState(10, sensi);
	DrawCharacterState(22, siro);

	char str[256];
	sprintf_s(str, "%s  HP : %d", zoma.name.c_str(), zoma.hp);
	kbcDrwaMojiRetu(2, 7, str);
	sprintf_s(str, "%d���", turnNo);
	kbcDrwaMojiRetu(1, 6, str);

}
/*!----------------------------------------------------------------------
*@brief	�L�����N�^�[�̃X�e�[�^�X�̍X�V�B
----------------------------------------------------------------------*/
void UpdateCharacterState(Character& ryu_san, Character& sensi, Character& siro, Character& zoma)
{
	//�w�C�g�͏����Â��܂��Ă����B
	if (sensi.hp == 0) {
		sensi.hate = 0;
	}
	else {
		sensi.hate += 10.0f;
	}
	if (ryu_san.hp == 0) {
		ryu_san.hate = 0;
	}
	else {
		ryu_san.hate += 10.0f;

	}
	if (siro.hp == 0) {
		siro.hate = 0;
	}
	else {
		siro.hate += 10.0f;
	}
	//�R�}���h�J�E���g�̉񕜁B
	sensi.commandCount = 2;
	ryu_san.commandCount = 2;
	siro.commandCount = 3;	//�q�[���[��3��s���B
	zoma.commandCount = 2;
	//�o�t�J�E���g�����Z����B
	sensi.buffCount;
	ryu_san.buffCount--;
	siro.buffCount--;

	if (sensi.buffCount < 0) {
		//�o�t���������B
		sensi.buffCount = 0;
		sensi.def = sensi.baseDef;
	}
	if (ryu_san.buffCount < 0) {
		//�o�t���������B
		ryu_san.buffCount = 0;
		ryu_san.def = ryu_san.baseDef;
	}
	if (siro.buffCount < 0) {
		//�o�t���������B
		siro.buffCount = 0;
		siro.def = siro.baseDef;
	}
}
/*!----------------------------------------------------------------------
*@brief	�w�i��`�悷��֐��B
----------------------------------------------------------------------*/
void DrawBackground()
{
	//�Q�����z��B���ȏ���p.256����z��Ɋւ���L�q������܂��B�������z���p.269
	int map[16][32] = {
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  0���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  1���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  2���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  3���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  4���
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },	//  5���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  6���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  7���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  8���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  9���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 10���
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },	// 11���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 12���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 13���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 14���
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },	// 15���
	};
	//�w�i��`��B
	//�񎟌��z���map���Q�Ƃ��āA�w�i��`�悵�Ă����B
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 32; x++) {
			if (map[y][x] == 0) {
				//2�����z���map[y][x]��0�������Ă�����A
				//���Wx, y�̏ꏊ�ɋ󔒕�����`�悷��B
				kbcDrawMoji(x, y, ' ');
			}
			else if (map[y][x] == 1) {
				//2�����z���map[y][x]��1�������Ă�����A
				//���Wx, y�̏ꏊ��@��`�悷��B
				kbcDrawMoji(x, y, '@');
			}
			else if (map[y][x] == 2)
			{
				kbcDrawMoji(x, y, '-');
			}
		}
	}
}
/*----------------------------------------------------------------------
//�R�}���h�������B�B
----------------------------------------------------------------------*/

void ExecuteCommand(Character& zoma, Character& sensi, Character& ryu_san, Character& siro, int& isSelectCommand, int& turnNo)
{
	if (sensi.hp == 0 && ryu_san.hp == 0 && siro.hp == 0) {
		kbcDrwaMojiRetu(1, 12, "�S�ł��Ă��܂����E�E�E");
	}else if (zoma.hp > 0) {
		if (ExecuteCommand() == 0) {
			//�R�}���h��S�����������̂ŁA���̃^�[���B
			isSelectCommand = 1;
			char str[256];
			sprintf_s(str, "%d��ݖڏI���I�I�I", turnNo);
			kbcDrwaMojiRetu(1, 6, str);
			turnNo++;
		}

	}
	else {
		kbcDrwaMojiRetu(1, 12, "�喂���ްς�|�����I�I�I");
	}
}
