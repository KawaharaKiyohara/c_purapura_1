#pragma once

class IPlayerState {
public:
	virtual void Enter() = 0;
	virtual void Leave() = 0;
	virtual void Update() = 0;
	//�W�����v�ł���H
	virtual bool IsPossibleJump() = 0;
	//���G�H
	virtual bool IsInvincible() = 0;
};
