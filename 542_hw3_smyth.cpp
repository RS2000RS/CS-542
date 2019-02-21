//  542_hw3_smyth.cpp
//  CS 542 - Discrete Structures
//  Homework #3


#include <iostream>
#include <set>
#include <iterator> 
using namespace std;

void show(const set<int> & s);
unsigned evens(const set<int> & s);
unsigned howManyInteresting(const set<int> & s, bool(*interesting)(int n));
bool subset(const set<int> & little, const set<int> & big);
set<int> Union(const set<int> & s0, const set<int> & s1);
set<int> intersection(const set<int> & s0, const set<int> & s1);
set<int> complement(const set<int> & s, const set<int> & universe);
set<int> difference(const set<int> & a, const set<int> & b);
set<int> symmetricDifference(const set<int> & a, const set<int> & b);
bool hello(int n);

int main()
{ 
	set <int> s, g, t; 

	s.insert(10); s.insert(10); s.insert(21); s.insert(70); s.insert(2);
	g.insert(51); g.insert(101); g.insert(1); g.insert(71); g.insert(10); g.insert(2); 
	t.insert(102); t.insert(2); t.insert(70);

	show(s);
	cout << "How many evens: " << evens(s)
		 << "\nHow many interestings: " << howManyInteresting(s, hello)
		 << "\nSubset?: " << subset(t, g)
		 << "\nUnion two sets: "; show(Union(s, g));
	cout << "\nIntersect two sets : "; show(intersection(s, g));
	cout << "\nComplement two sets : "; show(intersection(t, g));
	cout << "\nSymmetric Difference: "; show(symmetricDifference(g,t));
}


void show(const set<int> & s) {
	set <int> ::iterator itr;
	cout << "The set is : ";
	for (itr = s.begin(); itr != s.end(); ++itr) {
		cout << '\t' << *itr; 
	}
	cout << endl; 
}

unsigned evens(const set<int> & s) {
	unsigned count=0; 
	set <int> ::iterator itr;
	for (itr = s.begin(); itr != s.end(); ++itr)
		if (*itr % 2 == 0) count++;
	return count; 
}

unsigned howManyInteresting(const set<int> & s, bool(*interesting)(int n)) {
	unsigned count = 0;
	set <int> ::iterator itr;
	for (itr = s.begin(); itr != s.end(); ++itr)
		if (interesting(*itr)) count++;
	return count;
}

bool subset(const set<int> & little, const set<int> & big) {
	set <int> ::iterator itr1, itr0;

	for (itr0 = little.begin(), itr1 = big.begin(); itr0 != little.end() && itr1 != big.end(); ++itr1)
		if (*itr0 < *itr1) return false;
		else if (*itr0 == *itr1) ++itr0;

	return *(--little.end()) > *(--big.end()) ? false : true;
}

set<int> Union(const set<int> & s0, const set<int> & s1) {
	set <int> s2;
	s2.insert(s0.begin(), s0.end()); s2.insert(s1.begin(), s1.end());
	return s2; 
}

set<int> intersection(const set<int> & s0, const set<int> & s1) {
	set <int> s2; 
	set <int> ::iterator itr1, itr0;

	for (itr0=s0.begin(), itr1=s1.begin(); itr0!=s0.end() && itr1!=s1.end();)
		if (*itr0 == *itr1) { s2.insert(*itr0); ++itr0; ++itr1; }
		else if (*itr0 > *itr1) ++itr1;
		else ++itr0; 

	return s2; 
}

set<int> complement(const set<int> & s, const set<int> & universe) {
	set <int> s2;
	set <int> ::iterator itr1, itr0;

	for (itr0 = s.begin(), itr1 = universe.begin(); itr0 != s.end() && itr1 != universe.end(); ++itr1)
		if (*itr0 == *itr1)  ++itr0;
		else s2.insert(*itr1);

		return s2;
}

set<int> difference(const set<int> & a, const set<int> & b) {
	return complement(b, a);
}

set<int> symmetricDifference(const set<int> & a, const set<int> & b) {
	set <int> s2;
	set <int> ::iterator itr1, itr0;

	for (itr0 = a.begin(), itr1 = b.begin(); itr0 != a.end() && itr1 != b.end();)
		if (*itr0 == *itr1) { ++itr0; ++itr1; }
		else if (*itr0 > *itr1) { s2.insert(*itr1); ++itr1;}
		else { s2.insert(*itr0); ++itr0; }

	return s2;
}

bool hello(int n) {
	if (n * 7 % 3 == 0) return true; 
	return false;
}
