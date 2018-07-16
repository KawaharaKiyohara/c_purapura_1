#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;

//2次元のベクトル構造体。
struct Vector2 {
	float x;
	float y;
};


int main()
{
	//GeneratePosition関数はランダムな100個の座標を作成して、それをpositions配列に格納します。
	//この時、characterPositionから、50以上離れてる座標の数をカウント。
	//２点間の距離は下記のような計算で求めることができます。
	//
	/*0番目の点とキャラクターとの距離を計算するサンプルコード。
	
		//キャラクターから0番目の点に向かって伸びるベクトルを計算する。
		Vector2 diff;
		diff.x = characterPosition.x - positions[0].x;
		diff.y = characterPosition.y - positions[0].y;
		//三平方の定理を使って、diffの大きさを求める。
		float t = diff.x * diff.x + diff.y * diff.y;
		//sqrtはC言語の標準関数で、引数で渡された数字の平方根を計算してくれます。
		float dist = sqrt( t );
	*/
	//ランダムに座標を作成。
	Vector2 positions[100];
	GeneratePositions(positions);

	//キャラの座標。
	Vector2 characterPosition = {20.0f, 30.0f};
	int count = 0;
	//ここから距離を調べるコードを記述する。





	//答え合わせ。
	SubmissionAnswer(count);
	return 0;
}