#include "Bmp.h"
#include "Tiff.h"
#include <iostream>

int main(){
	//Bmp binary = Bmp("ex1_binary.bmp");
	//Bmp grayscale = Bmp("ex1_grayscale.bmp");
	//grayscale.printBpHeader();
	//grayscale.printBpInfoHeader();
	//Bmp grayscaleRLE = Bmp("ex1_grayscaleRLE.bmp");
	//Bmp index = Bmp("ex1_index.bmp");
	//Bmp indexRLE = Bmp("ex1_indexRLE.bmp");
	Bmp rgb = Bmp("ex1_rgb.bmp");
	//rgb.toGrayImageByMax();
	//rgb.toGrayImageByAvg();
	//rgb.toGrayImageByWAvg(1, 98, 1);
	//rgb.save("toGray1.bmp");
	Tiff test = Tiff(rgb);
	//test.save("hahaha.tif");
}