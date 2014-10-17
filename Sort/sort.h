#ifndef SORT_H
#define SORT_H

#include <time.h>

class  Sort{
private:
	unsigned tstart = 0;
	bool compare(int a, int b);
public:
	Sort();
	~Sort();

	void Settime() { tstart = (unsigned)clock(); }
	double Gettime() {
		unsigned tcurr = (unsigned)clock();
		return (double)(tcurr - tstart) / (double)CLOCKS_PER_SEC;
	}

	void PrintResult(int A[], int n);
	void InsertSort(int A[], int n);
	void BubbleSort(int A[], int n);
	void SelectSort(int A[], int n);
	void ShellSort(int A[], int n);
	void QSort(int A[], int i, int j);
	void MergeSort(int A[], int temp[], int left, int right);
	inline void swap(int A[], int i, int j){
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}

	inline void insertForshell(int A[], int n, int incr){
		for (int i = incr; i<n; i += incr)
			for (int j = i; (j >= incr) &&(!this->compare(A[j], A[j - incr])); j -= incr)
				swap(A, j, j - incr);
	}

	inline int findpivot(int A[], int i, int j){
		return (i + j) / 2;
	}

	inline int partition(int A[], int l, int r, int& pivot) {
		do {             // Move the bounds inward until they meet
			while (this->compare(A[++l], pivot));  // Move l right and
			while ((l < r) && this->compare(pivot, A[--r])); // r left
			swap(A, l, r);              // Swap out-of-place values
		} while (l < r);              // Stop when they cross
		return l;      // Return first position in right partition
	}

};

#endif