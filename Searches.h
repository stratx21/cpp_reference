/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Searches.h
 * Author: Josh
 *
 * Created on January 16, 2018, 5:07 PM
 */

#ifndef SEARCHES_H
#define SEARCHES_H

/**
 * This function performs a Linear Search on the array array.
 * 
 * precondition: size is no larger than the size of the array array.
 * 
 * @param array the array to be searched
 * @param size the size of the array
 * @param item the item to be found
 * @return the index at which the item to be found item was found, or -1 if it
 *      was not found.
 */
int linearSearch(int array[], int size, int item);



//PRECONDITION:: array must be sorted before use
/**
 * This function performs a Binary Search on the array array.
 * 
 * precondition: size is no larger than the size of the array array.
 *               The array must be sorted before it is searched.       <- *NOTE
 * 
 * @param array the array to be searched
 * @param size the size of the array
 * @param item the item to be found
 * @return the index at which the item to be found item was found, or -1 if it
 *      was not found.
 */
int binarySearch(int array[], int size, int item);

#endif /* SEARCHES_H */
