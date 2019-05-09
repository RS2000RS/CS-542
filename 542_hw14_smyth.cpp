//  542_hw14_smyth.cpp
//  CS 542 - Discrete Structures
//  Homework #14

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
#define trials 10000

double monotonic(unsigned a, unsigned b);
bool monoCheck(string a);

int main()
{

	cout << monotonic(2, 3);
}

double monotonic(unsigned a, unsigned b) {

	int count = 0;
	string holder;

	for (int j = 0; j < trials; j++) {
		holder = "";
		for (int i = 0; i < b; i++) 
			holder += to_string(rand() % a);
		if (monoCheck(holder)) count++;
	}

	return double(count) / trials;
}

bool monoCheck(string a) {
	char holder = a[0];
	int direction = -1;

	for (char c : a) {
		if (direction == -1) {
			if (c > holder) direction = 0;
			else if (c < holder) direction = 1;
		}
		else if ((c > holder && direction == 1) || (c < holder && direction == 0)) return false;
		holder = c;
	}
	return true;
}
