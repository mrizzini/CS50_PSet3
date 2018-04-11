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

    if (n < 0)
    {
    return false;
    }

    int start = 0;
    int middle;
    int end = n - 1;
    int size = n;

    while (size > 0)
    {
        // middle = (start + end) / 2;
        eprintf("value is %i\n", value);
        eprintf("size is %i and end is %i and middle is %i and start is %i and values[middle] is %i\n", size, end, middle, start, values[middle]);

        middle = (start + end) / 2;

        if (values[middle] == value)
        {
             eprintf("final count size is %i and end is %i and middle is %i and start is %i and values[middle] is %i\n", size, end, middle, start, values[middle]);
            return true;
        }


        else if (value > values[middle]) // search right side of array
        {
                size = size / 2;
                start = middle + 1;
                eprintf("2nd size is %i and end is %i and middle is %i and start is %i and values[middle] is %i\n", size, end, middle, start, values[middle]);

        }
        else if (value < values[middle]) // search left side of array
        {
                size = size / 2;
                end = middle - 1;
                if (end < 0)
                {
                    end = 0;
                }

                eprintf("3rd size is %i and end is %i and middle is %i and start is %i and values[middle] is %i\n", size, end, middle, start, values[middle]);

        }
    }
    // for (int i = 0; i < n; i++)  THIS WAS LINEAR SEARCH CODE USED FOR PLACEHOLDER
    // {
    //     if (values[i] == value)
    //     {
    //         return true;
    //     }
    // }

    // while list > 0 PSEUDOCODE FOR BINARY SEARCH
        // look at middle of list
        // if number is found, return true
        // else if number higher, search left
        // else if number lower, search right
    // else return false

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    // BUBBLE SORT
    int swap = 1;
    int tempFirst;
    int tempSecond;

    while (swap != 0)
    {
        swap = 0;
        for (int i = 0; i < (n - 1); i++)
        {
            if (values[i] > values[i + 1])
            {
                tempFirst = values[i];
                tempSecond = values[i + 1];
                values[i] = tempSecond;
                values[i + 1] = tempFirst;
                swap++;
            }
        }
    }


    return;
}
