#pragma once



#define LINK_NODE_MAX	4		//�אڃm�[�h�̍ő吔�B
struct Vector2 {
	int x, y;
};
struct SNode {
	SNode* linkNode[LINK_NODE_MAX];		//�אڃm�[�h�BNULL�ł���Ηאڃm�[�h�Ȃ��B
	SNode* parentNode;					//�e�̃m�[�h�B
	int mapID;							//�}�b�v�ԍ��B
	Vector2 pos;						//�m�[�h�̍��W�B
	int moveCost;						//�ړ��R�X�g
	bool isDone;						//�����ς݃t���O�B
};
class CPathFinding {
public:
	CPathFinding();
	~CPathFinding();
	//�m�[�h�̍\�z�B
	void BuildNodes();
	//���[�g�̌���
	//root		�������ꂽ���[�g�̊i�[��B
	//startPos	�J�n���W�B
	//targetPos	�ڕW���W�B
	void FindRoot(std::vector<Vector2>& root, Vector2 startPos, Vector2 targetPos);
private:
	SNode		m_nodes[16][16];		//�m�[�h�̔z��B
};