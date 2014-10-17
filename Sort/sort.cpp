#include"sort.h"
#include <iostream>

using namespace std;

Sort::Sort(){}

Sort::~Sort(){}

bool Sort::compare(int a, int b){
	return a > b;
}

void Sort::PrintResult(int A[], int n){
	for (int i = 0; i < n; i++)
		 cout << A[i] << " ";
	cout << endl;
}

void Sort::InsertSort(int A[], int n){
	for (int i = 0; i < n; i++){
		int minflag = i;
		for (int j = i + 1; j < n; j++){
			if (this->compare(A[minflag], A[j]))
				minflag = j;
		}
		swap(A, minflag, i);
	}
}

void Sort::SelectSort(int A[], int n){
	for (int i = 1; i < n; i++){
		for(int j = i; j > 0; j--){
			if (!this->compare(A[j], A[j - 1])){
				swap(A, j, j - 1);
			}
		}
	}
}

void Sort::BubbleSort(int A[], int n){
	for (int i = 0; i < n; i++){
		for (int j = n-1; j >i; j--){
			if (!this->compare(A[j], A[j-1]))
				swap(A, j, j-1);
		}
	}
}

void Sort::ShellSort(int A[], int n){
	for (int i = n / 2; i>2; i /= 2)      // For each increment
		for (int j = 0; j<i; j++)       // Sort each sublist
			insertForshell(&A[j], n - j, i);
	insertForshell(A, n, 1);
}

void Sort::QSort(int A[], int i, int j){
	if (j <= i) return; // Don't sort 0 or 1 element
	int pivotindex = findpivot(A, i, j);
	swap(A, pivotindex, j);    // Put pivot at end
	// k will be the first position in the right subarray
	int k = partition(A, i - 1, j, A[j]);
	swap(A, k, j);             // Put pivot in place
	QSort(A, i, k - 1);
	QSort(A, k + 1, j);
}

void Sort::MergeSort(int A[], int temp[], int left, int right){
	if (left == right) return;        // List of one element
	int mid = (left + right) / 2;
	MergeSort(A, temp, left, mid);
	MergeSort(A, temp, mid + 1, right);
	for (int i = left; i <= right; i++)   // Copy subarray to temp
		temp[i] = A[i];
	// Do the merge operation back to A
	int i1 = left; int i2 = mid + 1;
	for (int curr = left; curr <= right; curr++) {
		if (i1 == mid + 1)      // Left sublist exhausted
			A[curr] = temp[i2++];
		else if (i2 > right)  // Right sublist exhausted
			A[curr] = temp[i1++];
		else if (this->compare(temp[i1], temp[i2]))
			A[curr] = temp[i1++];
		else A[curr] = temp[i2++];
	}
}