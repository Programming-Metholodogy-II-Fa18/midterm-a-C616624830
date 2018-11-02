// problem3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Data.h"
#include <iostream>
using namespace std;

bool search(Data data, int key) {
	int x = -2;
	while (key != x && x != -1) {
		x = data.remove();
	}
	if (x == -1) {
		return false;
	}
	return true;
}


int main()
{
	Data data;
	data.add(1);
	data.add(5);
	data.add(8);
	data.add(10);
	data.add(12);
	data.add(14);
	data.add(18);
	data.add(20);
	data.add(33);
	data.add(41);
	if (search(data, 8)) {
		cout << "8" << endl;
}
	if (search(data, 33)) {
		cout << "33" << endl;
	}
    return 0;
}

