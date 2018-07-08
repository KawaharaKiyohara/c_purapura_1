#pragma once
#include <Windows.h>

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
 *@code
 		//使用例
 		//x座標：1、y座標:4の場所にAという文字を描画する。
 		kbcDrawMoji( 1, 4, 'A' );
 *@endcode
 ----------------------------------------------------*/
extern bool kbcDrawMoji(int posX, int posY, char moji);

/*!----------------------------------------------------
 *@brief	kbcDrwaMojiRetu
 * 文字列を描画する関数。
 *
 *@param[in]	posX		文字列を描画したいX座標。
 *@param[in]	posY		文字列を描画したいY座標。
 *@param[in]	mojiretu	描画したい文字列。
 *@code
 		//使用例
 		//x座標：1、y座標:4の場所にHello worldという文字列を描画する。
 		kbcDrwaMojiRetu( 1, 4, "Hello world" );
 *@endcode
 ----------------------------------------------------*/ 
extern void kbcDrawMojiRetu(int startPosX, int posY, const char* mojiretu);

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

