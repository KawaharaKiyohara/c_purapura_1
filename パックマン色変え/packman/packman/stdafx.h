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

//敵の数。
extern int g_enemyNum;

//食べ物の数。
extern int g_foodNum;