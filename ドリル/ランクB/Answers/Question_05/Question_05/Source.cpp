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
	//球と球との衝突判定。
	//GenerateSpheres関数はランダムな100個の球体を作成して、それをspheres配列に格納します。
	//生成された球体のうちいくつが、キャラクターを内包する球体を表すcharacterSphereと衝突しているかカウントしなさい。
	//
	//これを解く上でのヒント。
	//
	//二つの球体、aとbが衝突するのは、下記の条件を満たすとき、
	// aとbの距離をlとしたとき、
	// l < aの半径＋bの半径
	//

	//ランダムに球体を100個作成する。
	Sphere spheres[100];
	GenerateSpheres(spheres);
	
	//キャラクタを内包する球体を作る。
	Sphere characterSphere;
	characterSphere.position = {20.0f, 15.0f};
	characterSphere.radius = 60.0f;

	int count = 0;

	//ここから球と球の衝突判定を実装する。
	for (int i = 0; i < 100; i++) {
		Vector2 diff;
		diff.x = characterSphere.position.x - spheres[i].position.x;
		diff.y = characterSphere.position.y - spheres[i].position.y;
		float len = sqrt(diff.x * diff.x + diff.y * diff.y);

		float r = characterSphere.radius + spheres[i].radius;
		if (len < r) {
			//衝突してるね。
			count++;
		}
	}

	//答え合わせ。
	SubmissionAnswer(count);
	return 0;
}