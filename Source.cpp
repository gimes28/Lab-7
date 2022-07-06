#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "OrderedList.h"
#include "MidList.h"
#include "UOMidList.h"

using namespace std;

int main() {

    srand(time(NULL));

    //Task 4
    int size;
    cout << "Enter amount of items in list" << endl;
    cin >> size;

    OrderedList<int> orderlist(size);
    MidList<int> midlist(size);
    UOMidList<int> uomidlist(size);

    for (int i = 0; i < size; i++) {
        int num = rand() % 100 + 1;
        int* newItem = new int(num);
        cout << "Number entered: " << num << endl;
        try {
            orderlist.AddItem(newItem);
            midlist.AddMidItem(newItem);
            uomidlist.AddNextItem(newItem);
        }
        catch (Exception e) {
            e.printError();
        }
    }
    cout << endl;
    for (int i = 0; i < size - 5; i++) {
        int num1 = rand() % (size - 5) + 1;
        cout << "Remove position: " << num1 << endl;
        cout << "Orderlist: " << *orderlist.RemoveItem(num1) << endl;
        cout << "Midlist: " << *midlist.RemoveItem(num1) << endl;
        cout << "OUMidlist: " << *uomidlist.RemoveMidItem(num1) << endl;
    }
    //efficiency 

    cout << "Efficiency of orderedList: " << orderlist.moveCount / static_cast<double>(size) << " Moves and " << orderlist.compCount / static_cast<double>(size) << " comparisons" << endl;
    cout << "Efficiency of midList: " << midlist.moveCount / static_cast<double>(size) << " Moves and " << midlist.compCount / static_cast<double>(size) << " comparisons" << endl;
    cout << "Efficiency of unorderedMidList: " << uomidlist.moveCount / static_cast<double>(size) << " Moves and " << uomidlist.compCount / static_cast<double>(size) << " comparisons" << endl;

}