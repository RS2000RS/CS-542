//  542_hw6_smyth.cpp
//
//  Smyth, Ravela
//  CS542 Homework #6 "Is this relation an equivalence relation?"


// ---------- INCLUDES ------------------------------------------------------------------

#include "stdafx.h"
#include <vector>
#include <algorithm> // pair
#include <iostream>
#include <set> // set
using namespace std;

// ---------- TYPEDEFS ------------------------------------------------------------------

typedef pair<unsigned, unsigned> OP;
typedef set<OP> SOP;

// ---------- FUNCTIONS ------------------------------------------------------------------

bool er(const SOP & sop, const set<unsigned> & univ);
bool reflexivity(const SOP & sop, const set<unsigned> & univ);
bool symmetry(const SOP & sop);
bool transitivity(const SOP & sop);
bool elementOf(const OP & op, const SOP & sop);
OP firstFound(unsigned first, const SOP & sop);

// ---------- MAIN ------------------------------------------------------------------

int main()
{ 

	if (er(SOP{ OP(1,1), OP(2,2),  OP(6,6), OP(1,6), OP(6,1), OP(1,2)}, set<unsigned>{ 1, 2, 6 })) cout << "true";
}

// ---------- FUNCTION DEFINITION ------------------------------------------------------------------

bool er(const SOP & sop, const set<unsigned> & univ) {
	if (!reflexivity(sop, univ) || !symmetry(sop) || !transitivity(sop)) return false;
	return true; 
}

bool reflexivity(const SOP & sop, const set<unsigned> & univ) {
	set<unsigned> ::iterator itr;

	for (itr = univ.begin(); itr != univ.end(); ++itr)
		if (!elementOf({ *itr, *itr }, sop)) return false;
	return true;
}
bool symmetry(const SOP & sop) { 
	//vector<int> flag(sop.size());
	SOP::iterator itr;

	for (itr = sop.begin(); itr != sop.end(); ++itr)
		if (!elementOf(OP( itr->second, itr->first), sop)) return false; //ineffcient
	return true;
}

bool transitivity(const SOP & sop) {
	SOP::iterator itr;

	for (itr = sop.begin(); itr != sop.end(); ++itr)
		if (!elementOf(OP(firstFound(itr->second, sop).second, itr->first), sop)) return false;
	return true;
}


bool elementOf(const OP & op, const SOP & sop) {
	return sop.find(op) !=sop.end();
}

OP firstFound(unsigned first, const SOP & sop) {
	SOP::iterator itr;
	for (itr = sop.begin(); itr != sop.end(); ++itr)
		if (itr->first == first) return *itr;
	return *itr;
}
