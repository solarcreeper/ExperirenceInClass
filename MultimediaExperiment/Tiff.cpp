#include "Tiff.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

Tiff::Tiff(Bmp bmp){
	this->entry = new Entry[5];
	this->toTiffFromBmp(bmp);
	this->save("hahah.tif", bmp);
}

Tiff::Tiff(char filename[64]){
	this->open(filename);
}

Tiff::~Tiff(){

}

void Tiff::open(char filename[64]){
	FILE *fin;
	fopen_s(&fin, filename, "rb");
	if (fin == NULL){ return; };
	fread(&this->IFH, 1, sizeof(IFH), fin);
	fread(&this->entryCount, 1, sizeof(WORD), fin);
	this->entry = new Entry[entryCount];
	for (int i = 0; i < entryCount; i++){
		fread(&entry[i].id, 1, sizeof(WORD), fin);
		fread(&entry[i].type, 1, sizeof(WORD), fin);
		fread(&entry[i].length, 1, sizeof(DWORD), fin);
 		fread(&entry[i].valueOffset, 1, sizeof(DWORD), fin);
	}
	fclose(fin);
}

void Tiff::save(char filename[64], Bmp bmp){
	FILE *fout;
	fopen_s(&fout, filename, "wb");
	fwrite(&IFH, 1, sizeof(IFH), fout);
	fwrite(&entryCount, 1, sizeof(WORD), fout);
	for (int i = 0; i < entryCount; i++){
		fwrite(&entry[i].id, 1, sizeof(WORD), fout);
		fwrite(&entry[i].type, 1, sizeof(WORD), fout);
		fwrite(&entry[i].length, 1, sizeof(DWORD), fout);
		fwrite(&entry[i].valueOffset, 1, sizeof(DWORD), fout);
	}
	fwrite(&bmp.imagedata, 1, sizeof(bmp.imagedata), fout);
	fclose(fout);
}

void Tiff::setIFH(){
	this->IFH.order = 0x4d4d;
	this->IFH.version = 0x002a;
	this->IFH.offSet = 0x0008;
}

void Tiff::setEntryCount(int num){
	this->entryCount = num;
}

void Tiff::setEntry(Entry e, int num){
	this->entry[num] = e;
}

IFH Tiff::getIFH(){
	return this->IFH;
}

int Tiff::getEntryNum(){
	return this->entryCount;
}

void Tiff::printIFH(){
	cout << "Image File Header Infomation: " << endl;
	cout << "order: " << setbase(16) << (int)this->IFH.order << endl;
	cout << "version: " << setbase(16) << (int)this->IFH.version << endl;
	cout << "offSetValue" << setbase(16) << (int)this->IFH.offSet << endl;
}

void Tiff::printEntry(int num){
	cout << "Entry" << num << "' Infomation: " << endl;
	cout << "id: " << setbase(10)<< (int)this->entry[num].id << endl;
	cout << "type: " << setbase(16) << (int)this->entry[num].type << endl;
	cout << "length: " << setbase(16) << (int)this->entry[num].length << endl;
	cout << "valueOffset: " << setbase(16) << (int)this->entry[num].valueOffset << endl;
}

void Tiff::toTiffFromBmp(Bmp bmp){
	this->setIFH();
	Entry temp;
	int i = 0;
	temp.id = 256;
	temp.type = 4;
	temp.length = 1;
	temp.valueOffset = bmp.getBpInfoHeaderBpWidth();
	this->setEntry(temp, i++);
	temp.id = 257;
	temp.type = 4;
	temp.length = 1;
	temp.valueOffset = bmp.getBpInfoHeaderBpHeight();
	this->setEntry(temp, i++);
	temp.id = 259;
	temp.type = 3;
	temp.length = 1;
	temp.valueOffset = 1;
	this->setEntry(temp, i++);
	temp.id = 278;
	temp.type = 3;
	temp.length = 1;
	temp.valueOffset = bmp.getBpInfoHeaderBpHeight();
	this->setEntry(temp, i++);
	temp.id = 273;
	temp.type = 1;
	temp.length = 3;
	temp.valueOffset = 10 + 12 * (i + 1);
	this->setEntry(temp, i++);
	this->setEntryCount(i);
}

bool Tiff::isOffset(int num){
	bool flag = false;
	switch (entry[num].type){
	case 1:
		if (entry[num].length > 4){ flag = true; };
		break;
	case 2:
		if (entry[num].length * 8 > 4){ flag = true; };
		break;
	case 3:
		if (entry[num].length * 2 > 4){ flag = true; };
		break;
	case 4:
		if (entry[num].length * 4 > 4){ flag = true; };
		break;
	case 5:
		if (entry[num].length * 8 > 4){flag = true; };
		break;
	default:
		break;
	}
	return flag;
}