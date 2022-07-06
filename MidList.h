#pragma once
#ifndef MIDLIST_h
#define MIDLIST_h

#include "OrderedList.h"

template<class M>
class MidList : public OrderedList<M> {
private:
public:
    MidList(int s);
    void AddMidItem(M*);
    void printList();
    int moveCount = 0;
    int compCount = 0;
};

// calls overloaded constructor from base class
template<class M>
MidList<M>::MidList(int s) : OrderedList<M>::OrderedList(s) {}

template<class M>
void MidList<M>::AddMidItem(M* val) {
    try {
        if (OrderedList<M>::isFull()) {
            throw Exception("List Overflow Error");
        }
    }
    catch (Exception e) {
        e.printError();
    }
    if (OrderedList<M>::isEmpty()) {
        this->data[0] = val;
        this->length++;
        compCount++;
        return;
    }
    M* tempVal;
    int pos = this->SIZE / 2;   // start in the middle of the array
    if (this->data[pos] == nullptr || *val < *this->data[pos]) {
        while (this->data[pos] == nullptr || *val < *this->data[pos]) {   // move pos left
            // moveCount++;
            compCount++;
            if (pos == 0) {
                break;
            }
            pos--;
        }
    }
    if (*val > *this->data[pos]) {
        if (this->data[pos] == nullptr) {
            this->data[pos] = val;
        }
        else {
            while (this->data[pos] != nullptr && *val > *this->data[pos]) {   // move pos right
                pos++;
                // moveCount++;
                compCount++;
            }
        }
    }

    while (pos < this->length + 1) {  // shifting over everything in the array
        tempVal = this->data[pos];
        this->data[pos] = val;
        val = tempVal;
        pos++;
        moveCount++;
    }
    this->length++;
}

template<class M>
void MidList<M>::printList() {
    for (int i = 0; i < this->length; i++) {
        if (this->data[i] == nullptr) {
            break;
        }
        else {
            cout << *this->data[i] << " ";
        }
    }
}

#endif