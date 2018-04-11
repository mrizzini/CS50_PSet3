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

        // eprintf("values0 is %i\n", values[0]);
        // eprintf("values1 is %i\n", values[1]);
        // eprintf("values2 is %i\n", values[2]);
        // eprintf("values3 is %i\n", values[3]);
        // eprintf("values4 is %i\n", values[4]);
        // eprintf("values5 is %i\n", values[5]);
        // eprintf("values5 is %i\n", values[6]);
        // eprintf("values5 is %i\n", values[7]);
        // eprintf("values5 is %i\n", values[8]);
        // eprintf("values5 is %i\n", values[9]);

    int start = 0;
    int middle;
    int end = n;
    int size = n;

    // middle = (start + end) / 2;
    // size = sizeof(values) / sizeof(values[0]);

    // eprintf("size of array is is %i and middle is %i\n", n, middle);

    while (size > 0)
    {
        middle = (start + end) / 2;
        eprintf("middle is %i\n", middle);

        if (middle == value)
        {
            return true;
        }
        else if (value > values[middle]) // search right side of array
        {
            start = middle + 1;
            if ((size / 2) % 2 == 0)
            {
                size = size / 2;
            }
            else
            {
                size = (size + 1) / 2;
            }

        }
        else if (value < values[middle]) // search left side of array
        {
            end = middle - 1;
            if ((size / 2) % 2 == 0)
            {
                size = size / 2;
            }
            else
            {
                size = (size + 1) / 2;
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     if (values[i] == value)
    //     {
    //         return true;
    //     }
    // }

    // while list > 0
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
    int swap = 1;
    int tempFirst;
    int tempSecond;

        // eprintf("1st values0 is %i\n", values[0]);
        // eprintf("1st values1 is %i\n", values[1]);
        // eprintf("1st values2 is %i\n", values[2]);
        // eprintf("1st values3 is %i\n", values[3]);
        // eprintf("1st values4 is %i\n", values[4]);
        // eprintf("1st values5 is %i\n", values[5]);
        // eprintf("1st values5 is %i\n", values[6]);
        // eprintf("1st values5 is %i\n", values[7]);
        // eprintf("1st values5 is %i\n", values[8]);
        // eprintf("1st values5 is %i\n", values[9]);


    while (swap != 0)
    {
        swap = 0;
        for (int i = 0; i < (n - 1); i++)
        {
            if (values[i] > values[i + 1])
            {
                // eprintf("for loop value is %i and value i+1 is %i\n", values[i], values[i + 1]);
                tempFirst = values[i];
                tempSecond = values[i + 1];
                values[i] = tempSecond;
                values[i + 1] = tempFirst;
                // values[i] = values[i + 1];
                // values[i + 1] = values[i - 1];
                swap++;
            }
        }

    }

        // eprintf("values0 is %i\n", values[0]);
        // eprintf("values1 is %i\n", values[1]);
        // eprintf("values2 is %i\n", values[2]);
        // eprintf("values3 is %i\n", values[3]);
        // eprintf("values4 is %i\n", values[4]);
        // eprintf("values5 is %i\n", values[5]);
        // eprintf("values5 is %i\n", values[6]);
        // eprintf("values5 is %i\n", values[7]);
        // eprintf("values5 is %i\n", values[8]);
        // eprintf("values5 is %i\n", values[9]);

    return;
}
