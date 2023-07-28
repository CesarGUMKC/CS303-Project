#include "Functions.h"
#include "myStack.h"
#include <iostream>

using namespace std;

bool isBalanced(string line) {                             //function that check for balance 

	myStack<char> stack1, stack2, stack3;                           //creates stacks for ( { [.



	for (char c : line) {                           //reads each char in line and adds to stack if open operand
		//if closing operator check respective stack if empty or operand not open, return false
		if (c == '(') {                             //else return true, line or expression is balanced
			stack1.push(c);
		}

		if (c == ')') {
			if (stack1.empty()) {
				return false;
			}
			else if (stack1.topElem() == '(') {
				stack1.pop();
			}
			else {
				return false;
			}

		}



		if (c == '{') {
			stack2.push(c);
		}

		if (c == '}') {
			if (stack2.empty()) {
				return false;
			}
			else if (stack2.topElem() == '{') {
				stack2.pop();
			}
			else {
				return false;
			}

		}



		if (c == '[') {
			stack3.push(c);
		}

		if (c == ']') {
			if (stack3.empty()) {
				return false;
			}
			if (stack3.topElem() == '[') {
				stack3.pop();
			}
			else {
				return false;
			}

		}
	}

	return true;
}

bool isOperator(char c) {                  //function to check if char is an operator

	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {

		return true;
	}
	else {
		return false;
	}

}

bool isOperand(char c) {                    //function to check if char is an operand

	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']') {

		return false;
	}
	else {
		return true;
	}

}

int precedence(char op) {             //function that returns the precedence of the inputed char ,

	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/' || op == '%') {
		return 2;
	}
	else
		return 0;

}

string reversed(const string& line) {

	string reversedLine;

	myStack<char> stack;

	for (char c : line) {

		if (c == '(') {
			stack.push(')');
		}
		else if (c == ')') {
			stack.push('(');
		}
		else if (c == '[') {
			stack.push(']');
		}
		else if (c == ']') {
			stack.push('[');
		}
		else if (c == '}') {
			stack.push('{');
		}
		else if (c == '{') {
			stack.push('}');
		}


		else {
			stack.push(c);
		}

	}

	while (!stack.empty()) {                      //after iterating thru expression, any remaining operator character in the stack append to postfix string
		char tempChar = stack.topElem();
		reversedLine += tempChar;
		stack.pop();
	}

	return reversedLine;
}

string infixToPostfix(const string& line) {         //function to convert an infix expression to a postfix expression

	myStack<char> operators;                  //a stack of char to store operators in correct order
	string postfix;

	for (char c : line) {                            //iterate thru infix expressionm, if not operand then add to postfix

		if (isOperand(c)) {
			if (c == ' ') {
				continue;
			}
			else {
				postfix += c;
			}
		}

		else if (c == '(' || c == '{' || c == '[') {                //if opening operand, add top stack
			operators.push(c);
		}

		else if (c == ')') {                                                          //if closing operand , check stack and if not opening operand, pop and add to postfix until found 
			while (operators.topElem() != '(' && !operators.empty()) {
				char tempChar = operators.topElem();
				postfix += tempChar;
				operators.pop();
			}

			if (operators.topElem() == '(' && !operators.empty()) {

				operators.pop();
			}
		}

		else if (c == ']') {
			while (operators.topElem() != '[' && !operators.empty()) {
				char tempChar = operators.topElem();
				postfix += tempChar;
				operators.pop();
			}

			if (operators.topElem() == '[' && !operators.empty()) {

				operators.pop();
			}
		}

		else if (c == '}') {
			while (operators.topElem() != '{' && !operators.empty()) {
				char tempChar = operators.topElem();
				postfix += tempChar;
				operators.pop();
			}

			if (operators.topElem() == '{' && !operators.empty()) {

				operators.pop();
			}
		}

		else if (isOperator(c)) {                                                          // if it is an operator, and while its precedence is less than or equal to top of stack, pop and add to postfix, then push to stack
			while (!operators.empty() && precedence(c) <= precedence(operators.topElem())) {
				char tempChar = operators.topElem();
				postfix += tempChar;
				operators.pop();
			}

			operators.push(c);
		}
	}

	while (!operators.empty()) {                      //after iterating thru expression, any remaining operator character in the stack append to postfix string
		char tempChar = operators.topElem();
		postfix += tempChar;
		operators.pop();
	}


	return postfix;                      //return result :)

}

string infixToPrefix(const string& line) {                //function to convert to prefix from infix

	string prefix = infixToPostfix(reversed(line));

	prefix = reversed(prefix);

	return prefix;

}

string prefixToInfix(const string& line) {                //function to convert to infix from prefix

	myStack<string> stack;
	int length = line.size();


	for (int i = length - 1; i >= 0; i--) {

		char c = line[i];

		if (isOperator(c)) {

			string operand1 = stack.topElem();
			stack.pop();

			string operand2 = stack.topElem();
			stack.pop();

			string temp = "(" + operand1 + c + operand2 + ")";

			stack.push(temp);

		}

		else {

			stack.push(string(1, c));
		}


	}

	string expression = stack.topElem();

	return expression;
}


string postfixToInfix(const string& line) {             //function to convert to infix from postfix

	myStack<string> stack;
	int length = line.size();


	for (int i = 0; i <= length - 1; i++) {

		char c = line[i];

		if (isOperator(c)) {

			string operand2 = stack.topElem();
			stack.pop();

			string operand1 = stack.topElem();
			stack.pop();

			string temp = "(" + operand1 + c + operand2 + ")";

			stack.push(temp);

		}

		else {

			stack.push(string(1, c));
		}


	}

	string expression = stack.topElem();

	return expression;

}