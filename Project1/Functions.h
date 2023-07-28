#pragma once
#include <iostream>

using namespace std;

bool isBalanced(string line);
bool isOperator(char c);
bool isOperand(char c);
int precedence(char op);
string infixToPostfix(const string& line);
string infixToPrefix(const string& line);
string prefixToInfix(const string& line);
string postfixToInfix(const string& line);
string reversed(const string& line);

