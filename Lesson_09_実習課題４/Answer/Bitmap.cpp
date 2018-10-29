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
	fs.seekg(0, fstream::beg);		//ファイルの先頭に戻どる。
	uint32_t begPos = fs.tellg();	//現在のファイルの位置を取得。
	uint32_t fileSize = endPos - begPos;	//末尾-銭湯でファイルサイズを計算。

	//読み込むぜ。
	char* buf = new char[fileSize];
	fs.read(buf, fileSize);

	//ファイルヘッダーのアドレスを代入。
	BITMAPFILEHEADER* header = (BITMAPFILEHEADER*)buf;
	//ファイル情報ヘッダーのアドレスを代入。
	BITMAPINFOHEADER* infoHeader = (BITMAPINFOHEADER*)(buf + sizeof(BITMAPFILEHEADER));
	//ほんとは色々チェックがいるのだが、
	//フォーマットは24bitカラーで、解像度は512×512で決め打ちだっぜ！
	//適当にイメージにジャンプ。
	char* pImage = buf + header->bfOffBits;

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
#if 0 //課題のアンサー
	for (int i = 0; i < IMAGE_H * IMAGE_W; i++) {
		//モノクロにするぜ。
		float Y = m_image[i].r * 0.299f
				+ m_image[i].g * 0.587f
				+ m_image[i].b * 0.114f;

		m_image[i].r = Y;
		m_image[i].g = Y;
		m_image[i].b = Y;
	}
#endif
#if 0 //ハンズオンのアンサー
	//m_imageの先頭アドレスをpRgbに代入する。
	SRgb* pRgb = m_image;
	for (int i = 0; i < IMAGE_H * IMAGE_W; i++) {
		//pRgbの指している先の画素をモノクロにしていく。
		float Y = pRgb->r * 0.299f
			+ pRgb->g * 0.587f
			+ pRgb->b * 0.114f;

		pRgb->r = Y;
		pRgb->g = Y;
		pRgb->b = Y;

		//次
		pRgb++;
	}
#endif
}