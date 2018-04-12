// Helper functions for music

#include <cs50.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
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
