// DrawlineDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "DDA.h"
#include "MidpointLineAlgorithm.h"
#include "Bresenham.h"
#include "MidpointCycleAlgorithm.h"
#include <iostream>

using std::cout;

void main(){
	//DDA(1, 1, 59, 55);
	//MLA(1, 1, 59, 55);
	Bresenham(21, 12, 29, 16);
	//DDA(21, 12, 29, 16);

}