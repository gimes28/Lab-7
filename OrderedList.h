#pragma once
#ifndef ORDEREDLIST_h
#define ORDEREDLIST_h

#include "Exception.h"

template<class O>
class OrderedList {
public:
    O** data;
    int SIZE;
    int length;

    OrderedList();
    OrderedList(int);
    void AddItem(O*);
    O* RemoveItem(int pos);
    bool isEmpty();
    bool isFull();
    void makeEmpty();
    int Length();

    int moveCount = 0;
    int compCount = 0;

    bool operator == (const OrderedList&);
    bool operator < (const OrderedList&);
    bool operator > (const OrderedList&);
};

template<class O>
OrderedList<O>::OrderedList() {
    this->data = new O * [0];
    this->SIZE = 0;
    this->length = 0;
}

template<class O>
OrderedList<O>::OrderedList(int s) {
    this->data = new O * [s];
    this->SIZE = s;
    this->length = 0;
    for (int i = 0; i < s; i++) {
        data[i] = nullptr;
    }
}

template<class O>
void OrderedList<O>::AddItem(O* val) {
    if (isFull()) {
        throw Exception("List Overflow Error");
    }
    if (isEmpty()) {
        data[0] = val;
        length++;
        compCount++;
        return;
    }
    O* tempVal;
    for (int pos = 0; pos <= SIZE; pos++) {
        if (data[pos] == nullptr) {
            data[pos] = val;
            data[pos + 1] = nullptr;
            moveCount++;
            compCount++;
        }
        else if (*data[pos] >= *val) {
            tempVal = data[pos];
            data[pos] = val;
            val = tempVal;
            moveCount++;
            compCount++;
        }
    }
    length++;
}

template<class O>
O* OrderedList<O>::RemoveItem(int pos) {
    if (isEmpty()) {
        throw Exception("List Underflow Error");
    }
    O* retval = data[pos];
    for (int i = pos; i < SIZE - 1; i++) {
        data[i] = data[i + 1];
        moveCount++;
        compCount++;
    }
    length--;
    return retval;
}

template<class O>
bool OrderedList<O>::isEmpty() {
    return length == 0;
}

template<class O>
bool OrderedList<O>::isFull() {
    return length >= SIZE;
}

template<class O>
void OrderedList<O>::makeEmpty() {
    length = 0;
};

template<class O>
int OrderedList<O>::Length() {
    return length;
};


template<class O>
bool OrderedList<O>::operator == (const OrderedList<O>& item) {
    return item == this->item;
}

template<class O>
bool OrderedList<O>::operator < (const OrderedList<O>& item) {
    return item < this->item;
}

template<class O>
bool OrderedList<O>::operator > (const OrderedList<O>& item) {
    return item > this->item;
}
#endif