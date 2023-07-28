#include <iostream>
#include <string>
#include "myStack.h"
#include "Functions.h"

using namespace std;

int main() {

	string line;
	string choice;

	cout << "Which type of expression are you trying to convert, select 1, 2, or 3:" << endl;
	cout << "\t1)Prefix\n\t2)Infix\n\t3)Postfix" << endl << endl;

	cout << "Enter here:";
	cin >> choice;
	while (choice != "1" && choice != "2" && choice != "3") {

		cout << "Please enter valid option(1,2,3):";
		cin >> choice;

	}

	int decision = stoi(choice);

	cout << "Enter expression, to quit enter an empty line: ";              //ask user for expression

	getline(cin, line);

	while (getline(cin, line) && (line != "")) {                              //checks for valid input


		if (isBalanced(line)) {                                         //function that checks for balance, if so call conversion function to change to selected expression form depending on their decision

			cout << "\n\nYour expression is Balanced!" << endl << endl;
			                  
			if (decision == 1) {          //if they select prefix

				cout << "Would you like to convert your prefix expression to:" << endl;
				cout << "\t1)Infix\n\t2)Postfix" << endl;
				cout << "\nEnter Here:";
				cin >> choice;

				while (choice != "1" && choice != "2") {

					cout << "Please enter valid option(1 or 2):";
					cin >> choice;

				}

				decision = stoi(choice);

				if (decision == 1) {

					cout << "Your expression converted to Infix is: " << prefixToInfix(line);
					break;
				}

				if (decision == 2) {

					string temp = prefixToInfix(line);

					cout << "Your expression converted to Postfix is: " << infixToPostfix(temp);
					break;

				}


			}

			if (decision == 2) {              //if they select infix

				cout << "Would you like to convert your Infix expression to:" << endl;
				cout << "\t1)Prefix\n\t2)Postfix" << endl;
				cout << "\nEnter Here:";
				cin >> choice;

				while (choice != "1" && choice != "2") {

					cout << "Please enter valid option(1 or 2):";
					cin >> choice;

				}

				decision = stoi(choice);

				if (decision == 1) {

					cout << "Your expression converted to Prefix is: " << infixToPrefix(line);
					break;
				}

				if (decision == 2) {

					cout << "Your expression converted to Postfix is: " << infixToPostfix(line);
					break;

				}


			}

			if (decision == 3) {         //if they select postfix

				cout << "Would you like to convert your Postfix expression to:" << endl;
				cout << "\t1)Prefix\n\t2)Infix" << endl;
				cout << "\nEnter Here:";
				cin >> choice;

				while (choice != "1" && choice != "2") {

					cout << "Please enter valid option(1 or 2):";
					cin >> choice;

				}

				decision = stoi(choice);

				if (decision == 1) {

					string temp = postfixToInfix(line);

					cout << "Your expression converted to Prefix is: " << infixToPrefix(temp);
					break;
				}

				if (decision == 2) {

					cout << "Your expression converted to Infix is: " << postfixToInfix(line);
					break;

				}
			}




		}

		if (!isBalanced(line)) {                  //if not balanced, ask new user for input or end program
			cout << "\n\nYour expression is Not Balanced!! Try a new line" << endl << endl;
		}
	}



	cout << "\n\nEnd of Program" << endl;

}