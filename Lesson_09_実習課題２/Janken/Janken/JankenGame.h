#pragma once
/*!
 *@brief	じゃんけんゲームクラス。
 */
class JankenGame
{
public:
	/////////////////////////////////////////////////
	// ここからメンバ関数の宣言。
	/////////////////////////////////////////////////
	/*!
	 *@brief	じゃんけんゲームを実行。
	 */
	void Run();
	/*!
	 *@brief	じゃんけんの結果を表示する関数。
	 *@param[in]	result		結果。0なら勝ち、1なら引き分け、2なら負け。
	 *@return		戻り値なし
	 */
	void DispResultMessage(int result);
	/*!
	 *@brief	コンピューターの手を表示する関数。
	 */
	void DispComNoTe();
	/*!
	 *@brief	プレイヤーの手を表示する関数。
	 */
	void DispPlayerNoTe();
	/////////////////////////////////////////////////
	//ここからメンバ変数。
	/////////////////////////////////////////////////
	int comNoTe = 0;	//COMの手。０はグー、１はチョキ、２はパー。
	int playerNoTe = 0;	//プレイヤーの手
};

