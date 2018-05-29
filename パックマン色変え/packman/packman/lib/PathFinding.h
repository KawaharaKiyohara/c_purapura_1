#pragma once



#define LINK_NODE_MAX	4		//隣接ノードの最大数。
struct Vector2 {
	int x, y;
};
struct SNode {
	SNode* linkNode[LINK_NODE_MAX];		//隣接ノード。NULLであれば隣接ノードなし。
	SNode* parentNode;					//親のノード。
	int mapID;							//マップ番号。
	Vector2 pos;						//ノードの座標。
	int moveCost;						//移動コスト
	bool isDone;						//調査済みフラグ。
};
class CPathFinding {
public:
	CPathFinding();
	~CPathFinding();
	//ノードの構築。
	void BuildNodes();
	//ルートの検索
	//root		検索されたルートの格納先。
	//startPos	開始座標。
	//targetPos	目標座標。
	void FindRoot(std::vector<Vector2>& root, Vector2 startPos, Vector2 targetPos);
private:
	SNode		m_nodes[16][16];		//ノードの配列。
};