#pragma once

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "lib/consoleLib.h"
#include "lib/PathFinding.h"


//�}�b�v��`�B
extern int g_map[16][16];
//�p�X�t�@�C���f�B���O�B
extern CPathFinding g_pathFinding;

///////////////////////////////////
//��������v���C���[�֌W�B
///////////////////////////////////
extern int playerIsDead;
extern int playerPosX;
extern int playerPosY;