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
	//点とAABB(軸並行バウンディングボックス)との衝突判定。
	//GeneratePosition関数はランダムな100個の座標を作成して、それをpositions配列に格納します。
	//生成された座標のうちいくつが、キャラクターのAABBを表すcharacterAabbと衝突しているかカウントしなさい。
	//AABBの詳しい説明は下記のURLを参照。
	//https://qiita.com/HIEMON/items/a392c34b602eb653c337
	//http://d.hatena.ne.jp/taiyakisun/20120205/1328410006
	//
	//これを解く上でのヒント。
	//聞きなれない用語が多くて難しく感じるかもしれませんが、
	//実はとても簡単です。上のページの説明に惑わされずに難しく考えすぎない！
	//惑わされた人はAnswerを見てみるのもいいかも。
	//

	//ランダムに座標を100個作成する。
	Vector2 positions[100];
	GeneratePositions(positions);

	AABB characterAabb;
	characterAabb.vMax = { 30.0f, 30.0f };		//characterAabbの最大値を決定。
	characterAabb.vMin = { -30.0f, -30.0f };	//characterAabbの最小値を決定。

	int count = 0;

	//ここから点とAABBの衝突判定を実装する。
	



	//答え合わせ。
	SubmissionAnswer(count);
	return 0;
}