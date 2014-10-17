#ifndef TIFF_H
#define TIFF_H
#include "Bmp.h"

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef long LONG;

struct IFH{
	WORD order;			 //编码方式，4d4d大段优先，4949小段优先
	WORD version;		 //文件类型，预留字节，值为2A
	DWORD offSet;	     //IFD的开始位置
};

struct Entry{
	WORD id;			  //属性ID
	WORD type;			  //数据长度代号
	DWORD length;		  //数据数量
	DWORD valueOffset;	  //值或者值所在的地址
};

class Tiff{
public:
	Tiff(Bmp bmp);
	Tiff(char filename[64]);
	~Tiff();

	//一些getter&setter
	void setIFH();							//手动设置IFH,用于构造一个新的文件
	void setEntryCount(int count);			//设置Entry的数量，用于构造新的文件
	void setEntry(Entry e, int entryNum);	//设置Entry的值，用于构造新的文件，读取文件
	IFH getIFH();							//获取IFH的值
	int getEntryNum();						//获取Entry的数量
	

	//一些功能函数
	void open(char filename[64]);			//打开
	void save(char filename[64], Bmp bmp);			//保存
	void printIFH();						//打印IFH
	void printEntry(int num);				//打印Entry
	void toTiffFromBmp(Bmp bmp);			//从Bmp转换为Tiff
	bool isOffset(int num);					//Entry所存的数据是否需要寻找偏移数据
private:
	IFH IFH;
	WORD entryCount;
	Entry *entry;
};
#endif