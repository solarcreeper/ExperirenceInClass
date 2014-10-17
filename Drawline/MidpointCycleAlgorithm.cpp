#include"MidpointCycleAlgorithm.h"
#include<iostream>

using std::cout;
using std::endl;

MCA::MCA(int x, int y, int r){
	this->getPos(x, y, r);
}

MCA::~MCA(){

}

bool MCA::draw(int x, int y, int color){
	cout << x << "  " << y << endl;
	return true;
}

bool MCA::drawFourPiont(int x, int y, int color){
	this->draw(x, y, 0);
	this->draw(x, -y, 0);
	this->draw(-x, y, 0);
	this->draw(-x, -y, 0);
	this->draw(y, x, 0);
	this->draw(y, -x, 0);
	this->draw(-y, x, 0);
	this->draw(-y, -x, 0);
	return true;
}

void MCA::getPos(int x, int y, int r){
	int x0 = x;
	int y0 = y + r;
	this->drawFourPiont(x0, y0, 0);
	double dUp = 2 * x0 + 3;
	double dDown = 2 * (x0 - y0) + 5;
	double d = 1.25 + 2 * x0 - y0;
	while (x0 < y0){
		if (d <= 0){
			d = d + 2 * x0 + 3;
		}
		else{
			d = d + 2 * (x0 - y0) + 5;
			y0--;
		}
		x0++;
		this->drawFourPiont(x0, y0, 0);
	}
}