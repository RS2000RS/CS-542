//  542_hw4_smyth.cpp
//
//  Smyth, Ravela
//  CS542 Homework #4 "Relations and functions as sets of ordered pairs"

// ---------- INCLUDES ------------------------------------------------------------------

#include <algorithm> // pair
#include <iostream>
#include <set> // set
using namespace std;

// ---------- TYPEDEFS ------------------------------------------------------------------

typedef pair<unsigned, unsigned> OP;
typedef set<OP> SOP;

// ---------- FUNCTIONS ------------------------------------------------------------------
void show(const OP & op);
OP makeOP(unsigned first, unsigned second);
OP add(const OP & a, const OP & b);
void show(const SOP & sop);
bool elementOf(const OP & op, const SOP & sop);
bool firstFound(unsigned first, const SOP & sop);
bool eitherFound(unsigned n, const SOP & sop);
SOP Union(const SOP & sop0, const SOP & sop1);

// ---------- MAIN ------------------------------------------------------------------

int main() {
	OP op0 = makeOP(2,2), op1(2, 3), op2=add(op0,op1), op4(2, 4);
	SOP sop; sop.insert(op0);
	sop.insert(op1); sop.insert(op2); sop.insert(op4);
	show(sop);
	cout << "BOOL: " << elementOf(OP(1,2), SOP{OP(1,1), OP(2,1), OP(2,2)})
	     << "BOOL 2: " << eitherFound(0, sop);
	show(Union(sop,{OP(1,0), OP(8,78)}));
	
}

// ---------- FUNCTION DEFINITION ------------------------------------------------------------------
void show(const OP & op) {
	cout << "(" << op.first << ", " << op.second << ") ";
}

OP makeOP(unsigned first, unsigned second) {
    return OP(first, second);
}

OP add(const OP & a, const OP & b) {
    return OP(a.first+b.first, a.second+b.second);
}

void show(const SOP & sop) {
    SOP ::iterator itr;

    for (itr = sop.begin(); itr != sop.end(); ++itr)
        show(*itr);
}

bool elementOf(const OP & op, const SOP & sop) {
    return sop.find(op) != sop.end();
}

bool firstFound(unsigned first, const SOP & sop) {
    SOP ::iterator itr;
    for (itr = sop.begin(); itr != sop.end(); ++itr)
        if (itr->first == first) return true; 
    return false;
}

bool secondFound(unsigned second, const SOP & sop) {
    SOP ::iterator itr;
    for (itr = sop.begin(); itr != sop.end(); ++itr)
        if (itr->second == second) return true; 
    return false;
}

bool eitherFound(unsigned n, const SOP & sop) {
    return firstFound(n,sop) || secondFound(n,sop); 
}

SOP Union(const SOP & sop0, const SOP & sop1) {
    SOP sop = sop0; 
    sop.insert(sop1.begin(), sop1.end());
    return sop;
}
