#pragma once

class Player;
class Game;

class EnemyBase : public IGameObject
{
public:
	EnemyBase();
	~EnemyBase();
	/// <summary>
	/// ���W�̎擾�B
	/// </summary>
	/// <returns></returns>
	const CVector3& GetPosition() const
	{
		return m_position;
	}
	
	/// <summary>
	/// ���W�̐ݒ�B
	/// </summary>
	/// <param name="pos"></param>
	void SetPosition(const CVector3& pos)
	{
		m_position = pos;
	}
	void Move();
	void Rotate();
	void Update();
	bool Start();
protected:
	prefab::CSkinModelRender* m_modelRender = nullptr;	//!<���f�������_���[�B
	CVector3 m_position = CVector3::Zero;			//!<���W�B
	CQuaternion m_rotation = CQuaternion::Identity;	//!<��]
private:
	Player* m_player;
	Game* m_game;

};

