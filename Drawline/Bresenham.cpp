#include"Bresenham.h"
#include<iostream>

using std::cout;
using std::endl;

Bresenham::Bresenham(int x1, int y1, int x2, int y2){
	this->getPos(x1, y1, x2, y2);
}

Bresenham::~Bresenham(){

}

bool Bresenham::draw(int x, int y, int color){
	cout << x << " " << y << endl;
	return true;
}

void Bresenham::getPos(int x1, int y1, int x2, int y2){
	double dx = x2 - x1;
	double dy = y2 - y1;
	double k = dy / dx;
	float e = -0.5;
	this->draw(x1, y1, 0);
	for (int i = x1; i < x2; i++){
		e = e + k;
		if (e > 0){
			y1++;
			e = e - 1;
		}
		x1++;
		
		this->draw(x1, y1, 0);
	}
}