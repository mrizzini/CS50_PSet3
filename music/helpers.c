// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    // take a fraction as a STRING (1/8, 1/4,/ 3/8)
    // assume numerator and denominator are each one digit
    // assume the fraction works out to a whole number of eighth notes
    // Returns the number (INTEGER) of eigth notes long (1/8 = 1 | 1/4 = 2 | 3/8 = 3)
    // possible denominator values are 8, 4, 2, 1
    // int numerator = atoi(fraction[0]);
    // int denominator = atoi(fraction[2]);

    char num = fraction[0];
    char den = fraction[2];
    float numerator = num - '0';
    float denominator = den - '0';
    float division = numerator / denominator;
    int noteLength;

        if (division == .125)
    {
        noteLength = 1;
        return noteLength;
    }
    if (division == .25)
    {
        noteLength = 2;
        return noteLength;
    }
    if (division == .375)
    {
        noteLength = 3;
        return noteLength;
    }
    if (division == .5)
    {
        noteLength = 4;
        return noteLength;
    }


}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    // if s represents a rest, return true
    // else, return false

    string lineEnd = "";
    if (strcmp(s, lineEnd) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
