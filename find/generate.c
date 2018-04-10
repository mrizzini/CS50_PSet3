/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // if the user does not enter 2 or 3 command line inputs, this message is printed and the program is exited (return 1)
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // the user's first command line input after ./generate is assigned to the integer var n
    int n = atoi(argv[1]);

    // IF the user enters 3 command line inputs, which is optional, the IF statement kicks in. it takes the 3rd input and
    // the number which technically all chars, gets turned into an integer with atoi and then it used to seed, or initialize,
    // the internal buffer of functions such as drand48().
    // if the user does not input a 3rd command line input, the ELSE kicks in. this will make the seed NULL which will give you a
    // different value
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // for loop which will take the amount of n (the user input) and print out that many lines. on each line, it prints a
    // pseudo random non negative number between [0.0, 1.0) and multiplies that by the LIMIT which was 65536
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
