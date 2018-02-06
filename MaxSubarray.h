#ifndef MAXSUBARRAY_H
#define MAXSUBARRAY_H

#include <iostream>
using namespace std;

constexpr static int INTEGER_MIN = -2147483647;

struct Data{
public:
    int low, high, sum;
    Data(int l, int h, int s);
};

/**
 * This function performs basic tests of the functions.
 */
void testMaxSubarray();

/**
 * This function finds the max subarray that crosses over the point mid and
 *      can reach as low as low and as high as high to find the maximum
 *      subarray with the largest sum.
 * 
 * @param array[] the array that is being passed to find the data for. 
 * @param low the integer value that is the low point to which the function
 *      will work in.
 * @param mid the mid point at which the array must include in order to find
 *      the max sum of the array that crosses the mid point.
 * @param high the high point at which the array can go up to.
 */
Data findMaxCrossingSubarray(int array[], int low, int mid, int high);

/**
 * This function finds the max subarray throughout the entire array array by 
 *      finding what range of indexes give the highest sum without skipping
 *      any numbers between the low and high of the maximum subarray. 
 * 
 * @param array[] the array that is being passed to find the data for. 
 * @param low the integer value that is the low point to which the function
 *      will work in.
 * @param high the high point at which the array can go up to.
 */
Data findMaxSubarray(int array[], int low, int high);

#endif /* MAXSUBARRAY_H */
