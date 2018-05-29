#include "stdafx.h"

//�}�b�v�̍����B
const int FRAME_BUFFER_HEIGHT = 20;
//�}�b�v�̕��B
const int FRAME_BUFFER_WIDTH = 20;

//�����o�b�t�@�B
static char sFrameBuffer[FRAME_BUFFER_HEIGHT][FRAME_BUFFER_WIDTH];
//�J���[�o�b�t�@�B
static EnStringColor sStringColorBuffer[FRAME_BUFFER_HEIGHT][FRAME_BUFFER_WIDTH];


#define     COL_INTENSITY     0x08     // ���P�x�}�X�N
#define     COL_RED_MASK     0x04     // �ԐF�r�b�g
#define     COL_GREEN_MASK 0x02     // �ΐF�r�b�g
#define     COL_BLUE_MASK   0x01     //  �F�r�b�g

void SetColor(int col)
{
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);     // �R���\�[���n���h���擾
	WORD attr = 0;     //  API �ɓn���A�g���r���[�g
	if (col & COL_INTENSITY)       // ���P�x�r�b�g�������Ă����
		attr |= FOREGROUND_INTENSITY;      //  �A�g���r���[�g�̍��P�x�r�b�g�𗧂Ă�
	if (col & COL_RED_MASK)
		attr |= FOREGROUND_RED;
	if (col & COL_GREEN_MASK)
		attr |= FOREGROUND_GREEN;
	if (col & COL_BLUE_MASK)
		attr |= FOREGROUND_BLUE;
	SetConsoleTextAttribute(hCons, attr);        // �F�w��
}


void kbcDrawMojiRetu(int startPosX, int posY, const char* mojiretu, EnStringColor color)
{
	for (int i = 0; mojiretu[i] != '\0'; i++) {
		kbcDrawMoji(startPosX + i, posY, mojiretu[i], color);
	}
}
bool kbcDrawMoji(int posX, int posY, char moji, EnStringColor color)
{
	//�t���[���o�b�t�@�̕��ƍ����𒴂��Ă��Ȃ����`�F�[�b�N�B
	if (posX < FRAME_BUFFER_WIDTH && posY < FRAME_BUFFER_HEIGHT) {
		sFrameBuffer[posY][posX] = moji;
		sStringColorBuffer[posY][posX] = color;
		//�`����
		return true;
	}
	//�`���Ȃ������B
	return false;
}
void kbcBeginFrame()
{
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

	//�����o�b�t�@���N���A�B
	memset(sFrameBuffer, 0, sizeof(sFrameBuffer));
	//�J���[�o�b�t�@���N���A�B
	memset(sStringColorBuffer, enStringColor_White, sizeof(sStringColorBuffer));
}
void kbcEndFrame()
{
	EnStringColor currentStringColor = enStringColor_White;
	//�ŏ��͕����𔒂ɃZ�b�g����B
	SetColor(currentStringColor);	
	//�t���[���o�b�t�@�̓��e����ʂɕ\������B
	for (int i = 0; i < FRAME_BUFFER_HEIGHT; i++) {
		for (int j = 0; j < FRAME_BUFFER_WIDTH; j++) {
			if (currentStringColor != sStringColorBuffer[i][j]) {
				//�F���ς�����B
				currentStringColor = sStringColorBuffer[i][j];
				SetColor(currentStringColor);
			}
			std::cout << sFrameBuffer[i][j];
		}
		std::cout << "\n";
	}

	//16�~���b����B
	Sleep(16);

	//�W���o�̓R���\�[���̃n���h�����擾�B
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
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