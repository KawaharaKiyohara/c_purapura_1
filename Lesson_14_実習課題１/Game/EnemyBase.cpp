#include "stdafx.h"
#include "EnemyBase.h"
#include "Player.h"
#include "Game.h"

EnemyBase::EnemyBase()
{
}


EnemyBase::~EnemyBase()
{
	DeleteGO(m_modelRender);
}

bool EnemyBase::Start()
{
	m_modelRender = NewGO<prefab::CSkinModelRender>(0);
	m_modelRender->Init(L"modelData/enemy.cmo" );

	m_modelRender->SetShadowCasterFlag(true);
	m_modelRender->SetShadowReceiverFlag(true);

	m_player = FindGO<Player>("Player");
	m_game = FindGO<Game>("Game");
	return true;
}
void EnemyBase::Move()
{
}
void EnemyBase::Rotate()
{
}
void EnemyBase::Update()
{
	if (m_game->IsGameOver() || m_game->IsGameClear()) {
		return;
	}
	//�ړ����������s�B
	Move();
	//��]���������s�B
	Rotate();

	const auto scale = CVector3(3.0f, 3.0f, 3.0f);
	m_modelRender->SetPRS(m_position, m_rotation, scale);

	CVector3 toPlayer = m_player->GetPosition() - m_position;

	auto mRot = CMatrix::Identity;
	mRot.MakeRotationFromQuaternion(m_rotation);
	CVector3 forward;
	forward.x = mRot.m[2][0];
	forward.y = mRot.m[2][1];
	forward.z = mRot.m[2][2];

	if (toPlayer.Length() < 300.0f) {
		//����p�𔻒�B
		toPlayer.Normalize();

		float angle = acosf(toPlayer.Dot(forward));
		if (fabsf(angle) < CMath::PI * 0.25f) {
			//����p45�x�ȓ��B
			//�Q�[���ɃQ�[���I�[�o�[��ʒm�B
			m_game->NotifyGameOver();
		}
	}
}