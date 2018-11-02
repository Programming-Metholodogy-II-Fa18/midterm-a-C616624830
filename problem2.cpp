// problem2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
	Data data;
	data.add(1);
	data.add(9);
	data.add(4);
	data.add(5);
	data.add(10);
	data.add(0);
	cout << data.getValue(0) <<' '<<data.getValue(3) << endl;
}

