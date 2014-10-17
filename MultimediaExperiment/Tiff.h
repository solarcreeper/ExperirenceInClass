#ifndef TIFF_H
#define TIFF_H
#include "Bmp.h"

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef long LONG;

struct IFH{
	WORD order;			 //���뷽ʽ��4d4d������ȣ�4949С������
	WORD version;		 //�ļ����ͣ�Ԥ���ֽڣ�ֵΪ2A
	DWORD offSet;	     //IFD�Ŀ�ʼλ��
};

struct Entry{
	WORD id;			  //����ID
	WORD type;			  //���ݳ��ȴ���
	DWORD length;		  //��������
	DWORD valueOffset;	  //ֵ����ֵ���ڵĵ�ַ
};

class Tiff{
public:
	Tiff(Bmp bmp);
	Tiff(char filename[64]);
	~Tiff();

	//һЩgetter&setter
	void setIFH();							//�ֶ�����IFH,���ڹ���һ���µ��ļ�
	void setEntryCount(int count);			//����Entry�����������ڹ����µ��ļ�
	void setEntry(Entry e, int entryNum);	//����Entry��ֵ�����ڹ����µ��ļ�����ȡ�ļ�
	IFH getIFH();							//��ȡIFH��ֵ
	int getEntryNum();						//��ȡEntry������
	

	//һЩ���ܺ���
	void open(char filename[64]);			//��
	void save(char filename[64], Bmp bmp);			//����
	void printIFH();						//��ӡIFH
	void printEntry(int num);				//��ӡEntry
	void toTiffFromBmp(Bmp bmp);			//��Bmpת��ΪTiff
	bool isOffset(int num);					//Entry����������Ƿ���ҪѰ��ƫ������
private:
	IFH IFH;
	WORD entryCount;
	Entry *entry;
};
#endif