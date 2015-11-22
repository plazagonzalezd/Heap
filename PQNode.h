//
//  PQNode.h
//  heap
/*
 PQNodes are the items stored in the heap.
 Every node has a field calle key, which is an 
 integer.
 */
//  Created by Alexis Plaza González on 11/25/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//

#ifndef __heap__PQNode__
#define __heap__PQNode__

#include <stdio.h>

struct PQNode{
    /* the constructor takes an integer and stores it in key*/
    PQNode(int key);
    int key;
};
#endif /* defined(__heap__PQNode__) */
