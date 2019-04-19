//  542_hw10_smyth.cpp
//  CS 542 - Discrete Structures
//  Homework #10

#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <utility>
#include <iterator>
using namespace std;

stack<char> operators;
stack<int> operands;

char priority[] = { '!', '&', '^', '|', '(' , ')' };
map<char,int> vars;
string firstexp, secondexp;

bool equivalent(int depth, int val);
string valued_exp(string exp);
bool evaluate(string exp);
void operation();
bool higherPriority(char a, char b);
int find(char c);

int main()
{
	string input_str = "A & B,    !(!A | !B)"; 
	//cin >> input_str;

	int pos = input_str.find_first_of(',');
	firstexp = input_str.substr(pos + 1), secondexp = input_str.substr(0, pos);

	for (int i = 0; i < firstexp.length(); i++)
		if (isalpha(firstexp[i]))
			vars[firstexp[i]] = 3; 

	cout << equivalent(0,0) && equivalent(0,1);


}

bool equivalent(int depth, int val) {

	auto first = vars.begin(); // get iterator to 1st element
	advance(first, depth);     // advance by 9
	vars[first->first] = val;

	if (depth == vars.size()-1) return evaluate(valued_exp(firstexp)) == evaluate(valued_exp(secondexp));
	else return equivalent(depth+1, 0) && equivalent(depth + 1, 1);
}

string valued_exp(string exp) {
	string val_exp=exp;


	for (int i = 0; i < exp.length(); i++)
		if (isalpha(exp[i])) val_exp[i] = to_string(vars[exp[i]])[0];


	//cout << "++++" << val_exp << "++++\n";

	return val_exp; 
}

bool evaluate(string exp) {
	for (int i = 0; i < exp.length(); i++)
		switch (exp[i]) {
		case ' ': break;
		case '0': operands.push(0); break;
		case '1': operands.push(1); break;
		case '(': operators.push('('); break;
		case ')':
			while (operators.top() != '(')
				operation();
			operators.pop();
			break;
		default:
			while (!operators.empty() && !higherPriority(exp[i], operators.top()))
				operation();
			operators.push(exp[i]);
		}

	while (!operators.empty())
		operation();

	return operands.top();
}

void operation() {
	int a = operands.top();
	operands.pop();
	int b = -1;
	if (operators.top() != '!') { b = operands.top(); operands.pop(); }
	int op = operators.top(); operators.pop();

	switch (op) {
	case '!': operands.push(!a); break;
	case '&': operands.push(a & b); break;
	case '^': operands.push(a ^ b); break;
	case '|': operands.push(a | b); break;
	}


}

bool higherPriority(char a, char b) {
	if (find(a) < find(b)) return true;
	return false;
}

int find(char c) {
	for (int i = 0; i < 6; i++)
		if (c == priority[i]) return i;
	return -1;
}
