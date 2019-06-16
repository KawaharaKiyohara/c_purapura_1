#pragma once

class Player;
class Game;

class EnemyBase : public IGameObject
{
public:
	EnemyBase();
	~EnemyBase();
	/// <summary>
	/// 座標の取得。
	/// </summary>
	/// <returns></returns>
	const CVector3& GetPosition() const
	{
		return m_position;
	}
	
	/// <summary>
	/// 座標の設定。
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
	prefab::CSkinModelRender* m_modelRender = nullptr;	//!<モデルレンダラー。
	CVector3 m_position = CVector3::Zero;			//!<座標。
	CQuaternion m_rotation = CQuaternion::Identity;	//!<回転
private:
	Player* m_player;
	Game* m_game;

};

