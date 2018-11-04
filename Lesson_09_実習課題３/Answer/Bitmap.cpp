#include "pch.h"
#include "Bitmap.h"
#include <fstream>
#include <algorithm>

using namespace std;


/// <summary>
/// �R���X�g���N�^
/// </summary>
Bitmap::Bitmap()
{
}

/// <summary>
/// �f�X�g���N�^�B
/// </summary>
Bitmap::~Bitmap()
{
}

/// <summary>
/// Bitmap�����[�h�B
/// Bitmap�̉𑜓x��512�~512�ł���K�v������܂��B
/// </summary>
/// <param name="filePath">�ǂݍ��ރt�@�C���p�X�B</param>
/// <returns>
/// �ǂݍ��݂ɐ���������true�A
/// ���s������false��Ԃ��܂��B
/// </returns>
bool Bitmap::Load(const char* filePath)
{
	//�t�@�C���X�g���[�����쐬�B
	ifstream fs(filePath, std::ios::binary);

	if (fs.fail() == true) {
		//�t�@�C���̓ǂݍ��݂Ɏ��s�����B
		return false;
	}
	//�t�@�C���T�C�Y���v�Z����B
	fs.seekg(0, fstream::end);		//�t�@�C���̏I�[�Ɉړ�����B
	uint32_t endPos = (uint32_t)fs.tellg();	//���݂̃t�@�C���̈ʒu���擾�B
	fs.clear();
	fs.seekg(0, fstream::beg);		//�t�@�C���̐擪�ɖ߂ǂ�B
	uint32_t begPos = (uint32_t)fs.tellg();	//���݂̃t�@�C���̈ʒu���擾�B
	uint32_t fileSize = endPos - begPos;	//����-�K���Ńt�@�C���T�C�Y���v�Z�B

	//�ǂݍ��ނ��B
	char* buf = new char[fileSize];
	fs.read(buf, fileSize);

	//�t�@�C���w�b�_�[�̃A�h���X�����B
	BITMAPFILEHEADER* header = (BITMAPFILEHEADER*)buf;
	//�t�@�C�����w�b�_�[�̃A�h���X�����B
	BITMAPINFOHEADER* infoHeader = (BITMAPINFOHEADER*)(buf + sizeof(BITMAPFILEHEADER));
	//�ق�Ƃ͐F�X�`�F�b�N������̂����A
	//�t�H�[�}�b�g��24bit�J���[�ŁA�𑜓x��512�~512�Ō��ߑł��������I
	//�K���ɃC���[�W�ɃW�����v�B
	char* pImage = buf + header->bfOffBits;

	//�r�b�g�}�b�v�̏��������o�ϐ��ɃR�s�[�B
	memcpy(&m_bitmapHeader, header, sizeof(m_bitmapHeader));
	memcpy(&m_bitmapInfoHeader, infoHeader, sizeof(m_bitmapInfoHeader));
	memcpy(m_image, pImage, sizeof(m_image));

	//�R�s�[���I������̂ł�������Ȃ��̂ŁA�������폜�B
	//�������B
	delete[] buf;
	//�t�@�C�������B
	fs.close();

	//�ǂݍ��݂����������̂�true��Ԃ��B
	return true;
}
/// <summary>
/// Bitmap�̕ۑ��B
/// </summary>
/// <param name="filePath">�ۑ�����t�@�C���p�X�B</param>
/// <returns>
/// �ۑ��ɐ���������true�A
/// ���s������false��Ԃ��B
/// </returns>
bool Bitmap::Save(const char* filePath)
{
	ofstream fs(filePath, std::ios::binary);

	if (fs.fail() == true) {
		//�t�@�C���̃I�[�v���Ɏ��s�����B
		return false;
	}

	//�������߁\�B
	fs.write((char*)&m_bitmapHeader, sizeof(m_bitmapHeader));
	fs.write((char*)&m_bitmapInfoHeader, sizeof(m_bitmapInfoHeader));
	fs.write((char*)m_image, sizeof(m_image));

	fs.close();
	//�ۑ������������̂ŁAtrue��Ԃ��B
	return true;
}
/// <summary>
/// �ǂݍ���ł���摜�f�[�^�𔒍��摜�ɕϊ�����B
/// </summary>
void Bitmap::ConvertMonochrome()
{
	for (int y = 0; y < IMAGE_H; y++) {
		for (int x = 0; x < IMAGE_W; x++) {
			//���m�N���ɂ��邺�B
			float Y = m_image[y][x].r * 0.299f
				+ m_image[y][x].g * 0.587f
				+ m_image[y][x].b * 0.114f;

			m_image[y][x].r = (unsigned char)Y;
			m_image[y][x].g = (unsigned char)Y;
			m_image[y][x].b = (unsigned char)Y;
		}
	}
}
/// <summary>
/// �摜����Ԃ���������������B
/// </summary>
void Bitmap::RemoveRColor()
{
	for (int y = 0; y < IMAGE_H; y++) {
		for (int x = 0; x < IMAGE_W; x++) {
			m_image[y][x].r = 0; //R��������������B
		}
	}
}
/// <summary>
/// �摜���ڂ����B
/// 4�_�T���v�����O���s���āA�ڂ����܂��B
/// </summary>
void Bitmap::ConvertBoke()
{
	//�I���W�i���摜�B
	SRgb m_originalImage[IMAGE_H][IMAGE_W];
	//�I���W�i���̉摜��ۑ����Ă����B
	memcpy(m_originalImage, m_image, sizeof(m_originalImage));

	for (int y = 0; y < IMAGE_H; y++) {
		for (int x = 0; x < IMAGE_W; x++) {
			//�ڂ����B
			int r, g, b;
			r = g = b = 0;
			//�ߖT9�s�N�Z���̕��ς�ϊ���̃J���[�Ƃ���B
			for (int k = 0; k < 3; k++) {

				int yy = y + k;
				if (yy >= IMAGE_H) {
					yy = y;
				}
				//1��ځB
				r += m_originalImage[yy][x].r;
				g += m_originalImage[yy][x].g;
				b += m_originalImage[yy][x].b;
				int xx = x + 1;
				if (xx >= IMAGE_W) {
					//�摜�̃T�C�Y�𒴂�����B
					xx = x;
				}
				r += m_originalImage[yy][xx].r;
				g += m_originalImage[yy][xx].g;
				b += m_originalImage[yy][xx].b;

				xx = x + 2;
				if (xx >= IMAGE_W) {
					//�摜�̃T�C�Y�𒴂�����B
					xx = x;
				}
				r += m_originalImage[yy][xx].r;
				g += m_originalImage[yy][xx].g;
				b += m_originalImage[yy][xx].b;
			}

			m_image[y][x].r = r / 9;
			m_image[y][x].g = g / 9;
			m_image[y][x].b = b / 9;
		}
	}
}
/// <summary>
/// �ǂݍ���ł���摜�̃R���g���X�g�����߂�B
/// </summary>
void Bitmap::UpContrast()
{
	for (int y = 0; y < IMAGE_H; y++) {
		for (int x = 0; x < IMAGE_W; x++) {
			unsigned char akarusa = max(m_image[y][x].r, m_image[y][x].g);
			akarusa = max(m_image[y][x].b, akarusa);

			if (akarusa > 127) {
				m_image[y][x].r = min( 255.0f, m_image[y][x].r * 1.5f);
				m_image[y][x].g = min( 255.0f, m_image[y][x].g * 1.5f);
				m_image[y][x].b = min( 255.0f, m_image[y][x].b * 1.5f);
			}
			else {
				m_image[y][x].r *= 0.5f;
				m_image[y][x].g *= 0.5f;
				m_image[y][x].b *= 0.5f;
			}
		}
	}
}
/// <summary>
/// �R���g���X�g�����߂�B
/// </summary>
/// <param name="power">�R���g���X�g�̋��x�B0.0�`1.0</param>
void Bitmap::UpContrast(float power)
{
	for (int y = 0; y < IMAGE_H; y++) {
		for (int x = 0; x < IMAGE_W; x++) {
			unsigned char akarusa = max(m_image[y][x].r, m_image[y][x].g);
			akarusa = max(m_image[y][x].b, akarusa);

			if (akarusa > 127) {
				m_image[y][x].r = min(255.0f, m_image[y][x].r * (1.0f + power));
				m_image[y][x].g = min(255.0f, m_image[y][x].g * (1.0f + power));
				m_image[y][x].b = min(255.0f, m_image[y][x].b * (1.0f + power));
			}
			else {
				m_image[y][x].r *= 1.0f - power;
				m_image[y][x].g *= 1.0f - power;
				m_image[y][x].b *= 1.0f - power;
			}
		}
	}
}
/// <summary>
/// �㉺���]�B
/// </summary>
void Bitmap::FlipUpDown()
{
	//�I���W�i���摜�B
	SRgb m_originalImage[IMAGE_H][IMAGE_W];
	//�I���W�i���̉摜��ۑ����Ă����B
	memcpy(m_originalImage, m_image, sizeof(m_originalImage));

	for (int y = 0; y < IMAGE_H; y++) {
		for (int x = 0; x < IMAGE_W; x++) {
			m_image[y][x] = m_originalImage[IMAGE_H - y - 1][x];
		}
	}
}

/// <summary>
/// ���E���]�B
/// </summary>
void Bitmap::FlipLeftRight()
{
	//�I���W�i���摜�B
	SRgb m_originalImage[IMAGE_H][IMAGE_W];
	//�I���W�i���̉摜��ۑ����Ă����B
	memcpy(m_originalImage, m_image, sizeof(m_originalImage));

	for (int y = 0; y < IMAGE_H; y++) {
		for (int x = 0; x < IMAGE_W; x++) {
			m_image[y][x] = m_originalImage[y][IMAGE_W - x - 1];
		}
	}
}