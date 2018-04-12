/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */       //(  needle, haystack, size )
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    // return false immediately if n is non-positive.
    if (n < 0)
    {
        return false;
    }

    int start = 0; // start of array, or portion of array we are searching
    int middle; // middle of array, or portion of array we are searching
    int end = n - 1; // end of array, or portion of array we are searching
    int size = n; // size of array, or portion of array we are searching

    while (size > 0)
    {
        // middle = (start + end) / 2;
        // eprintf("value is %i\n", value);
        // eprintf("size is %i and end is %i and middle is %i and start is %i and values[middle] is %i\n", size, end, middle, start, values[middle]);
        middle = (start + end) / 2; // this sets middle of array. if it is odd dividing an odd number, it goes to the left

        if (values[middle] == value) // if the middle of the array is the value we are looking for, return true
        {
            // eprintf("final count size is %i and end is %i and middle is %i and start is %i and values[middle] is %i\n", size, end, middle, start, values[middle]);
            return true;
        }

        else if (value > values[middle]) // search right side of array if value we are looking for is greater than the middle value
        {
            size = size / 2; // divides size in half, we only need to worry about the right side
            start = middle + 1; // sets the start point to the right of middle. don't need to worry about middle index anymore
            // eprintf("2nd size is %i and end is %i and middle is %i and start is %i and values[middle] is %i\n", size, end, middle, start, values[middle]);
        }
        else if (value < values[middle]) // search left side of array if value we are looking for is less than the middle value
        {
            size = size / 2; // divides size in half, we only need to worry about the left side
            end = middle - 1; // sets end point to left of the middle. don't need to worru about middle index anymore
            if (end < 0) // if end goes to -1, reset to 0
            {
                end = 0;
            }
            // eprintf("3rd size is %i and end is %i and middle is %i and start is %i and values[middle] is %i\n", size, end, middle, start, values[middle]);
        }
        // after one of the else if statements run, the code will go and check if size is 0. if it is, then we continue on and
        // return false. we know the value is not in the array.
        // if it is not, it will set the middle again, which will be different with the new start or end index. and code continues
    }

    // for (int i = 0; i < n; i++)  THIS WAS LINEAR SEARCH CODE USED FOR PLACEHOLDER
    // {
    //     if (values[i] == value)
    //     {
    //         return true;
    //     }
    // }

    // while list > 0               PSEUDOCODE FOR BINARY SEARCH
        // look at middle of list
        // if number is found, return true
        // else if number higher, search left
        // else if number lower, search right
    // else return false

    return false; // if the while loop above never returns true, the code runs down to here and returns false to find.c
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    // BUBBLE SORT
    int swap = 1; // sets swap counter
    int tempFirst; // integer variables to be used to swap variables later
    int tempSecond;

    while (swap != 0)
    {
        swap = 0; // set swap counter to 0
        for (int i = 0; i < (n - 1); i++) // n - 1 so that we are never hitting past the array down below
        {
            if (values[i] > values[i + 1]) // if the first value of array is bigger than the next, run below
            {
                tempFirst = values[i]; // sets up value to be swapped
                tempSecond = values[i + 1]; // sets up value to be swapped
                values[i] = tempSecond; // swap the first value of array with the one smaller, the next one
                values[i + 1] = tempFirst; // swap the second value of array with the one bigger, the value right before it
                swap++; // add to swap counter.
            }
        }
    } // if the whole code runs with swap being 0, then we know the array is fully sorted

    return;
}
