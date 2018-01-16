/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sorts.cpp
 * Author: Josh
 * 
 * Created on January 16, 2018, 5:06 PM
 */

#include "Sorts.h"

void testSort(){
    //test merge sort:
    int size = 16;
    //The end result should be -1 to 14 in order V
    int testing[] = {5,6,2,1,11,0,14,9,10,13,7,4,8,12,3,-1};
    
    cout << "Before sort:" << endl;
    for(int i=0; i<size; i++){//print the testing array
        cout << testing[i] << " ";
    }
    cout << endl << endl;
    
    mergeSort(testing,size);
    
    cout << "After sort:" << endl;
    for(int i=0; i<size; i++){//print the testing array
        cout << testing[i] << " ";
    }
    cout << endl << endl;
    
}

//=============================================================================
//Merge Sort Functions::
//[START]
//=============================================================================

void mergeSort(int array[], int size){
    mergeSort(array,0,size-1);
}

void mergeSort(int array[], int start, int end){
    if(start < end){
        int middle = (start + end)/2;
        mergeSort(array, start,    middle); //Sort array from start to middle
        mergeSort(array, middle+1, end);    //Sort array from middle+1 to end
        merge(array, start, middle, end);
    }
}

void merge(int array[], int start, int middle, int end){
    int length = end-start+1;
    
    int leftSorted  = start;
    int rightSorted = middle+1;
    
    int* sorted = new int[length];
    
    for(int count = 0; count < length; count++){
        if(leftSorted > middle){//The left part has been used completely
            sorted[count] = array[rightSorted];
            rightSorted++;
        } else if(rightSorted > end){//The right part has been used completely
            sorted[count] = array[leftSorted];
            leftSorted++;
        } else if(array[leftSorted] < array[rightSorted]){//The next element on the left side is less than the next element on the right side
            sorted[count] = array[leftSorted];
            leftSorted++;
        } else{//The next element on the right side is less than the next element on the left side
            sorted[count] = array[rightSorted];
            rightSorted++;
        }
    }
    
    //Set the array passed in elements that were sorted to the sorted parts
    for(int sortedElement = 0; sortedElement < length; sortedElement++){
        array[start] = sorted[sortedElement];
        start++;
    }
    
    delete [] sorted;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//Merge Sort Functions
//[END]
//=============================================================================


void bubbleSort(int array[], int size){
    //BUBBLE::                                      O(n^2) 
    bool sorted = false;
    for(int pass = 0; !sorted && pass < size-1; pass++){
        sorted=true;
        for(int i = 0; i < size-1-pass; i++){
            if(array[i] > array[i+1]){
                swap(array[i], array[i+1]);
                sorted=false;
            }
        }
    }
}

void selectionSort(int array[], int size){
    //SELECTION::                                   O(n log n) 
    for(int pass = 0; pass < size-1; pass++){
        for(int scan = pass + 1; scan < size; scan++){
            if(array[scan] > array[scan+1]){
                swap(array[scan], array[scan+1]);
            }
        }
    }
}

void insertionSort(int array[], int size){
    //INSERTION::                                   O(n^2) 
    for(int j = 1; j < size; j++){
        int key = array[j];
        //Insert A[j] into the sorted sequence A[1...j-1]. <- ?
        int i = j-1;
        while(i >= 0 && array[i] > key){//switch "a[i] > key" to "a[i] < key" for decreasing order
            array[i+1] = array[i];
            i = i-1;
        }
        array[i+1] = key;
    }
}

