#pragma once
#include <Windows.h>

//文字色。
enum EnStringColor {
	enStringColor_Black,		//黒。
	enStringColor_DarkBlue,		//ダークブルー。
	enStringColor_DarkGreen,	//ダークグリーン。
	enStringColor_DarkCyan,		//ダークシアン。
	enStringColor_DarkRed,		//ダークレッド。
	enStringColor_DarkViolet,	//ダークバイオレット。
	enStringColor_DarkYellow,	//ダークイエロー。
	enStringColor_Gray,			//グレイ。
	enStringColor_LightGray,	//ライトグレイ。
	enStringColor_Blue,			//青。
	enStringColor_Green,		//緑。
	enStringColor_Cyan,			//シアン。
	enStringColor_Red,			//赤。
	enStringColor_Violet,		//バイオレット。
	enStringColor_Yellow,		//黄色。
	enStringColor_White,		//白。
};
/////////////////////////////////////////////////////
// グローバル関数の関数宣言。
/////////////////////////////////////////////////////



/*!----------------------------------------------------
 *@brief	kbcDrawMoji
 *	文字を描画する関数。
 *@details
 * 英数字しか描画できません。日本語を表示したい場合は、
 * 一文字だとしてもkbcDrawMojiRetuを使うように。
 *
 *@param[in]	posX		文字を描画したいX座標。
 *@param[in]	posY		文字を描画したいY座標。
 *@param[in]	moji		描画したい文字。
 *@param[in]	color		文字色。
 *@code
 		//使用例
 		//x座標：1、y座標:4の場所にAという文字を描画する。
 		kbcDrawMoji( 1, 4, 'A' );
 *@endcode
 ----------------------------------------------------*/
extern bool kbcDrawMoji(int posX, int posY, char moji, EnStringColor color = enStringColor_White);

/*!----------------------------------------------------
 *@brief	kbcDrwaMojiRetu
 * 文字列を描画する関数。
 *
 *@param[in]	posX		文字列を描画したいX座標。
 *@param[in]	posY		文字列を描画したいY座標。
 *@param[in]	mojiretu	描画したい文字列。
 *@param[in]	color		文字色。
 *@code
 		//使用例
 		//x座標：1、y座標:4の場所にHello worldという文字列を描画する。
 		kbcDrwaMojiRetu( 1, 4, "Hello world" );
 *@endcode
 ----------------------------------------------------*/ 
extern void kbcDrawMojiRetu(int startPosX, int posY, const char* mojiretu, EnStringColor color = enStringColor_White);

/*!----------------------------------------------------
 *@brief	kbcBeginFrame
 * フレームの開始に呼び出す関数。
 ----------------------------------------------------*/
extern void kbcBeginFrame();

/*!----------------------------------------------------
 *@brief	kbcBeginFrame
 * フレームの終了に呼び出す関数。
 ----------------------------------------------------*/
extern void kbcEndFrame();

