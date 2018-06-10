#pragma once
#include <vector>

struct Otimono {
	int posX;
	int posY;
	int dead = 0;
};

void OtimonoProgram();
void DrawOtimono();
void MoveOtimono();
extern std::vector<Otimono>	otimonoArray;	//—‚¿•¨‚Ì‰Â•Ï’·”z—ñB