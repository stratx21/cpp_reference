/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sorts.h
 * Author: Josh
 *
 * Created on January 16, 2018, 5:06 PM
 */

#ifndef SORTS_H
#define SORTS_H

//MERGE::                                       O(n*lg(n))   <- lg = log base 2
//=============================================================================

/**
 * This function sets up the merge sort with the array and size of the array;
 *      this function assumes that the entire array of the size size should
 *      be sorted.
 * 
 * precondition: size is no larger than the size of the array array.
 * 
 * @param array the array to be sorted
 * @param size the size of the array to be sorted
 */
void mergeSort(int array[], int size);

/**
 * This function is the recursive function that splits the array array and
 *      merge sorts the two split parts, then merges them together.
 * 
 * precondition: end is not out of range; end must be at max the length of the
 *      array minus one.
 *               start is no less than zero.
 * 
 * @param array the array to be sorted
 * @param start the starting index to sort
 * @param end the end index to sort
 */
void mergeSort(int array[], int start, int end);

/**
 * This function merges two parts of the array, starting at start and ending
 *      at end, but split in the middle at middle. 
 * 
 * precondition: end is not out of range; end must be at max the length of the
 *      array minus one.
 *               start is no less than zero.
 * 
 * @param array the array to have its parts between start and end arranged
 * @param start the start point of the part to merge
 * @param middle the middle that separates the two parts to merge
 * @param end the end point of the part to merge
 */
void merge    (int array[], int start, int middle, int end);



//BUBBLE::                                      O(n^2) 
//=============================================================================

/**
 * This function sorts the array array in the form of a bubble sort.
 * 
 * precondition: size is no larger than the size of the array array.
 * 
 * @param array the array to be sorted
 * @param size the size of the array to be sorted
 */
void bubbleSort(int array[], int size);



//SELECTION::                                   O(n*log(n)) 
//=============================================================================
/**
 * This function sorts the array array in the form of a selection sort.
 * 
 * precondition: size is no larger than the size of the array array.
 * 
 * @param array the array to be sorted
 * @param size the size of the array to be sorted
 */
void selectionSort(int array[], int size);



//INSERTION::                                   O(n^2) 
//=============================================================================

/**
 * This function sorts the array array in the form of an insertion sort.
 * 
 * precondition: size is no larger than the size of the array array.
 * 
 * @param array the array to be sorted
 * @param size the size of the array to be sorted
 */
void insertionSort(int array[], int size);

#endif /* SORTS_H */
