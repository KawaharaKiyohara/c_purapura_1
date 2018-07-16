#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;

//2次元のベクトル構造体。
struct Vector2 {
	float x;
	float y;
};

//軸並行バウンディングボックス。
struct AABB {
	Vector2	vMax;	//箱の最大x座標と、最大y座標。
	Vector2	vMin;	//箱の最小x座標と、最大y座標。
};

int main()
{
	//AABBとAABBとの衝突判定。
	//GenerateAABBs関数はランダムな100個のAABBを作成して、それをaabbs配列に格納します。
	//生成されたAABBのうちいくつが、キャラクターのAABBを表すcharacterAabbと衝突しているかカウントしなさい。
	//AABBの詳しい説明は下記のURLを参照。
	//https://qiita.com/HIEMON/items/a392c34b602eb653c337
	//http://d.hatena.ne.jp/taiyakisun/20120205/1328410006
	//
	//これを解く上でのヒント。
	//二つのAABB、aとbが衝突するのは、下記の条件を満たすとき、
	// aの最大値 > bの最小値 && aの最小値 < bの最大値
	//

	//ランダムにAABBを100個作成する。
	AABB aabbs[100];
	GenerateAABBs(aabbs);

	AABB characterAabb;
	characterAabb.vMax = { 30.0f, 30.0f };		//characterAabbの最大値を決定。
	characterAabb.vMin = { -30.0f, -30.0f };	//characterAabbの最小値を決定。

	int count = 0;

	//ここからAABBとAABBの衝突判定を実装する。
	




	//答え合わせ。
	SubmissionAnswer(count);
	return 0;
}