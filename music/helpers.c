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

    else
    {
        return false;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{

    // string fullNote = "A8";
    char longNote[3];
    char shortNote[2];
    char octave[2];
    string test;
    float hertzFloat;
    int hertz;
    float octaveFloat;
    float semiTones = 0;
    float one = 1;
    // float multiplier;
    // float power;

    if (isdigit(note[1])) // if note is only A5, C3, F7, etc
    {
        shortNote[0] = note[0];
        shortNote[1] = '\0';
        octave[0] = note[1];
        octave[1] = '\0';
        test = shortNote;
    }
    else if (!isdigit(note[1])) // if note has an accidental A#4, Cb8, etc.
    {
        longNote[0] = note[0];
        longNote[1] = note[1];
        longNote[2] = '\0';
        octave[0] = note[2];
        octave[1] = '\0';
        test = longNote;
    }

    octaveFloat = atoi(octave);

    if (strcmp(test, "A") == 0)
    {
        semiTones = (octaveFloat - 4) * 12;
        // A5 multiply by 2 A6 multiply by 4
        // multiplier =
        hertzFloat = round((pow(2, (semiTones / 12)) * 440));
    }
    else if (strcmp(test, "A#") == 0)
    {
        semiTones = (octaveFloat - 4) * 12;
        hertzFloat = (pow(2, (semiTones / 12)) * 440);
        hertzFloat = round(hertzFloat * (pow(2, (one / 12))));
    }
    else if (strcmp(test, "Ab") == 0)
    {
        semiTones = (octaveFloat - 4) * 12;
        hertzFloat = (pow(2, (semiTones / 12)) * 440);
        // printf("hertzFIRST is %i\n", hertz);
        hertzFloat = round(hertzFloat / (pow(2, (one / 12))));
    }

    else
    {
        hertzFloat = 0;
    }

    hertz = hertzFloat;
    return hertz;

    // printf("octave is %c\n", octave[0]);
    // printf("short note is %c\n", shortNote[0]);
    // printf("long note is %c%c\n", longNote[0], longNote[1]);
    // printf("hertzFloat is %f\n", hertzFloat);
    // printf("FINAL HERTZ is %i\n", hertz);



    // TODO
    // takes in a string (A6)
    // outputs an integer (hertz)

    // if (strcmp(note, "A4") == 0)
    // {
    //     return 440;
    // }

    // int frequency;

    // if (strcmp(note, "A0") == 0)
    // {
    //     frequency = 440 / 16;
    // }
    // if (strcmp(note, "A1") == 0)
    // {
    //     frequency = 440 / 8;
    // }
    // if (strcmp(note, "A2") == 0)
    // {
    //     frequency = 440 / 4;
    // }
    // if (strcmp(note, "A3") == 0)
    // {
    //     frequency = 440 / 2;
    // }
    // if (strcmp(note, "A4") == 0)
    // {
    //     frequency = 440;
    // }
    // if (strcmp(note, "A5") == 0)
    // {
    //     frequency = 440 * 2;
    // }
    // if (strcmp(note, "A6") == 0)
    // {
    //     frequency =  440 * 4;
    // }
    // if (strcmp(note, "A7") == 0)
    // {
    //     frequency = 440 * 8;
    // }
    // if (strcmp(note, "A8") == 0)
    // {
    //     frequency = 440 * 16;
    // }

    // return frequency;

    // else if
    // {
    //     return false;
    // }
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
