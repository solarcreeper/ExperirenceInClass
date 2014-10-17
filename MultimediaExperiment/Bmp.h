#ifndef BMP_H
#define BMP_H

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef long LONG;

struct BitmapHeader{
	//WORD  bpType;					//文件类型，必须是“BM” 
	DWORD bpSize;					//整个文件大小
	WORD  bpReserved1;				//保留字1
	WORD  bpReserved2;				//保留字2
	DWORD bpOffSize;				//从文件开始到位图数据之间的偏移量
};

struct  BitmapInfoHeader{
	DWORD bpInfoHeaderSize;			//位图信息头长度
	DWORD bpWidth;					//位图宽度
	DWORD bpHeight;					//位图长度
	WORD  bpPlanes;					//位图位面数
	WORD  bpCount;					//每个像素的位数
	DWORD bpCompression;			//图像数据压缩类型
	DWORD bpRealSize;				//图像数据的真实大小
	DWORD bpHResolution;			//图像水平分辨率
	DWORD bpVResolution;			//图像垂直分辨率
	DWORD bpColorCount;				//图像实际使用的颜色索引数
	DWORD bpMColorCount;			//图像重要的颜色索引数
};

struct RGBQUAD{
	short rgbBlue;					//调色板Blue分量
	short rgbGreen;					//调色板Green分量
	short rgbRed;					//调色板Red分量
	short rgbReserved;				//调色板保留值
};

struct IAMGEDATA{
	BYTE blue;
	BYTE green;
	BYTE red;
};

class Bmp{
public:
	Bmp(char filename[64]);
	~Bmp();
	//结构体整体setter&getter
	void setBpHeader(BitmapHeader bh);
	void setBpInfoHeader(BitmapInfoHeader bih);
	void setRgbQuad(RGBQUAD quad);
	BitmapHeader getHeader();
	BitmapInfoHeader getInfoHeader();
	RGBQUAD getQUad();
	IAMGEDATA getImageData();

	//一些功能函数,打印，保存
	void printBpHeader();
	void printBpInfoHeader();
	void printRgbQuad();
	void printBinaryQuad();
	void printBpImageData();
	void open(char filename[64]);
	void save(char filename[64]); 

	//一些改变图像颜色&...的函数
	void toGrayImageByMax();    //最大值法
	void toGrayImageByAvg();	//平均值法
	void toGrayImageByWAvg(int weightedRed, int weightedGreen, int weightedBlue);	//加权平均值法

	BYTE getMax(BYTE red, BYTE green, BYTE blue);
	BYTE getAvg(BYTE red, BYTE green, BYTE blue);
	BYTE getWAvg(BYTE red, BYTE green, BYTE blue, int weightedRed, int weightedGreen, int weightedBlue);


	//******以下接口实现部分*******
	//BpHeader各个数据的setter
	void setBpHeaderBpType(WORD type);
	void setBpHeaderBpSize(DWORD size);
	void setBpHeaderBpReserved(int reservedNum, WORD reserved);
	void setBpHeaderBpOffSize(DWORD offsize);
	//BpInfoHeader各个数据的setter
	void setBpInfoHeaderSize(DWORD size);
	void setBpInfoHeaderBpWidth(DWORD width);
	void setBpInfoHeaderBpHeight(DWORD height);
	void setBpInfoHeaderBpPlanes(WORD planes);
	void setBpInfoHeaderBpCount(WORD count);
	void setBpInfoHeaderBpCompression(DWORD compression);
	void setBpInfoHeaderBpRealSize(DWORD realsize);
	void setBpInfoHeaderBpHResolution(DWORD resolution);
	void setBpInfoHeaderBpVResolution(DWORD resolution);
	void setBpInfoHeaderBpColorCount(DWORD count);
	void setBpInfoHeaderBpMColorCount(DWORD mcount);
	//RGBQUAD各个数据的setter
	void setRGBQUADGreen(BYTE green);
	void setRGBQUADBlue(BYTE blue);
	void setRGBQUADRed(BYTE red);
	
	//BitmapHeader的各个数据getter
	WORD getBpHeaderType();
	DWORD getBpHeaderSize();
	WORD getBpHeaderReserved(int reservedNum);
	DWORD getBpHeaderOffSize();
	//BitmapInfoHeader的各个数据getter
	DWORD getBpInfoHeaderSize();
	DWORD getBpInfoHeaderBpWidth();
	DWORD getBpInfoHeaderBpHeight();
	WORD getBpInfoHeaderBpPlanes();
	WORD getBpInfoHeaderBpCount();
	DWORD getBpInfoHeaderBpCompression();
	DWORD getBpInfoHeaderBpRealSize();
	DWORD getBpInfoHeaderBpHResolution();
	DWORD getBpInfoHeaderBpVResolution();
	DWORD getBpInfoHeaderBpColorCount();
	DWORD getBpInfoHeaderBpMColorCount();
	//RGBQUAD的各个数据getter
	BYTE getRGBQUADBlue();
	BYTE getRGBQUADGreen();
	BYTE getRGBQUADRed();


	IAMGEDATA *imagedata;
private:
	BitmapHeader bpHeader;
	BitmapInfoHeader bpInfoHeader;
	RGBQUAD rgbQUAD[256];
	RGBQUAD binaryQUAD[2];
	
	int *imageIndex;
};
#endif