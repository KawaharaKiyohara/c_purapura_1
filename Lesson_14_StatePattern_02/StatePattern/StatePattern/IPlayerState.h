#pragma once

class IPlayerState {
public:
	virtual void Enter() = 0;
	virtual void Leave() = 0;
	virtual void Update() = 0;
	//ジャンプできる？
	virtual bool IsPossibleJump() = 0;
	//無敵？
	virtual bool IsInvincible() = 0;
};
