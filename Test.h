#pragma once
#include <iostream>
using namespace std;

class Exception {//exception class for throwing error
public:
	Exception(const string& msg) : msg_(msg) {}
	~Exception() {}
	string getMessage() const { return(msg_); }
private:
	string msg_;
};
// We can use this for any data type that supports
template <typename T>
class OrderedList {//template class
public:
	T* array;//create array of size 20
	int size;
public:
	OrderedList(int size) {//constructor
	//initialize array with size 20 of datatype T (i.e data type will be alloted compile time)
		array = new T[size];
		this->size = size;//set size to class size variable
	}
	//The AddItem method should start at the front of the array when searching
	//for a place to insert a new item.
	void AddItem(T data) {
		try {
			if (IsFull()) {//if array is full throw error
				throw(Exception("Error :Array is full"));
			}

		}
		catch (Exception& e) {
			cout << e.getMessage() << endl;
		}
		for (int i = 0; i < size; i++) {
			if (IsEmpty(i)) {
				array[i] = data;

				cout << "Data inserted";
				break;
			}
		}
	}
	//The RemoveItem method should ensure that the items in the array are still
	//in order and there are no empty spots between items.

	void RemoveItem(int data) {
		bool item_exists = false;
		for (int i = 0; i < size; i++) {
			if (array[i] == data) {
				item_exists = true;
				array[i] = NULL;//remove item of specific index
			}

		}
		try {
			if (!item_exists) {
				throw(Exception("Error :Item does not exists"));
			}
			cout << "Data removed";
			T* arr = array;//create temporary array to store pointer array data

			int j = 0;
			//insert data into array again in order without any null in betweeb
			for (int i = 0; i < size; i++) {

				if (arr[i] != NULL) {
					array[j] = arr[i];
					j++;
				}
				array[i] = NULL;



			}

		}
		catch (Exception& e) {
			cout << e.getMessage() << endl;
		}

	}
	bool IsEmpty(int index) {
		return array[index] == NULL;//if pointer array index is empty return true else false
	}
	bool IsFull() {
		bool full;
		for (int i = 0; i < size; i++) {
			if (!IsEmpty(i)) {//if array index is not empty
				full = true;//set true
			}
			else {
				full = false;//else set false
			}

		}
		return full;
	}
	void MakeEmpty() {
		for (int i = 0; i < size; i++) {
			array[i] = NULL;//set array to null
		}
	}
	void print() {
		cout << "\nArray contents are \nindex\tdata\n";
		for (int i = 0; i < size; i++)
			cout << i << "\t" << *(array + i) << "\n";
		cout << endl;
	}
};

/*
int main() {
	int SIZE = 50;//decloare size to 20
	int data;//set datatype of data to integer
	OrderedList<int> o(SIZE);
	/* for(int i=0;i<SIZE-1;i++){//insert dummy data
	o. array[i]=i+2;
	}
int ch;
do {//loop until user does not input 4
	cout << "1.AddItem\n2.RemoveItem\n3.MakeEmpty\n4.exit\n";
	cin >> ch;
	switch (ch) {
	case 1:
		cout << "Enter data to insert ";
		cin >> data;//input data of declared datatype
		o.AddItem(data);
		o.print();
		break;
	case 2:
		cout << "Enter data to remove ";
		cin >> data;
		o.RemoveItem(data);
		o.print();
		break;
	case 3:
		o.MakeEmpty();
		o.print();
		break;
	}
} while (ch != 4);
return 0;
}
*/

