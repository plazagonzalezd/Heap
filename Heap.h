//
//  Heap.h
//  heap
/*
 a vector implementation of a heap class. There's no limit in the number of 
 elements that the heap can support.
*/
//  Created by Alexis Plaza González on 11/22/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//

#ifndef __heap__Heap__
#define __heap__Heap__

#include <stdio.h>
#include "PQNode.h"
#include <iostream>
#include <vector>
using namespace std;

#endif /* defined(__heap__Heap__) */
class Heap{
    
public:
    /*
     The constuctor takes a vector as a parameter and builds a heap with the elements
     of the the inputed vector. It calls buildHeap for every element in the inputed element.
     */
    Heap(vector<PQNode*> theVector);
    
    /* inster an element in the heap. Takes a key as a parameter and creates a new PQNode with that
     key. The element is inserted at the end of the heap (myVector[size++]) and then it is perlocated up
     to it's correct position.
     */
    void insert(int key);
    
    /* returns the maximum number in the heap, which is always located at myVector[1]-> key
     */
    int findMax();
    
    /* delete max returns the maximum element in the heap by calling find max. It also deletes 
     the number at myVector[1] and reorganizes the vector calling perlocateDown.
     */
    int deleteMax();
    
    /* returns size, which is the number of elements in the heap*/
    
    int count();
    
    /* pritns out the number of elements in the heap. in the order: 
     parent, left child, right child... The vector is already organized
     so that iterating over the vector from myVector[1] to myVector[size] will
     print the heap in the desire order*/
    
    void print();
    /* heapSort calls deleteMax until the heap is empty. It prints the elements on the heap
     in decreasing order and cleans out the heap*/
    void heapSort();

private:
    
    /*
     organizes the inputed node to it's appropiate position. It "lowers the position of the node"
     (i.e. from Vector[10] to Vector[8]). It compares the key of the parent of the node
     and moves the node up if the parent's key is lower.
     */
    void percolateUp(PQNode* node);
    
    /* takes an integer, creates a new node with key equal to hole. Then it organizes this new node
     down the array. It compares the children of the node, and exchange them if the child is of greater
     priority than the new node.
     */
    void percolateDown(int hole);
    
    /*
       Iterates over the vector starting on the parent of the last node
     and ending at 0. Calls percolate down for each loop.
     */
    void buildHeap();
    
    vector<PQNode*> myVector; //the vector in which the heap is stored
    int size; // the number of elements in the heap.
};