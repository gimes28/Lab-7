#pragma once
#ifndef EXCEPTION_h
#define EXCEPTION_h

#include <cstring>
#include <iostream>
using namespace std;

// Exception class for the Queue class
class Exception {
private:
    string errorMessage;
public:
    Exception(string error = "NULL") {
        errorMessage = error;
    }
    void printError() {
        cout << errorMessage << endl;
    }
};

#endif
