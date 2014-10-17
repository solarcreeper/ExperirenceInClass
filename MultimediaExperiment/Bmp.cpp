#include "Bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

Bmp::Bmp(char filename[64]){
	this->open(filename);
}

Bmp::~Bmp(){

}

void Bmp::setBpHeader(BitmapHeader bh){
	this->bpHeader = bh;
}

void Bmp::setBpInfoHeader(BitmapInfoHeader bih){
	this->bpInfoHeader = bih;
}

//void Bmp::setRgbQuad(RGBQUAD quad){
//	this->rgbQUAD = quad;
//}

BitmapHeader Bmp::getHeader(){
	return this->bpHeader;
}

BitmapInfoHeader Bmp::getInfoHeader(){
	return this->bpInfoHeader;
}

//RGBQUAD Bmp::getQUad(){
//	return this->rgbQUAD;
//}

void Bmp::printBpHeader(){
	//cout << "BitmapType: " << this->bpHeader.bpType << endl;
	cout << "BitmapSize: " << this->bpHeader.bpSize << endl;
	cout << "BitmapReserved1: " << this->bpHeader.bpReserved1 << endl;
	cout << "BitmapReserved2: " << this->bpHeader.bpReserved2 << endl;
	cout << "BitmapOffSize: " << this->bpHeader.bpOffSize << endl;
}

void Bmp::printBpInfoHeader(){
	cout << "InfoHeaderSize: " << this->bpInfoHeader.bpInfoHeaderSize << endl;
	cout << "BitmapWidth: " << this->bpInfoHeader.bpWidth << endl;
	cout << "BitmapHeight: " << this->bpInfoHeader.bpHeight << endl;
	cout << "BitmapPlanes: " << this->bpInfoHeader.bpPlanes << endl;
	cout << "BitmapCount: " << this->bpInfoHeader.bpCount << endl;
	cout << "Compression: " << this->bpInfoHeader.bpCompression << endl;
	cout << "ImageSize: " << this->bpInfoHeader.bpRealSize << endl;
	cout << "HResolution: " << this->bpInfoHeader.bpHResolution << endl;
	cout << "VResolution: " << this->bpInfoHeader.bpVResolution << endl;
	cout << "ColorCount: " << this->bpInfoHeader.bpColorCount << endl;
	cout << "MColorCount: " << this->bpInfoHeader.bpMColorCount << endl;
}

void Bmp::printRgbQuad(){
	for (int i = 0; i < this->bpInfoHeader.bpColorCount; i++){
		cout << rgbQUAD[i].rgbBlue << "," << rgbQUAD[i].rgbGreen << "," << rgbQUAD[i].rgbRed << endl;
	}
}

void Bmp::printBinaryQuad(){
	
}

void Bmp::printBpImageData(){

}

void Bmp::open(char filename[64]){
	int width, height;
	WORD bpType;
	FILE *fin;
	fopen_s(&fin, filename, "rb");
	if (fin == NULL){ return; }                                   //如果未读入，直接退出
	fread(&bpType, 1, sizeof(bpType), fin);
	if (bpType != 0x4d42){ return; };
	fread(&this->bpHeader, 1, sizeof(BitmapHeader), fin);				//开始读取
	fread(&this->bpInfoHeader, 1, sizeof(BitmapInfoHeader), fin);
	cout << filename << "'s header:" << endl;
	this->printBpHeader();
	cout << endl << filename << "s infoHeader:" << endl;
	this->printBpInfoHeader();
	width = this->bpInfoHeader.bpWidth;
	height = this->bpInfoHeader.bpHeight;

	switch (this->bpInfoHeader.bpCount){
	case 1:
		for (int i = 0; i < 2; i++){
			fread(&this->binaryQUAD[i].rgbBlue, 1, sizeof(BYTE), fin);
			fread(&this->binaryQUAD[i].rgbGreen, 1, sizeof(BYTE), fin);
			fread(&this->binaryQUAD[i].rgbRed, 1, sizeof(BYTE), fin);
			fread(&this->binaryQUAD[i].rgbReserved, 1, sizeof(BYTE), fin);
		}
		//二值图像的读取
		break;
	case 4:
		for (int i = 0; i < this->bpInfoHeader.bpColorCount; i++){
			fread(&this->rgbQUAD[i].rgbBlue, 1, sizeof(BYTE), fin);
			fread(&this->rgbQUAD[i].rgbGreen, 1, sizeof(BYTE), fin);
			fread(&this->rgbQUAD[i].rgbRed, 1, sizeof(BYTE), fin);
			fread(&this->rgbQUAD[i].rgbReserved, 1, sizeof(BYTE), fin);
		}
		//16色图像读取
		break;
	case 8:
		for (int i = 0; i < this->bpInfoHeader.bpColorCount; i++){
			fread(&this->rgbQUAD[i].rgbBlue, 1, sizeof(BYTE), fin);
			fread(&this->rgbQUAD[i].rgbGreen, 1, sizeof(BYTE), fin);
			fread(&this->rgbQUAD[i].rgbRed, 1, sizeof(BYTE), fin);
			fread(&this->rgbQUAD[i].rgbReserved, 1, sizeof(BYTE), fin);
		}
		this->imageIndex = new int[width*height];
		for (int i = 0; i < height; i++){
			for (int j = 0; j < width; j++){
				imageIndex[i*height + j] = 0;
				fread(&imageIndex[i*height + j], 1, sizeof(BYTE), fin);
			}
		}
		//256色图像读取
		break;
	case 24:
		//24位真彩色图像读取
		this->imagedata = new IAMGEDATA[width*height];
		for (int i = 0; i < height; i++){                  //初始化图像数组
			for (int j = 0; j < width; j++){
				imagedata[i * height + j].blue = 0;
				imagedata[i * height + j].green = 0;
				imagedata[i * height + j].red = 0;
			}
		}
		for (int i = 0; i < height; i++){
			for (int j = 0; j < width; j++){
				fread(&imagedata[i*height + j].red, sizeof(BYTE), 1, fin);
				//cout << setbase(16) << (int)imagedata[i*height + j].red << " ";
				fread(&imagedata[i*height + j].green, sizeof(BYTE), 1, fin);
				//cout << setbase(16) << (int)imagedata[i*height + j].green << " ";
				fread(&imagedata[i*height + j].blue, sizeof(BYTE), 1, fin);
				//cout << setbase(16) << (int)imagedata[i*height + j].blue << endl;
			}
		}
		/*for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
		cout << imagedata[i*height + j].red << " ";
		cout << imagedata[i*height + j].green << " ";
		cout << imagedata[i*height + j].blue << endl;
		}
		}*/
		fclose(fin);
		break;
	default:
		break;
	}

}

