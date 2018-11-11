#include "pch.h"
#include "Bitmap.h"
#include <fstream>

using namespace std;


/// <summary>
/// コンストラクタ
/// </summary>
Bitmap::Bitmap()
{
}

/// <summary>
/// デストラクタ。
/// </summary>
Bitmap::~Bitmap()
{
}

/// <summary>
/// Bitmapをロード。
/// Bitmapの解像度は512×512である必要があります。
/// </summary>
/// <param name="filePath">読み込むファイルパス。</param>
/// <returns>
/// 読み込みに成功したらtrue、
/// 失敗したらfalseを返します。
/// </returns>
bool Bitmap::Load(const char* filePath)
{
	//ファイルストリームを作成。
	ifstream fs(filePath, std::ios::binary);

	if (fs.fail() == true) {
		//ファイルの読み込みに失敗した。
		return false;
	}
	//ファイルサイズを計算する。
	fs.seekg(0, fstream::end);		//ファイルの終端に移動する。
	uint32_t endPos = fs.tellg();	//現在のファイルの位置を取得。
	fs.clear();
	fs.seekg(0, fstream::beg);			//ファイルの先頭に戻どる。
	uint32_t begPos = fs.tellg();		//現在のファイルの位置を取得。
	uint32_t fileSize = endPos - begPos;	//末尾-先頭でファイルサイズを計算。

	//読み込むぜ。
	char* buf = new char[fileSize];
	fs.read(buf, fileSize);
	//bufが指している先にbitmapファイルのデータが読み込まれた。
	//bufが記憶しているアドレスをpにコピー。
	char* p = buf;

	//ハンズオン_1 ファイルヘッダーの中身を確認してみよう。
	//ファイルヘッダーのアドレスを代入。
	BITMAPFILEHEADER* header = (BITMAPFILEHEADER*)p;

	//ハンズオン_2 ファイル情報ヘッダーの中身を確認してみよう。
	//ファイル情報ヘッダーのアドレスを代入。
	p = (char*)(header + 1);
	BITMAPINFOHEADER* infoHeader = (BITMAPINFOHEADER*)p;
	
	//ハンズオン_3 画像データが格納されているメモリにジャンプ。
	p = (char*)(infoHeader + 1);
	char* pImage = p;

	//ハンズオン_4 ビットマップの情報をメンバ変数にコピーする。
	//ビットマップの情報をメンバ変数にコピー。
	memcpy(&m_bitmapHeader, header, sizeof(m_bitmapHeader));
	memcpy(&m_bitmapInfoHeader, infoHeader, sizeof(m_bitmapInfoHeader));
	memcpy(m_image, pImage, sizeof(m_image));

	//コピーが終わったのでもういらないので、もろもろ削除。
	//解放解放。
	delete[] buf;
	//ファイルを閉じる。
	fs.close();

	//読み込みが成功したのでtrueを返す。
	return true;
}
/// <summary>
/// Bitmapの保存。
/// </summary>
/// <param name="filePath">保存するファイルパス。</param>
/// <returns>
/// 保存に成功したらtrue、
/// 失敗したらfalseを返す。
/// </returns>
bool Bitmap::Save(const char* filePath)
{
	ofstream fs(filePath, std::ios::binary);

	if (fs.fail() == true) {
		//ファイルのオープンに失敗した。
		return false;
	}

	//書き込め―。
	fs.write((char*)&m_bitmapHeader, sizeof(m_bitmapHeader));
	fs.write((char*)&m_bitmapInfoHeader, sizeof(m_bitmapInfoHeader));
	fs.write((char*)m_image, sizeof(m_image));

	fs.close();
	//保存が成功したので、trueを返す。
	return true;
}
/// <summary>
/// 読み込んでいる画像データを白黒画像に変換する。
/// </summary>
void Bitmap::ConvertMonochrome()
{
	for (int y = 0; y < IMAGE_H; y++) {
		for (int x = 0; x < IMAGE_W; x++) {
			//モノクロにするぜ。
			float Y = m_image[y][x].r * 0.299f
				+ m_image[y][x].g * 0.587f
				+ m_image[y][x].b * 0.114f;

			m_image[y][x].r = (unsigned char)Y;
			m_image[y][x].g = (unsigned char)Y;
			m_image[y][x].b = (unsigned char)Y;
		}
	}
}