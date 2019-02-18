//  542_hw2_smyth.cpp
//  CS 542 - Discrete Structures
//  Homework #2


#include <iostream>
#include <cmath>
using namespace std;

void getFILNT(double filnt[], bool arith);
bool hasBlankN(double filnt[], int n);
void getF(double filnt[], bool arith);
void getI(double filnt[], bool arith);
void getL(double filnt[], bool arith);
void getN(double filnt[], bool arith);
void getT(double filnt[], bool arith);


int main()
{
    // 4    2   24     11 154
    // 10   3   2430   6  3640
    double FILNT_arith[5] = { -1,  -1, 24, 11, 154 }; char FILNT_char[] = { 'F', 'I', 'L', 'N', 'T' };
    double FILNT_geo[5] = { 10, -1, 2430, 6, -1 };
    
    cout << "Please input three variables in order F I L N T . If blank, input -1: ";
    
    getFILNT(FILNT_arith, true);
    getFILNT(FILNT_geo, false);

    cout << "\n";
    for (int i = 0; i < 5; i++)
        cout << FILNT_char[i] << " :: " << FILNT_arith[i] << " :: " << FILNT_geo[i] << "\n";
}

void getFILNT(double filnt[], bool arith) {
    
    //ARITH
    while (arith && hasBlankN(filnt,5)) {
        getF(filnt, true);
        getI(filnt, true);
        getL(filnt, true);
        getN(filnt, true);
        getT(filnt, true);
    }
    
    //GEO
    while (!arith && hasBlankN(filnt,5)) {
        getF(filnt, false);
        getI(filnt, false);
        getL(filnt, false);
        getN(filnt, false);
        getT(filnt, false);
    }
}

void getF(double filnt[], bool arith) {
    if (arith && hasBlankN(filnt, 0)) {
        if (!hasBlankN(filnt, 1) && !hasBlankN(filnt, 2) && !hasBlankN(filnt, 3))
            filnt[0] = filnt[2] - ((filnt[3] - 1) * filnt[1]);
        else if (!hasBlankN(filnt, 1) && !hasBlankN(filnt, 3) && !hasBlankN(filnt, 4))
            filnt[0] = (((filnt[4] * 2) / filnt[3]) - ((filnt[3] -1) * filnt[1])) / 2;
        else if (!hasBlankN(filnt, 2) && !hasBlankN(filnt, 3) && !hasBlankN(filnt, 4))
            filnt[0] = (filnt[4]*2)/filnt[3] - filnt[2];
    }
    else if (hasBlankN(filnt, 0)) {
        if (!hasBlankN(filnt, 1) && !hasBlankN(filnt, 2) && !hasBlankN(filnt, 3))
            filnt[0] = filnt[2] / pow(filnt[1], filnt[3]-1);
        else if (!hasBlankN(filnt, 1) && !hasBlankN(filnt, 3) && !hasBlankN(filnt, 4))
            filnt[0] = filnt[4] * (1 - filnt[1]) / (1 - pow(filnt[1], filnt[3]));
    }
}

void getI(double filnt[], bool arith) {
    if (arith && hasBlankN(filnt, 1) && !hasBlankN(filnt, 0) && !hasBlankN(filnt, 3) && !hasBlankN(filnt, 4))
        filnt[1] = (((2*filnt[4])/filnt[3]) - (2*filnt[0])) / (filnt[3] - 1);
    else if (hasBlankN(filnt, 1)) {
        if (!hasBlankN(filnt, 0) && !hasBlankN(filnt, 2) && !hasBlankN(filnt, 3))
            filnt[1]= pow(10, log10(filnt[2]/filnt[0])/(filnt[3]-1));
    }
}

void getL(double filnt[], bool arith) {
    if (arith && hasBlankN(filnt, 2) && !hasBlankN(filnt, 0) && !hasBlankN(filnt, 1) && !hasBlankN(filnt, 3))
        filnt[2] = filnt[0] + ((filnt[3]-1) * filnt[1]);
    else if (hasBlankN(filnt, 2))
        if (!hasBlankN(filnt, 0) && !hasBlankN(filnt, 1) && !hasBlankN(filnt, 3))
            filnt[2] = filnt[0] * pow(filnt[1], filnt[3]-1);
}

void getN(double filnt[], bool arith) {
    if (arith && hasBlankN(filnt, 3)) {
        if (!hasBlankN(filnt, 0) && !hasBlankN(filnt, 1) && !hasBlankN(filnt, 2))
            filnt[3] = (filnt[2] - filnt[0]) / filnt[1] + 1;
        else if (!hasBlankN(filnt, 0) && !hasBlankN(filnt, 2) && !hasBlankN(filnt, 4))
            filnt[3] = filnt[4] * 2 / (filnt[0] + filnt[2]);
    }
    else if (hasBlankN(filnt, 3))
        if (!hasBlankN(filnt, 0) && !hasBlankN(filnt, 1) && !hasBlankN(filnt, 2))
            filnt[3] = 1 + (log10(filnt[2]/filnt[0])/log10(filnt[1]));
}

void getT(double filnt[], bool arith) {
    if (arith && hasBlankN(filnt, 4)) {
        if (!hasBlankN(filnt, 0) && !hasBlankN(filnt, 1) && !hasBlankN(filnt, 3))
            filnt[4] = (filnt[3] / 2) * ( (2 * filnt[0]) + ((filnt[3] - 1) * filnt[1]));
        else if (!hasBlankN(filnt, 0) && !hasBlankN(filnt, 2) && !hasBlankN(filnt, 3))
            filnt[4] = (filnt[3] / 2) * (filnt[0] + filnt[2]);
    }
    else if (hasBlankN(filnt, 4))
        if (!hasBlankN(filnt, 0) && !hasBlankN(filnt, 1) && !hasBlankN(filnt, 3))
            filnt[4] = filnt[0] * (1-pow(filnt[1], filnt[3])) / (1-filnt[1]);
}




bool hasBlankN(double filnt[], int n) {
    if (n == 5) {
        for (int i = 0; i < n; i++)
            if (filnt[i] == -1) return true;
    }
    else if (filnt[n] == -1) return true;
    return false;
}
