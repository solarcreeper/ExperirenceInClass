#include"DDA.h"
#include<iostream>

using std::cout;
using std::endl;

DDA::DDA(int x1, int y1, int x2, int y2){

	this->getPos(x1, y1, x2, y2);
}

DDA::~DDA(){

}

bool DDA::draw(int x, int y, int color){
	//模拟画线函数，我就占个位置
	cout << x << "  " << y << endl;
	return true;
}

void DDA::getPos(int x1, int y1, int x2, int y2){
	double dx = x2 - x1;
	double dy = y2 - y1;
	double k = dy / dx;
	while (x1 <= x2){
		this->draw(x1, y1, 0);
		x1++;
		y1 = round(y1 + k);
	}
}