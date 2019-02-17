//  542_hw1_smyth.cpp
//  CS 542 - Discrete Structures
//  Homework #1

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

unsigned factorial(unsigned n);
unsigned comb(unsigned n, unsigned k);
unsigned perm(unsigned n, unsigned k);
unsigned combABC(unsigned n);
unsigned combABC(unsigned n);
unsigned permABC(unsigned n);
void permABC_rt(string permu, unsigned n);
unsigned f(unsigned a, unsigned b, unsigned c);
unsigned triangular_num(unsigned n);
void aprint(char a[], unsigned n);

int main(int argc, const char * argv[]) {
    cout << "1. factorial -- factorial(4) = " << factorial(4) << endl
         << "2. combination -- comb(5,2) = " << comb(5,2) << endl
         << "3. permutation -- perm(5,2) = " << perm(5,2) << endl
         << "4. f(a,b,c) -- f(1,2,1) = " << f(1,2,1) << endl
         << "5. combination ABC repeating -- combABC(5) : ";
        combABC(5);
    cout << "\n6. permutation ABC repeating -- permABC(2) : \n";
        permABC(2);
}

unsigned factorial(unsigned n) {
    if (n==0) return 1;
    return n * factorial(n-1);
}

unsigned triangular_num(unsigned n) {
    return (n * n + n) / 2;
}

unsigned comb(unsigned n, unsigned k) {
    return factorial(n) / (factorial(k) * factorial(n-k));
}

unsigned perm(unsigned n, unsigned k) {
    return factorial(n) / factorial(n-k);
}

unsigned combABC(unsigned n) {
    char combs[n];
    for(unsigned i=0; i<3; i++){
        fill(combs, combs+n, char('A' + i));
        
        if(i==0)
            for(unsigned k=0; k<n; k++) {
                fill(combs+n-k, combs+n, 'B');
                for(unsigned j=0; j<=k; j++) {
                    fill(combs+n-j, combs+n, 'C');
                    aprint(combs, n);
                }
            }
        else if(i==1)
            for(unsigned k=0; k<n; k++) {
                fill(combs+n-k, combs+n, 'C');
                aprint(combs, n);
            }
        else aprint(combs, n);
    }
    
    return triangular_num(n) + n + 1;
}

unsigned permABC(unsigned n) {
    permABC_rt("", n);
    return pow(3,n);
}

void permABC_rt(string permu, unsigned n) {
    if (n==0) {cout << permu<<endl; return;}
    permABC_rt(permu+'A', n-1);
    permABC_rt(permu+'B', n-1);
    permABC_rt(permu+'C', n-1);
}

unsigned f(unsigned a, unsigned b, unsigned c) {
    return factorial(a+b+c)/ (factorial(a)*factorial(b)*factorial(c));
}

void aprint(char a[], unsigned n) {
    cout << endl;
    for (unsigned i=0; i<n; i++)
        cout << a[i];
}

