#pragma once

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "lib/consoleLib.h"
#include "lib/PathFinding.h"


//マップ定義。
extern int g_map[16][16];
//パスファインディング。
extern CPathFinding g_pathFinding;

///////////////////////////////////
//ここからプレイヤー関係。
///////////////////////////////////
extern int playerIsDead;
extern int playerPosX;
extern int playerPosY;