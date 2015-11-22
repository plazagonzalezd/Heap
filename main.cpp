//
//  main.cpp
//  heap
//
//  Created by Alexis Plaza González on 11/22/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//
//
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <vector>
#include "Heap.h"

using namespace std;
enum EntryCode {INSERT, DELMAX, FINDMAX, PRINT, SIZE, SORT};

int main(){
    srand (time(NULL));
    vector<PQNode*> theVector; // random vector
    /* fills up the random vector with nodes with random keys.*/
    for(int i=0; i <= 15; i++){
        int value = rand() % 100;
        PQNode* node = new PQNode {value};
        theVector.push_back(node);
    }

    int response;
    int key;
    Heap heap {theVector};
    cout << "\n Enter \n 0: insert \n 1: delete max \n 2: find max \n 3: print \n 4: size \n 5: sort and clean \n";
    cin >> response;
    while(response >= INSERT && response <= SORT){
        switch(response) {
            case INSERT:
                cout<< "Please insert number: \n";
                cin >>key;
                heap.insert(key);
                break;
            case DELMAX:
                heap.deleteMax();
                break;
            case FINDMAX:
                heap.findMax();
                break;
            case PRINT:
                heap.print();
                break;
            case SIZE:
                cout << to_string(heap.count()) + "\n";
                break;
            case SORT:
                heap.heapSort();
        }
        Heap heap {theVector};
        cout << "\n Enter \n 0: insert \n 1: delete max \n 2: find max \n 3: print \n 4: size \n 5: sort and clean \n";
        cin >> response;
    }
    cout << endl << endl;
    return 0;
}
