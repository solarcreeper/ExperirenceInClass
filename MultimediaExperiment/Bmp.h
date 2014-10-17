#ifndef BMP_H
#define BMP_H

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef long LONG;

struct BitmapHeader{
	//WORD  bpType;					//�ļ����ͣ������ǡ�BM�� 
	DWORD bpSize;					//�����ļ���С
	WORD  bpReserved1;				//������1
	WORD  bpReserved2;				//������2
	DWORD bpOffSize;				//���ļ���ʼ��λͼ����֮���ƫ����
};

struct  BitmapInfoHeader{
	DWORD bpInfoHeaderSize;			//λͼ��Ϣͷ����
	DWORD bpWidth;					//λͼ���
	DWORD bpHeight;					//λͼ����
	WORD  bpPlanes;					//λͼλ����
	WORD  bpCount;					//ÿ�����ص�λ��
	DWORD bpCompression;			//ͼ������ѹ������
	DWORD bpRealSize;				//ͼ�����ݵ���ʵ��С
	DWORD bpHResolution;			//ͼ��ˮƽ�ֱ���
	DWORD bpVResolution;			//ͼ��ֱ�ֱ���
	DWORD bpColorCount;				//ͼ��ʵ��ʹ�õ���ɫ������
	DWORD bpMColorCount;			//ͼ����Ҫ����ɫ������
};

struct RGBQUAD{
	short rgbBlue;					//��ɫ��Blue����
	short rgbGreen;					//��ɫ��Green����
	short rgbRed;					//��ɫ��Red����
	short rgbReserved;				//��ɫ�屣��ֵ
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
	//�ṹ������setter&getter
	void setBpHeader(BitmapHeader bh);
	void setBpInfoHeader(BitmapInfoHeader bih);
	void setRgbQuad(RGBQUAD quad);
	BitmapHeader getHeader();
	BitmapInfoHeader getInfoHeader();
	RGBQUAD getQUad();
	IAMGEDATA getImageData();

	//һЩ���ܺ���,��ӡ������
	void printBpHeader();
	void printBpInfoHeader();
	void printRgbQuad();
	void printBinaryQuad();
	void printBpImageData();
	void open(char filename[64]);
	void save(char filename[64]); 

	//һЩ�ı�ͼ����ɫ&...�ĺ���
	void toGrayImageByMax();    //���ֵ��
	void toGrayImageByAvg();	//ƽ��ֵ��
	void toGrayImageByWAvg(int weightedRed, int weightedGreen, int weightedBlue);	//��Ȩƽ��ֵ��

	BYTE getMax(BYTE red, BYTE green, BYTE blue);
	BYTE getAvg(BYTE red, BYTE green, BYTE blue);
	BYTE getWAvg(BYTE red, BYTE green, BYTE blue, int weightedRed, int weightedGreen, int weightedBlue);


	//******���½ӿ�ʵ�ֲ���*******
	//BpHeader�������ݵ�setter
	void setBpHeaderBpType(WORD type);
	void setBpHeaderBpSize(DWORD size);
	void setBpHeaderBpReserved(int reservedNum, WORD reserved);
	void setBpHeaderBpOffSize(DWORD offsize);
	//BpInfoHeader�������ݵ�setter
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
	//RGBQUAD�������ݵ�setter
	void setRGBQUADGreen(BYTE green);
	void setRGBQUADBlue(BYTE blue);
	void setRGBQUADRed(BYTE red);
	
	//BitmapHeader�ĸ�������getter
	WORD getBpHeaderType();
	DWORD getBpHeaderSize();
	WORD getBpHeaderReserved(int reservedNum);
	DWORD getBpHeaderOffSize();
	//BitmapInfoHeader�ĸ�������getter
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
	//RGBQUAD�ĸ�������getter
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