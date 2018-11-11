#pragma once

#include <stdint.h>

#pragma pack(2)
/// <summary>
/// Bitmapファイルのヘッダー構造体。
/// </summary>
struct BITMAPFILEHEADER {
	uint16_t bfType;		//ファイルタイプ。通常はBM。
	uint32_t bfSize;		//ファイルサイズ(byte)
	uint16_t bfReserved1;	//予約領域。常に０。
	uint16_t bfReserved2;	//予約領域。常に０。
	uint32_t bfOffBits;		//ファイルの先頭から画像データまでのオフセット(byte)
};
/// <summary>
/// BITMAP情報ヘッダ。
/// </summary>
struct BITMAPINFOHEADER {
	uint32_t biSize;			//情報ヘッダサイズ。
	uint32_t biWidth;			//画像の幅。
	uint32_t biHeight;			//画像の高さ。
	uint16_t biPlanes;			//プレーン数。
	uint16_t biBitCount;		//色ビット数。1,4,8,(16),24,32。
	uint32_t biCompression;		//圧縮形式。0,1,2,3
	uint32_t biSizeImage;		//画像データサイズ。
	uint32_t biXPixPerMeter;	//水平解像度。[dot/m]
	uint32_t biYPixPerMeter;	//垂直解像度。[dot/m]
	uint32_t biClrUsed;			//格納パレット数。０の場合もある。
	uint32_t biCirImportant;	//重要色数。０の場合もある。
};

#pragma pack()
/// <summary>
/// Bitmapクラス。
/// </summary>
class Bitmap
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Bitmap();

	/// <summary>
	/// デストラクタ。
	/// </summary>
	~Bitmap();

	/// <summary>
	/// Bitmapをロード。
	/// Bitmapの解像度は512×512である必要があります。
	/// </summary>
	/// <param name="filePath">読み込むファイルパス。</param>
	/// <returns>
	/// 読み込みに成功したらtrue、
	/// 失敗したらfalseを返します。
	/// </returns>
	bool Load(const char* filePath);

	/// <summary>
	/// Bitmapの保存。
	/// </summary>
	/// <param name="filePath">保存するファイルパス。</param>
	/// <returns>
	/// 保存に成功したらtrue、
	/// 失敗したらfalseを返す。
	/// </returns>
	bool Save(const char* filePath);
	/// <summary>
	/// 読み込んでいる画像データを白黒画像に変換する。
	/// </summary>
	void ConvertMonochrome();
private:

	/// <summary>
	/// 1ドットの画素を表す構造体。
	/// </summary>
	struct SRgb {
		unsigned char r;	//R成分。unsignedは符号なしを表す修飾子。
		unsigned char g;	//G成分。unsignedは符号なしを表す修飾子。
		unsigned char b;	//b成分。unsignedは符号なしを表す修飾子。
	};

	static const int IMAGE_W = 512;			//画像の横幅。
	static const int IMAGE_H = 512;			//画像の縦幅。
	
	BITMAPFILEHEADER m_bitmapHeader;		//ビットマップファイルのヘッダー。
											//Load関数を実行すると、読み込んだビットマップ画像のヘッダーがコピーされます。
	BITMAPINFOHEADER m_bitmapInfoHeader;	//ビットマップファイルの情報ヘッダー。
											//Load関数を実行すると、読み込んだビットマップの情報ヘッダーがコピーされます。
	SRgb m_image[IMAGE_H][IMAGE_W];			//画像のイメージ。
private:
};

