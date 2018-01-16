/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Searches.cpp
 * Author: Josh
 * 
 * Created on January 16, 2018, 5:07 PM
 */

#include "Searches.h"

//LINEAR::
//=============================================================================

int linearSearch(int array[], int size, int item){   //O(n)
    //LINEAR SEARCH::
    int index = -1;
    bool found = false;
    int i = 0;
    while(!found && i < size){
        if(array[i] == item){
            found = true;
            index=i;
        }else{
            i++;
        }
    }
    
    return index;
}

//BINARY::
//=============================================================================

//PRECONDITION:: array must be sorted before use
int binarySearch(int array[], int size, int item){//O(log n)
    int first = 0,
        last  = size-1,
        middle;
    int index = 1;
    bool found = false;
    
    while(!found && first <= last){
        middle = (first + last)/2;
        if(array[middle] == item){
            found = true;
            index = middle;
        }else if(array[middle] > item){
            last = middle-1;
        }else{
            last = middle+1;
        }
    }
    
    
    return index;
}
