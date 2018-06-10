#include <Windows.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

struct Otimono {
	int posX;
	int posY;
	int dead = 0;
};

//�v���C���[�̍\����
struct SPlayer {
	int posX;
	int posY;
	int score;
};


//�}�b�v�̍����B
const int FRAME_BUFFER_HEIGHT = 20;
//�}�b�v�̕��B
const int FRAME_BUFFER_WIDTH = 20;

char sFrameBuffer[FRAME_BUFFER_HEIGHT][FRAME_BUFFER_WIDTH];

int main()
{
	std::vector<Otimono>	otimonoArray;	//�������̉ϒ��z��B
	int gameCount = 0;

	//�������������B
	srand((unsigned)time(NULL));

	//�Q�����z��B���ȏ���p.256����z��Ɋւ���L�q������܂��B�������z���p.269
	int map[16][16] = {
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  0���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  1���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  2���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  3���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  4���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  5���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  6���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  7���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  8���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	//  9���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 10���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 11���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 12���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 13���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 14���
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },	// 15���
		
	};

	//�v���C���[�P�B
	SPlayer player[2];
	player[0].posX = 3;
	player[0].posY = 15;
	player[0].score = 0;
	//�v���C���[�Q�B
	player[1].posX = 12;
	player[1].posY = 15;
	player[1].score = 0;
	
	//��������Q�[�����[�v�B
	while (true) {
		//1�t���[���̊J�n�B
		//�t�H���g�̃T�C�Y�̐ݒ�B
		const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_FONT_INFOEX info = { sizeof info };
		info.dwFontSize.X = 32;
		info.dwFontSize.Y = 32;
		SetCurrentConsoleFontEx(hConsole, 0, &info);

		//�R���\�[���̏c�Ɖ��̍s����ݒ�B
		HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwSize = { 9999, 9999 };
		SetConsoleScreenBufferSize(
			hCons,			// HANDLE hConsoleOutput
			dwSize);        // COORD dwSiz

							//�R���\�[���̍�����ݒ�B
		SMALL_RECT consoleWindow = { 0, 0, 20, 20 };
		BOOL ret = SetConsoleWindowInfo(
			hCons, // HANDLE hConsoleOutput
			TRUE,           // BOOL bAbsolute
			&consoleWindow);// CONST SMALL_RECT *lpConsoleWindow

							//�t���[���o�b�t�@���N���A�B
		memset(sFrameBuffer, 0, sizeof(sFrameBuffer));
		//�w�i��`��B
		//�񎟌��z���map���Q�Ƃ��āA�w�i��`�悵�Ă����B
		for (int y = 0; y < 16; y++) {
			for (int x = 0; x < 16; x++) {
				if (map[y][x] == 0) {
					//2�����z���map[y][x]��0�������Ă�����A
					//���Wx, y�̏ꏊ�ɋ󔒕�����`�悷��B
					if (x < FRAME_BUFFER_WIDTH && y < FRAME_BUFFER_HEIGHT) {
						sFrameBuffer[y][x] = ' ';
					}
				}
				else if (map[y][x] == 1) {
					//2�����z���map[y][x]��1�������Ă�����A
					//���Wx, y�̏ꏊ��@��`�悷��B
					if (x < FRAME_BUFFER_WIDTH && y < FRAME_BUFFER_HEIGHT) {
						sFrameBuffer[y][x] = '@';
					}
				}
			}
		}
		//�v���C���[�P�̈ړ������B
		for (int playerNo = 0; playerNo < 2; playerNo++) {
			if (playerNo == 0) {
				//1�v���C���[�B
				//�v���C���[�P�̈ړ������B
				if (GetAsyncKeyState(VK_LEFT) != 0) {
					//���̃L�[�������ꂽ�Ƃ��̏����������ɋL�q����B
					player[playerNo].posX--;
				}
				if (GetAsyncKeyState(VK_RIGHT) != 0) {
					player[playerNo].posX++;
				}
			}
			else if (playerNo == 1) {
				//2�v���C���[�B
				//�����ăv���C���[�Q�̈ړ������B
				if (GetAsyncKeyState('A') != 0) {
					//���̃L�[�������ꂽ�Ƃ��̏����������ɋL�q����B
					player[playerNo].posX--;
				}
				if (GetAsyncKeyState('D') != 0) {
					player[playerNo].posX++;
				}
			}
			//�ǔ���B
			if (player[playerNo].posX < 1) {
				player[playerNo].posX = 1;
			}
			if (player[playerNo].posX > 14) {
				player[playerNo].posX = 14;
			}
			//�������Ƃ̏Փ˔���B
			for (int i = 0; i < otimonoArray.size(); i++) {
				if (otimonoArray[i].posX == player[playerNo].posX
					&& otimonoArray[i].posY == player[playerNo].posY
					) {
					otimonoArray[i].dead = 1;
					//�Q�b�g�o���Ă�����J�E���g�A�b�v�B
					player[playerNo].score++;
				}
			}
			//�v���C���[�P��`�悷��B
			if (player[playerNo].posX < FRAME_BUFFER_WIDTH && player[playerNo].posY < FRAME_BUFFER_HEIGHT) {
				sFrameBuffer[player[playerNo].posY][player[playerNo].posX] = 'P';		
			}
		}

		//�������̃v���O���������s�B
		gameCount++;
		if (gameCount == 10) {
			//30�t���[���o�߂�����V�����������𔭐�������B
			Otimono otimono;
			//��������X���W�������_���Ō���B
			otimono.posX = (rand() % 14) + 1;
			otimono.posY = 0;
			//�Q�[���J�E���g��0�ɖ߂��B
			gameCount = 0;
			otimonoArray.push_back(otimono);
		}
		//�S�Ă̗������𗎉�������B
		for (auto& otimono : otimonoArray) {
			if ((gameCount % 5) == 0) {
				//5�t���[���Ɉ�x��������B
				otimono.posY += 1;
			}
		}
		//���X�g����폜�B	
		otimonoArray.erase(std::remove_if(otimonoArray.begin(), otimonoArray.end(), [&](auto& otimono)->bool {
			return otimono.posY == 18 || otimono.dead == 1;
		}), otimonoArray.end());

		//��������`��B
		for (auto& otimono : otimonoArray) {
			if (otimono.posX < FRAME_BUFFER_WIDTH && otimono.posX < FRAME_BUFFER_HEIGHT) {
				sFrameBuffer[otimono.posY][otimono.posX] = '*';
			}
		}

		//�X�R�A��\������B
		char scoreText[256];
		sprintf_s(scoreText, "Player1�@�X�R�A %d", player[0].score);
		for (int i = 0; scoreText[i] != '\0'; i++) {
			sFrameBuffer[18][0 + i] = scoreText[i];
		}
		sprintf_s(scoreText, "Player2�@�X�R�A %d", player[1].score);
		for (int i = 0; scoreText[i] != '\0'; i++) {
			sFrameBuffer[19][0 + i] = scoreText[i];
		}
		//1�t���[���̏I���B
		//�t���[���o�b�t�@�̓��e����ʂɕ\������B
		for (int i = 0; i < FRAME_BUFFER_HEIGHT; i++) {
			for (int j = 0; j < FRAME_BUFFER_WIDTH; j++) {
				std::cout << sFrameBuffer[i][j];
			}
			std::cout << "\n";
		}
		//32�~���b����B
		Sleep(16);
		//�W���o�̓R���\�[���̃n���h�����擾�B
		hCons = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos;
		pos.X = 0;
		pos.Y = 0;
		//�W���R���\�[���̃J�[�\����0�s�ځA0��ɖ߂��B
		SetConsoleCursorPosition(hCons, pos);
		CONSOLE_CURSOR_INFO cci;
		// CONSOLE_CURSOR_INFO�\���̂̌��݂̏�Ԃ��擾����
		GetConsoleCursorInfo(hCons, &cci);
		// �����o�ϐ��ł���bVisible���J�[�\���̕\���E��\���𐧌䂷��ϐ��Ȃ̂ŁA�����FALSE�ɂ��鎖�ŃJ�[�\�����\���ɂł���
		cci.bVisible = FALSE;
		// �ύX�����\���̏����R���\�[��Window�ɃZ�b�g����
		SetConsoleCursorInfo(hCons, &cci);
	}

	return 0;
}