#pragma once

#include <deque>



class IAICommand {
public:
	virtual bool Execute() = 0;
};

//攻撃コマンドクラス。
class AICommandAttack : public IAICommand {
public:
	Character& m_attacker;		//攻撃者。
	Character& m_target;			//ターゲット。
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
				sprintf_s(text, "%sの攻撃！！！", m_attacker.name.c_str());
				kbcDrwaMojiRetu(1, 12, text);
				float hoge = (rand() % 100) / 200.0f;
				int damage = max(0.0f, (m_attacker.atk / 2 + m_attacker.atk * hoge) - m_target.def / 4);
				text[256];
				sprintf_s(text, "%sに%dﾀﾞﾒｰｼﾞ与えた", m_target.name.c_str(), damage);
				kbcDrwaMojiRetu(1, 13, text);
				m_target.hp -= damage;
				m_target.hate -= 50;	//ヘイトも下げる。
				if (m_target.hp < 0) {
					sprintf_s(text, "%sは死んでしまった", m_target.name.c_str());
					kbcDrwaMojiRetu(1, 14, text);
					m_target.hp = 0;
					if (m_target.tensinoInori == 1) {
						//天使の祈りがかかっている。
						sprintf_s(text, "天使の祈り:%sは生き返った。", m_target.name.c_str());
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
				sprintf_s(text, "%sの攻撃！！！", m_attacker.name.c_str());
				kbcDrwaMojiRetu(1, 12, text);
				text[256];
				sprintf_s(text, "%sを死体蹴り！", m_target.name.c_str());
				kbcDrwaMojiRetu(1, 13, text);
			}
			return true;
		}
		
		return false;
	}
};

//挑発コマンドクラス。
class AICommandChouhatu : public IAICommand {
public:
	AICommandChouhatu(Character & target) :
		m_target(target) {}
	Character & m_target;		//挑発を行ったもの。
	bool Execute() override
	{
		if (m_target.hp > 0) {
			char text[256];
			sprintf_s(text, "%sは挑発を行った", m_target.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			int addHate = 100;
			m_target.hate += addHate;
			sprintf_s(text, "ヘイトが%d上がった", addHate);
			kbcDrwaMojiRetu(1, 13, text);
			return true;
		}
		return false;
		
	}
};
//遊ぶぜ。
class AICommandAsobu : public IAICommand {
public:
	AICommandAsobu(Character& chara) :
		m_chara(chara) {}
	Character m_chara;
	bool Execute() override
	{
		if (m_chara.hp > 0) {
			char text[256];
			sprintf_s(text, "%sは遊んでいる。", m_chara.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			return true;
		}
		return false;
	}
};

//回復コマンドクラス。
class AICommandHomi : public IAICommand {
public:
	Character & m_kaifuku;		//攻撃者。
	Character& m_target;		//ターゲット。
	AICommandHomi(Character& kaifuku, Character& target) :
		m_kaifuku(kaifuku),
		m_target(target)
	{

	}
	bool Execute() override
	{
		if (m_kaifuku.hp > 0) {
			char text[256];
			sprintf_s(text, "%sはﾎｲﾐを唱えた！！！", m_kaifuku.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			if (m_kaifuku.mp > 30) {
				int repair = 1000;
				text[256];
				sprintf_s(text, "%sは%d回復した。", m_target.name.c_str(), repair);
				kbcDrwaMojiRetu(1, 13, text);
				m_target.hp = min( m_target.maxHP, m_target.hp + repair );
				m_kaifuku.mp -= 30;
			}
			else {
				kbcDrwaMojiRetu(1, 13, "ＭＰが足りない。");
			}
			return true;
		}
		return false;
		
	}
};

//スクルトコマンド。
class AICommandSukuruto : public IAICommand {
public:
	Character & m_kaifuku;		//攻撃者。
	Character& m_target;		//ターゲット。
	AICommandSukuruto(Character& kaifuku, Character& target) :
		m_kaifuku(kaifuku),
		m_target(target)
	{

	}
	bool Execute() override
	{
		if (m_kaifuku.hp > 0) {
			char text[256];
			sprintf_s(text, "%sはｽｸﾙﾄを唱えた！！！", m_kaifuku.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			if (m_kaifuku.mp > 100) {
				
				sprintf_s(text, "%sは防御力が大幅に向上した。", m_target.name.c_str());
				kbcDrwaMojiRetu(1, 13, text);
				m_target.def = m_target.baseDef * 1.2;
				m_target.buffCount = 5;
				m_kaifuku.mp -= 100;
			}
			else {
				kbcDrwaMojiRetu(1, 13, "ＭＰが足りない。");
			}
			return true;
		}
		return false;

	}
};
//天使の祈りコマンド。
class AICommandTenshiNoInori : public IAICommand {
public:
	Character & m_kaifuku;		//攻撃者。
	
