#pragma once
#include <iostream>

using namespace std;

template <typename itemType>
class myStack {

private:

	int size;                        //data variables of a array stack implementation
	itemType* array;
	int top;


public:

	myStack() { top = -1; size = 20; array = new itemType[size]; }          //default const
	~myStack() { delete[] array; }

	bool empty() {             //function to check if stack is empty

		if (top == -1) {
			return true;
		}
		else {
			return false;
		}

	}

	bool full() {         //function to check if stack(array) is full

		if (top == size - 1) {
			return true;
		}
		else {
			return false;
		}

	}

	void push(const itemType& item) {               //function to push item to stack, if full create new array double in size, copy data, delete old array , push new item

		if (full()) {

			int newSize = size * 2;
			itemType* newArray = new itemType[newSize];

			for (int i = 0; i < size; i++) {

				newArray[i] = array[i];


			}

			delete[] array;
			array = newArray;
			size = newSize;


		}

		top++;
		array[top] = item;
	}

	void pop() {                //funtion to pop item in stack, if empty output error

		if (empty()) {

			cout << "Error. Cant pop empty array" << endl;
			return;

		}

		top--;
	}

	itemType topElem() {             //function to return top of stack

		if (empty()) {

			//cout << "Error. Empty array" << endl;
			return itemType();

		}


		return array[top];

	}

};
