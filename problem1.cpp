// problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void ExamSort(int a[], int size);
void MergeSort(int a[], int aux[], int lo, int hi);
void Merge(int a[], int aux[], int lo, int mid, int hi);
int main()
{
	int a[7] = { 15,9,60,44,12,1,4 };

	ExamSort(a, 7);
	for (int i = 0; i < 7; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

void ExamSort(int a[], const int size) {
	int* aux = new int[size];
	MergeSort(a, aux, 0, size - 1);
	delete[]aux;
}

void MergeSort(int a[], int aux[], int lo, int hi) {
	if (hi <= lo) return;
	int mid = lo + (hi - lo) / 2;
	MergeSort(a, aux, lo, mid);
	MergeSort(a, aux, mid + 1, hi);
	Merge(a, aux, lo, mid, hi);
}
void Merge(int a[], int aux[], int lo, int mid, int hi) {
	int first1 = lo;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = hi;
	int index = lo;

	while (first1 <= last1 && first2 <= last2) {
		if (a[first1] <= a[first2]) {
			aux[index] = a[first1];
			first1++;
		}
		else {
			aux[index] = a[first2];
			first2++;
		}
		index++;
	}
	while (first1 <= last1) {
		aux[index] = a[first1];
		++first1;
		++index;
	}
	while (first2 <= last2) {
		aux[index] = a[first2];
		++first2;
		++index;
	}

	for (int i = lo; i <= hi; i++) {
		a[i] = aux[i];
	}
}