	AICommandTenshiNoInori(Character& kaifuku) :
		m_kaifuku(kaifuku)
	{

	}
	bool Execute() override
	{
		if (m_kaifuku.hp > 0) {
			char text[256];
			sprintf_s(text, "%sは天使の祈りを唱えた！！！", m_kaifuku.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			if (m_kaifuku.mp > 100) {
				m_kaifuku.mp -= 100;
				m_kaifuku.tensinoInori = 1;
			}
			else {
				kbcDrwaMojiRetu(1, 13, "ＭＰが足りない。");
			}
			return true;
		}
		return false;

	}
};
//蘇生コマンド。
class AICommandZaoriku : public IAICommand {
public:
	Character & m_kaifuku;		//攻撃者。
	Character& m_target;		//ターゲット。
	AICommandZaoriku(Character& kaifuku, Character& target) :
		m_kaifuku(kaifuku),
		m_target(target)
	{

	}
	bool Execute() override
	{
		if (m_kaifuku.hp > 0) {
			char text[256];
			sprintf_s(text, "%sはｻﾞｵﾘｸを唱えた！！！", m_kaifuku.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			if (m_kaifuku.mp > 200) {
				sprintf_s(text, "%sは生き返った。", m_target.name.c_str());
				kbcDrwaMojiRetu(1, 13, text);
				m_kaifuku.mp -= 100;
				m_target.hp = m_target.maxHP ;
			}
			else {
				kbcDrwaMojiRetu(1, 13, "ＭＰが足りない。");
			}
			return true;
		}
		return false;

	}
};


//バイキルトコマンド。
class AICommandBaikiruto : public IAICommand {
public:
	Character & m_kaifuku;		//攻撃者。
	Character& m_target;		//ターゲット。
	AICommandBaikiruto(Character& kaifuku, Character& target) :
		m_kaifuku(kaifuku),
		m_target(target)
	{

	}
	bool Execute() override
	{
		if (m_kaifuku.hp > 0) {
			char text[256];
			sprintf_s(text, "%sはﾊﾞｲｷﾙﾄを唱えた！！！", m_kaifuku.name.c_str());
			kbcDrwaMojiRetu(1, 12, text);
			if (m_kaifuku.mp > 100) {

				sprintf_s(text, "%sは攻撃力が大幅に向上した。", m_target.name.c_str());
				kbcDrwaMojiRetu(1, 13, text);
				m_target.atk = m_target.baseAtk * 1.2;
				m_target.buffCount = 5;
				m_kaifuku.mp -= 100;
			}
			else {
				kbcDrwaMojiRetu(1, 13, "ＭＰが足りない。");
			}
			return true;
		}
		return false;

	}
};

std::deque<IAICommand*>	aiCommandList;

//コマンドを処理中！！！
int ExecuteCommand()
{
	if (aiCommandList.empty()) {
		//コマンドなくなったよ！
		return 0;
	}
	while (true) {
		IAICommand* command = aiCommandList.front();
		aiCommandList.pop_front();
		if (command->Execute()) {
			break;
		}
		if (aiCommandList.empty()) {
			//コマンドなくなったよ！
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
// 関数定義。
//////////////////////////////////////////////////////

/*!----------------------------------------------------------------------
*@brief	戦死のAI
----------------------------------------------------------------------*/
void AISensi(Character& sensi)
{
	//戦死は1/2の確率で挑発を行う。！
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
*@brief	りゅーサンのAI
----------------------------------------------------------------------*/
void AIRyusan(Character& ryu_san, Character& zoma)
{
	//なぐれなぐれなぐれーーーー！！！
	CommandAttack(ryu_san, zoma);
	CommandAttack(ryu_san, zoma);
}
/*!----------------------------------------------------------------------
*@brief	魔王のAI
----------------------------------------------------------------------*/
void AIMaou(Character& zoma, Character& ryu_san, Character& sensi, Character& siro)
{
	for (int i = 0; i < 2; i++) {
		float hateSum = ryu_san.hate + sensi.hate + siro.hate;

		float t = rand() % 100 / 100.0f;
		if (t < ryu_san.hate / hateSum) {
			//リューサンを殴る
			CommandAttack(zoma, ryu_san);
			return;
		}
		t -= ryu_san.hate / hateSum;
		if (t < sensi.hate / hateSum) {
			//戦死を殴る
			CommandAttack(zoma, sensi);
			return;
		}

		//ヒーラを殴る。
		CommandAttack(zoma, siro);
	}
	

}

/*!----------------------------------------------------------------------
*@brief	キャラのステータスの初期化。
----------------------------------------------------------------------*/
void InitCharacterState(Character& ryu_san, Character& sensi, Character& siro, Character& zoma)
{
	//キャラクターのパラメータを設定する。
	//まずは竜騎士(DPS)。リューサン。
	//竜騎士は耐久力が少な目で、攻撃力が高い。
	ryu_san.name = "ﾘｭｰｻﾝ";
	ryu_san.maxHP = 1200;
	ryu_san.hp = ryu_san.maxHP;
	ryu_san.atk = 800;
	ryu_san.baseAtk = ryu_san.atk;
	ryu_san.def = 100;
	ryu_san.baseDef = ryu_san.def;
	ryu_san.hate = 100;
	ryu_san.mp = 0;
	ryu_san.buffCount = 0;

	//続いて戦士(タンク)。
	//戦死は耐久力が高めだが、攻撃力は低い。
	sensi.name = "ｾﾝｼ";
	sensi.hp = 3000;
	sensi.maxHP = sensi.hp;
	sensi.atk = 200;
	sensi.baseAtk = sensi.atk;
	sensi.def = 800;
	sensi.baseDef = sensi.def;
	sensi.hate = 600;
	sensi.mp = 0;
	sensi.buffCount = 0;

	//続いて白魔導士(ヒーラー)
	//耐久はリューサンより高めだが、戦死より低い。
	//唯一のヒーラー。
	siro.name = "ｼﾛ";
	siro.hp = 1500;
	siro.maxHP = siro.hp;
	siro.atk = 300;
	siro.baseAtk = siro.atk;
	siro.def = 200;
	siro.baseDef = siro.def;
	siro.hate = 100;
	siro.mp = 6000;
	siro.buffCount = 0;

	//最後に魔王様。
	zoma.name = "大魔王ｿﾞｰﾏ";
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
*@brief	ステータスを描画する。
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
*@brief	キャラクターのステータスを全描画
----------------------------------------------------------------------*/
void DrawCharacterStateAll(Character& ryu_san, Character& sensi, Character& siro, Character& zoma, int turnNo)
{
	DrawCharacterState(1, ryu_san);
	DrawCharacterState(10, sensi);
	DrawCharacterState(22, siro);

	char str[256];
	sprintf_s(str, "%s  HP : %d", zoma.name.c_str(), zoma.hp);
	kbcDrwaMojiRetu(2, 7, str);
	sprintf_s(str, "%dﾀｰﾝ", turnNo);
	kbcDrwaMojiRetu(1, 6, str);

}
/*!----------------------------------------------------------------------
*@brief	キャラクターのステータスの更新。
----------------------------------------------------------------------*/
void UpdateCharacterState(Character& ryu_san, Character& sensi, Character& siro, Character& zoma)
{
	//ヘイトは少しづつ溜まっていく。
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
	//コマンドカウントの回復。
	sensi.commandCount = 2;
	ryu_san.commandCount = 2;
	siro.commandCount = 3;	//ヒーラーは3回行動。
	zoma.commandCount = 2;
	//バフカウントを減算する。
	sensi.buffCount;
	ryu_san.buffCount--;
	siro.buffCount--;

	if (sensi.buffCount < 0) {
		//バフが消えた。
		sensi.buffCount = 0;
		sensi.def = sensi.baseDef;
	}
	if (ryu_san.buffCount < 0) {
		//バフが消えた。
		ryu_san.buffCount = 0;
		ryu_san.def = ryu_san.baseDef;
	}
	if (siro.buffCount < 0) {
		//バフが消えた。
		siro.buffCount = 0;
		siro.def = siro.baseDef;
	}
}
/*!----------------------------------------------------------------------
*@brief	背景を描画する関数。
----------------------------------------------------------------------*/
void DrawBackground()
{
	//２次元配列。教科書のp.256から配列に関する記述があります。多次元配列はp.269
	int map[16][32] = {
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  0列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  1列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  2列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  3列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  4列目
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },	//  5列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  6列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  7列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  8列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  9列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 10列目
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },	// 11列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 12列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 13列目
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 14列目
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },	// 15列目
	};
	//背景を描画。
	//二次元配列のmapを参照して、背景を描画していく。
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 32; x++) {
			if (map[y][x] == 0) {
				//2次元配列のmap[y][x]に0が入っていたら、
				//座標x, yの場所に空白文字を描画する。
				kbcDrawMoji(x, y, ' ');
			}
			else if (map[y][x] == 1) {
				//2次元配列のmap[y][x]に1が入っていたら、
				//座標x, yの場所に@を描画する。
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
//コマンドを処理。。
----------------------------------------------------------------------*/

void ExecuteCommand(Character& zoma, Character& sensi, Character& ryu_san, Character& siro, int& isSelectCommand, int& turnNo)
{
	if (sensi.hp == 0 && ryu_san.hp == 0 && siro.hp == 0) {
		kbcDrwaMojiRetu(1, 12, "全滅してしまった・・・");
	}else if (zoma.hp > 0) {
		if (ExecuteCommand() == 0) {
			//コマンドを全部処理したので、次のターン。
			isSelectCommand = 1;
			char str[256];
			sprintf_s(str, "%dﾀｰﾝ目終了！！！", turnNo);
			kbcDrwaMojiRetu(1, 6, str);
			turnNo++;
		}

	}
	else {
		kbcDrwaMojiRetu(1, 12, "大魔王ｿﾞｰﾏを倒した！！！");
	}
}
