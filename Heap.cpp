//
//  Heap.cpp
//  heap
//  A implementation of a heap using a vector
//
//  Created by Alexis Plaza González on 11/22/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//

#include "Heap.h"
#include "PQNode.h"
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


// PUBLIC FUNCTIONS---------------------------------------------------------------------
/*
 The constructor of the HEAP.
 pre condition: none
 post condition: size = the size of the inputed vector + 10
 */
Heap::Heap(vector<PQNode*> theVector){
    size = 0;
    myVector.resize(theVector.size() + 10);
    for(int i=0; i < theVector.size(); i++){
        myVector[i+1] = theVector[i];
        size++;
        buildHeap();
    }
}

/*
 Insert inserts a new node into the heap
 pre condition: none
 post condition: size = size + 1;
 */
void Heap::insert(int element){
    PQNode* node = new PQNode {element};
    if(size == myVector.size()-1) myVector.resize(size*2); //doubles the size of the vector.
    if(size == 0){ //if myVector is empty
        myVector[1] = node;
        size++;
        return;
    }
    size++;
    myVector[size] = node;
    percolateUp(node);
}

/*
 findMax prints and return the maximun value in the heap (myVector[1] -> key)
 precondition: none
 postcondition: none
 */
int Heap::findMax(){
    if(size == 0){
        cout<< "the heap is empty \n";
        return 0;
    }
    cout<< to_string(myVector[1]->key)+ "\n";
    return myVector[1]-> key;
}

/*
 deleteMax deletes the maximum value in the heap (myVector[1] -> key) and reorganizes
 the heap.
 precondition: none
 postcondition: size = 0 if size = 1; or size = size - 1.
 */
int Heap::deleteMax(){
    if(size == 0){
        cout << "heap is empty\n";
        return 0;
    }
    int returnValue = findMax();
    myVector[1] = move(myVector[size]);
    size--;
    percolateDown(1);
    return returnValue;
}

/*
 orginizes the elements in the heap in decreasing order and clears the heap.
 pre condition: none
 post condition: size = 0.
 */
void Heap::heapSort(){
    for(int i = size; i > 0; i--) deleteMax();
}

/* returns size (number of elements in the heap.
 pre condition: none
 post condition: none
 */
int Heap::count(){
    return size;
}
/* prints out all the elements in the heap in the order:
 parent, left child, right child...
 precondition: none
 postcondition: none
 */
void Heap:: print(){
    for(int i = 1; i <= size; i++) cout<<to_string(myVector[i]-> key) + "\n";
}



// PRIVATE FUNCTIONS--------------------------------------------------------------------

/*
 buildHeap iterates over myVector starting at the parent of the last element and ending when i <= 0. 
 percolatesDown the element in each iteration.
 precondition: none
 postcondition: changes the order of the elements in myVector.
 */
void Heap::buildHeap(){
    for(int i = floor(size/2); i>0; i--){
        percolateDown(i);
    }
}


/*percolateUp changes the position of the last element to it's appropiate position.
 precondition: none
 postcondition: changes the order of the elements in myVector.
 */

void Heap::percolateUp(PQNode* node){
    for(int hole = size; floor(hole/2) != 0 && node->key > myVector[floor(hole / 2)]-> key; hole = (floor(hole/2)))
    {
        myVector[hole] = move(myVector[floor(hole/2)]);
        myVector[floor(hole/2)] = node;
    }
}

/* percolateDown changes the position of the inputed node to a "greater" position.
 precondition: none
 postcondition: changes the order of the elements in myVector.
 */
void Heap::percolateDown(int hole){
    int child;
    PQNode* compare = myVector[hole];
    for(; hole*2 <= size; hole = child){
        child = hole*2;
        if((child != size) && (myVector[child] -> key < (myVector[child + 1])->key)) child++;
        if( myVector[child] -> key > compare -> key) myVector[hole] = move(myVector[child]);
        else break;
    }
    myVector[hole] = move(compare);
}