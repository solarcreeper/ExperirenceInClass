#include "sort.h"
#include <ctime>
#include<windows.h>
#include <iostream>
#include<cstdlib>

using namespace std;

int main(){
	srand(time(0));
	const int max = 100000;
	int B[max];
	
	//Sort().PrintResult(B, max);
	
	//1.SelectSort
	for (int i = 0; i < max; i++){
		B[i] = rand() % 1000;
	}
	Sort().Settime();
	Sort().SelectSort(B, max);
	cout << "SelectSort time(N = " << max << "):" << Sort().Gettime() << endl;

	//2.InsertSort
	for (int i = 0; i < max; i++){
		B[i] = rand() % 1000;
	}
	Sort().Settime();
	Sort().InsertSort(B, max);
	cout << "InsertSort time(N = " << max << "):" << Sort().Gettime() << endl;

	//3.BubbleSort
	for (int i = 0; i < max; i++){
		B[i] = rand() % 1000;
	}
	Sort().Settime();
	Sort().BubbleSort(B, max);
	cout << "BubbleSort time(N = " << max << "):" << Sort().Gettime() << endl;

	//4.ShellSort
	for (int i = 0; i < max; i++){
		B[i] = rand() % 1000;
	}
	Sort().Settime();
	Sort().ShellSort(B, max);
	cout << "ShellSort  time(N = " << max << "):" << Sort().Gettime() << endl;

	//5.MergeSort
	for (int i = 0; i < max; i++){
		B[i] = rand() % 1000;
	}
	Sort().Settime();
	int A[max];
	Sort().MergeSort(B, A, 0, max);
	cout << "MergeSort  time(N = " << max << "):" << Sort().Gettime() << endl;

	//6.QSort
	for (int i = 0; i < max; i++){
		B[i] = rand() % 1000;
	}
	Sort().Settime();
	Sort().QSort(B, 0, max);
	cout << "QSort      time(N = " << max << "):" << Sort().Gettime() << endl;

	system("pause");
	return 0;
}	

//Sort().QSort(B, 0, max);
