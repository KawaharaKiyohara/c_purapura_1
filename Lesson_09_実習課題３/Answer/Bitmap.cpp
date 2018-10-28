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
	for (int y = 0; y < IMAGE_H; y++) {
		for (int x = 0; x < IMAGE_W; x++) {
			//モノクロにするぜ。
			float Y = m_image[y][x].r * 0.299f
					+ m_image[y][x].g * 0.587f
					+ m_image[y][x].b * 0.114f;

			m_image[y][x].r = Y;
			m_image[y][x].g = Y;
			m_image[y][x].b = Y;
		}
	}
}
/// <summary>
/// 画像をぼかす。
/// 4点サンプリングを行って、ぼかします。
/// </summary>
void Bitmap::ConvertBoke()
{

	//オリジナル画像。
	static SRgb m_originalImage[IMAGE_H][IMAGE_W];
	//オリジナルの画像を保存しておく。
	memcpy(m_originalImage, m_image, sizeof(m_originalImage));

	for (int y = 0; y < IMAGE_H; y++) {
		for (int x = 0; x < IMAGE_W; x++) {
			//ぼかす。
			int r, g, b;
			//近傍9ピクセルの平均を変換後のカラーとする。
			r = m_originalImage[y][x].r;
			g = m_originalImage[y][x].g;
			b = m_originalImage[y][x].b;
			r += m_originalImage[y][x+1].r;
			g += m_originalImage[y][x+1].g;
			b += m_originalImage[y][x+1].b;
			r += m_originalImage[y][x + 2].r;
			g += m_originalImage[y][x + 2].g;
			b += m_originalImage[y][x + 2].b;


			r += m_originalImage[y + 1][x].r;
			g += m_originalImage[y + 1][x].g;
			b += m_originalImage[y + 1][x].b;
			r += m_originalImage[y + 1][x+1].r;
			g += m_originalImage[y + 1][x+1].g;
			b += m_originalImage[y + 1][x+1].b;
			r += m_originalImage[y + 1][x + 2].r;
			g += m_originalImage[y + 1][x + 2].g;
			b += m_originalImage[y + 1][x + 2].b;

			r += m_originalImage[y + 2][x].r;
			g += m_originalImage[y + 2][x].g;
			b += m_originalImage[y + 2][x].b;
			r += m_originalImage[y + 2][x + 1].r;
			g += m_originalImage[y + 2][x + 1].g;
			b += m_originalImage[y + 2][x + 1].b;
			r += m_originalImage[y + 2][x + 2].r;
			g += m_originalImage[y + 2][x + 2].g;
			b += m_originalImage[y + 2][x + 2].b;
			

			m_image[y][x].r = r / 9;
			m_image[y][x].g = g / 9;
			m_image[y][x].b = b / 9;
		}
	}
}