void Bmp::save(char filename[64]){
	FILE *fout;
	/*if (fopen_s(&fout, filename, "wb") == NULL){
		cout << "create file error!" << endl;
		return;
	}*/
	fopen_s(&fout, filename, "w+b");
	WORD bpType = 0x4d42;
	fwrite(&bpType, sizeof(WORD), 1, fout);
	fwrite(&bpHeader, sizeof(BitmapHeader), 1, fout);
	fwrite(&bpInfoHeader, sizeof(BitmapInfoHeader), 1, fout);
	int width = this->bpInfoHeader.bpWidth;
	int height = this->bpInfoHeader.bpHeight;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			fwrite(&imagedata[i*height + j].red, sizeof(BYTE), 1, fout);
			fwrite(&imagedata[i*height + j].green, sizeof(BYTE), 1, fout);
			fwrite(&imagedata[i*height + j].blue, sizeof(BYTE), 1, fout);
		}
	}
	fclose(fout);
}



void Bmp::toGrayImageByMax(){
	int width = this->bpInfoHeader.bpWidth;
	int height = this->bpInfoHeader.bpHeight;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			BYTE red = imagedata[i*height + j].red;
			BYTE green = imagedata[i*height + j].green;
			BYTE blue = imagedata[i*height + j].blue;
			BYTE max = this->getMax(red, green, blue);
			imagedata[i*height + j].red = max;
			imagedata[i*height + j].green = max;
			imagedata[i*height + j].blue = max;
		}
	}
}

void Bmp::toGrayImageByAvg(){
	int width = this->bpInfoHeader.bpWidth;
	int height = this->bpInfoHeader.bpHeight;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			BYTE red = imagedata[i*height + j].red;
			BYTE green = imagedata[i*height + j].green;
			BYTE blue = imagedata[i*height + j].blue;
			BYTE avg = this->getAvg(red, green, blue);
			imagedata[i*height + j].red = avg;
			imagedata[i*height + j].green = avg;
			imagedata[i*height + j].blue = avg;
		}
	}
}

void Bmp::toGrayImageByWAvg(int weightedRed, int weightedGreen, int weightedBlue){
	int width = this->bpInfoHeader.bpWidth;
	int height = this->bpInfoHeader.bpHeight;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			BYTE red = imagedata[i*height + j].red;
			BYTE green = imagedata[i*height + j].green;
			BYTE blue = imagedata[i*height + j].blue;
			BYTE weightedAvg = this->getWAvg(red, green, blue, weightedRed, weightedGreen, weightedBlue);
			imagedata[i*height + j].red = weightedAvg;
			imagedata[i*height + j].green = weightedAvg;
			imagedata[i*height + j].blue = weightedAvg;
		}
	}
}

BYTE Bmp::getMax(BYTE red, BYTE green, BYTE blue){
	BYTE temp = red;
	if (green > temp){
		temp = green;
	}
	if (blue > temp){
		temp = green;
	}
	return temp;
}

BYTE Bmp::getAvg(BYTE red, BYTE green, BYTE blue){
	return (red + green + blue) / 3;
}

BYTE Bmp::getWAvg(BYTE red, BYTE green, BYTE blue, int weightedRed, int weightedGreen, int weightedBlue){
	return (red*weightedRed + green*weightedGreen + blue*weightedBlue) / 100;
}

DWORD Bmp::getBpInfoHeaderBpWidth(){
	return this->bpInfoHeader.bpWidth;
}

DWORD Bmp::getBpInfoHeaderBpHeight(){
	return this->bpInfoHeader.bpHeight;
}