// 542_hw14_smyth.cpp
//  CS 542 - Discrete Structures
//  Homework #14

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <vector> 
#include <string>
using namespace std;
#define trials 10000

double monotonic(unsigned a, unsigned b);
double strictlyMonotonic(unsigned a, unsigned b);
double okNesting(unsigned n);
double duel(double a, double b);
double flip(double p, unsigned n, unsigned k);
double prettyLady(unsigned gridX, unsigned gridY, unsigned ladyX, unsigned ladyY);
bool testLady(string s, unsigned a, unsigned b);
bool testNest(string a);
bool monoCheck(string a);
bool strictMonoCheck(string a);


int main()
{

	cout << flip(.5, 5, 5);
	
}

double flip(double p, unsigned n, unsigned k) {
	//(float)rand() / RAND_MAX
	int countCoin, countMatchK = 0;

	for (int i = 0; i < trials; i++) {
		countCoin = 0;
		for (int j = 0; j < n; j++)
			if ((float)rand() / RAND_MAX <= p) countCoin++;
		if (countCoin == k) countMatchK++;
	}

	return double(countMatchK) / trials;
}

double prettyLady(unsigned gridX, unsigned gridY, unsigned ladyX, unsigned ladyY) {
	string holder = "";
	int count=0; 

	for (int i = 0; i < gridX + gridY; i++)
		if (i < gridX) holder += "E";
		else holder += "N";

	for (int j = 0; j < trials; j++) {
		for (int i = 0; i <  gridX + gridY; i++)
			swap(holder[rand() % (gridX + gridY)], holder[rand() % (gridX + gridY)]);
		if (testLady(holder, ladyX, ladyY)) count++;
	}

	return double(count) / trials;
}

bool testLady(string s, unsigned a, unsigned b) {
	unsigned path[2] = {0,0};

	for (char c : s) {
		if (c == 'N') path[0]++;
		else if (c == 'E') path[1]++;
		if (path[0] == a && path[1] == b) return true;
		else if (path[0] > a || path[1] > b) return false; 
	}

	return false;
}


double duel(double a, double b) {
	int count = 0; 

	for (int i = 0; i < trials; i++)
		while (true)
			if ((float)rand() / RAND_MAX > a) {count++; break; }
			else if ((float)rand() / RAND_MAX > b) break;

	return double(count) / trials;
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

double okNesting(unsigned n) {
	int count = 0;
	string holder = "";

	for (int i = 0; i < n; i++)
		holder += "()";

	for (int j = 0; j < trials; j++) {
		for (int i = 0; i < (2*n); i++)
			swap(holder[rand() % (2*n)], holder[rand() % (2*n)]);
		if (testNest(holder)) count++;
	}

	return double(count) / trials;
}

bool testNest(string a) {
	vector <int> nest;

	for (char c : a)
		if (c == '(') nest.push_back(0);
		else if (c == ')') {
			if (nest.empty()) return false;
			else nest.pop_back();
		}

	return nest.empty(); 
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
