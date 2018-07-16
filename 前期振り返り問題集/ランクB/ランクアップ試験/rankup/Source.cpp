#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;

//2次元のベクトル構造体。
struct Vector2 {
	float x;
	float y;
};

//球。
struct Sphere {
	Vector2	position;	//球の中心座標。
	float radius;		//球の半径。
};

int main()
{
	// 【問題】
	//	球体の配列をキャラクターに近い順番になるように並び替えなさい。
	//
	// 【プログラムの説明】
	//  GenerateSpheres関数はランダムな100個の球体を作成して、それをspheres配列に格納します。	
	//  characterPositionはキャラクターの座標を表す。
	//	characterPositionとspheresとの距離を計算して、その距離が近い順番にsphere配列をソートしなさい。
	//

	//ランダムに球体を100個作成する。
	Sphere spheres[100];
	GenerateSpheres(spheres);
	
	//キャラクタの座標。
	Vector2 characerPosition = { 20.0f, 15.0f };

	//【ここからソートするプログラムを実装する。】
	


	//答え合わせ。
	SubmissionAnswer(spheres);
	return 0;
}