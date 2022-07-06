#pragma once
#ifndef UOMIDLIST_h
#define UOMIDLIST_h

#include "OrderedList.h"

template<class U>
class UOMidList : public OrderedList<U> {
private:
public:
    UOMidList(int s);
    void AddNextItem(U*);
    U* RemoveMidItem(int);
    void printList();
    bool isNullptr(int);
    int moveCount = 0;
    int compCount = 0;
};

// calls overloaded constructor from base class
template<class U>
UOMidList<U>::UOMidList(int s) : OrderedList<U>::OrderedList(s) {}

template<class U>
void UOMidList<U>::AddNextItem(U* val) {
    if (OrderedList<U>::isFull()) {
        throw Exception("List Overflow Error");
    }
    if (OrderedList<U>::isEmpty()) {
        this->data[0] = val;
        this->length++;
        compCount++;
        return;
    }
    int pos = 0;
    while (this->data[pos] != nullptr) {
        pos++;
    }
    this->data[pos] = val;
    this->length++;
}

template<class U>
U* UOMidList<U>::RemoveMidItem(int pos) {
    U* retval = NULL;
    if (OrderedList<U>::isEmpty()) {
        throw Exception("List Underflow Error");
    }
    try {
        if (isNullptr(pos)) {
            throw Exception("Position is already null");
        }
    }
    catch(Exception e){
        e.printError();
        //delete this->data[pos];        
    }
    
    retval = this->data[pos];
    // delete this->data[pos];
    moveCount++;
    compCount++;
    this->length--;
    return retval;

}


template<class U>
void UOMidList<U>::printList() {
    for (int i = 0; i < this->length; i++) {
        if (this->data[i] == nullptr) {
            break;
        }
        else {
            cout << *this->data[i] << " ";
        }
    }
}

template<class U>
bool UOMidList<U>::isNullptr(int pos) {
    return this->data[pos] == nullptr;
}
#endif