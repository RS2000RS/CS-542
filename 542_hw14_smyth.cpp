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
double strictlyMonotonic(unsigned a, unsigned b);
double okNesting(unsigned n);
bool monoCheck(string a);
bool strictMonoCheck(string a);


int main()
{

	cout << strictlyMonotonic(2, 3);
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

double strictlyMonotonic(unsigned a, unsigned b) {
	int count = 0;
	string holder;

	for (int j = 0; j < trials; j++) {
		holder = "";
		for (int i = 0; i < b; i++)
			holder += to_string(rand() % a);
		if (strictMonoCheck(holder)) count++;
	}

	return double(count) / trials;
}

double okNesting(unsigned n){
	//save stack, must start with '(', remove if ')' if stack has elements then not oknest
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

bool strictMonoCheck(string a) {
	char holder = a[0];
	int direction = -2;

	for (char c : a) {
		if (direction == -2) direction++; // awfully written
		else if (direction == -1) {
			if (c == holder) return false;
			else if (c > holder) direction = 0;
			else if (c < holder) direction = 1;
		}
		else if (c == holder || (c > holder && direction == 1) || (c < holder && direction == 0)) return false;
		holder = c;
	}
	return true;
}

