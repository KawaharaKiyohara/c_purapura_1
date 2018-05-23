#include <iostream>
#include "consoleLib.h"
#include <time.h>
#include <stdlib.h>


using namespace std;
//////////////////////////////////////////////////////
// 構造体など
//////////////////////////////////////////////////////

/*!
*@brief	キャラクター構造体。
*@details	キャラクターのパラメータを一つにまとめて、新しい型とします。
*/
struct Character {
	string	name;				//名前。
	int		maxHP;				//最大ヒットポイント。
	int		hp;					//ヒットポイント。
	int		mp;					//マジックポイント。
	int		atk;				//攻撃力。
	int		def;				//防御力。
	float	hate;				//ヘイト。	この値が高いほど、敵に狙われやすくなります。
	int		buffCount;			//バフカウント。	スクルト、バイキルトがかかると、カウントが５になります。０になるとバフが切れます。
	int		tensinoInori = 0;	//天使の祈りがかかっているかどうか。これがかかっている場合。死亡しても復活します。ヒーラーのみ使用可能。
	int		commandCount = 2;	//1ターンで行える行動数。白魔導士は３回行える。
	int		baseAtk;	//基本攻撃力。
	int		baseDef;	//基本防御力。
};

#include "AICommand.h"


/*----------------------------------------------------------------------
//ヒーラーが使用できる関数宣言の一覧。
----------------------------------------------------------------------*/
/*!
 *@brief	攻撃する。
 *@param[in]	siro	白魔導士
 *@param[in]	target	攻撃対象のキャラクタ。
 */
void CommandAttack(Character& siro, Character& target);
/*!
 *@brief	挑発する。
 *@details
 * ヘイトがたまって、魔王から狙われやすくなります。
 *@param[in]	siro	白魔導士
 *@param[in]	target	攻撃対象のキャラクタ。
 */
void CommandChouhatu(Character& siro);
/*!
 *@brief	遊ぶ
 *@details
 * ？？？？？？
 *@param[in]	siro	白魔導士
 */
void CommandAsobu(Character& siro);
/*!
 *@brief	ホイミ(回復呪文)をかける。
 *@param[in]	siro	白魔導士
 *@param[in]	target	魔法をかける対象。
 */
void CommandHoimi(Character& siro, Character& target);
/*!
 *@brief	スクルト(防御力アップ呪文)をかける。
 *@param[in]	siro	白魔導士
 *@param[in]	target	魔法をかける対象。
 */
void CommandSukuruto(Character& siro, Character& target);
/*!
 *@brief	ザオリク(蘇生呪文)をかける。
 *@param[in]	siro	白魔導士
 *@param[in]	target	魔法をかける対象。
 */
void CommandZaoriku(Character& siro, Character& target);
/*!
 *@brief	バイキルト(攻撃力アップ呪文)をかける。
 *@param[in]	siro	白魔導士
 *@param[in]	target	魔法をかける対象。
 */
void CommandBaikiruto(Character& siro, Character& target);
/*!
 *@brief	天使の祈りをかける。
 *@details
 * 白魔導士自身にしかかけることがない、特殊な祈り。
 * 一度だけ死亡しても自動的に蘇生する、白魔導士の奥義。
 *@param[in]	siro	白魔導士
 */
void CommandTenshiNoInori(Character& siro);


/*----------------------------------------------------------------------
//メイン関数。
----------------------------------------------------------------------*/
int main()
{
	//乱数を初期化。
	srand((unsigned)time(NULL));

	//ターン数。
	int turnNo = 1;
	//コマンド選択をする？ 1 でコマンド選択中
	int isSelectCommand = 1;
	//竜騎士(DPS)。リューサン。
	//竜騎士は耐久力が少な目で、攻撃力が高い。
	Character ryu_san;

	//続いて戦士(タンク)。
	//戦死は耐久力が高めだが、攻撃力は低い。
	Character sensi;

	//続いて白魔導士(ヒーラー)
	//耐久はリューサンより高めだが、戦死より低い。
	//唯一のヒーラー。
	Character siro;

	//最後に魔王様。
	Character zoma;

	//キャラのステータスを初期化する。
	InitCharacterState(ryu_san, sensi, siro, zoma);

	//ここからゲームループ。
	while (true) {
		//1フレームの開始。
		kbcBeginFrame();
		//背景を描画。
		DrawBackground();

		//キャラクターのステータスを描画。
		DrawCharacterStateAll(ryu_san, sensi, siro, zoma, turnNo);
		
		//時間によるキャラクターのステータスの更新処理。
		UpdateCharacterState(sensi, ryu_san, siro, zoma);
		
		
		if (isSelectCommand == 1 && zoma.hp > 0) {
			//ＡＩがコマンドを選択中。
			//魔王のAI
			AIMaou(zoma, ryu_san, sensi, siro);
			//リューサンのAI。
			AIRyusan(ryu_san, zoma);
			//戦死のAI
			AISensi(sensi);
			/////////////////////////////////////////////////////
			//ここからヒーラーのAIを記述しよう。
			//脳筋DPSと紙装甲のタンクを介護するんだ。
			//例えばこんなコード。
			
			//白魔導士のHPが1000以下になったら
			if (siro.hp < 1000) {
				//白魔導士自身にホイミをかける。
				CommandHoimi(siro, siro);
			}
			//戦死のHPが2000以下になったら
			if (sensi.hp < 2000) {
				//戦死にホイミをかける
				CommandHoimi(siro, siro);
			}
			//リューサンのHPが0になったらザオリク。
			if (ryu_san.hp == 0) {
				CommandZaoriku(siro, ryu_san);
			}
			/////////////////////////////////////////////////////

			//コマンド選択終わり。
			isSelectCommand = 0;
		}
		//コマンドを処理中。
		ExecuteCommand(zoma, sensi, ryu_san, siro, isSelectCommand, turnNo);
		
		// ここまでの間にゲームのプログラムを書いていってね//////////////////////
		
		//1フレームの終了。
		kbcEndFrame();
		
	}

	return 0;
}