#include"MidpointLineAlgorithm.h"
#include<iostream>

using std::cout;
using std::endl;

MLA::MLA(int x1, int y1, int x2, int y2){
	this->getPos(x1, y1, x2, y2);
}

MLA::~MLA(){

}

bool MLA::draw(int x, int y, int color){
	cout << x << " " << y << endl;
	return true;
}

void MLA::getPos(int x1, int y1, int x2, int y2){
	int a = y1 - y2;
	int b = x2 - x1;
	int d = 2 * a - b;
	int d1 = 2 * (d + a);
	int d2 = 2 * (a + b);
	this->draw(x1, y1, 0);
	while (x1 < x2){
		if (d >= 0){
			x1++;
			d = d + d1;
		}
		else{
			x1++;
			y1++;
			d = d + d2;
		}
		this->draw(x1, y1, 0);
	}


}