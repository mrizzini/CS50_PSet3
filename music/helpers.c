//PRjm: interesting way of doing duration with if/else, I never thought of that.
//Though you may have simplified it by mulitplying division by 8, and returning the result, would save a few steps of computation
//Good use of comments and variable naming in your frequency function, make everything very easy to follow
//Good use of switch cases in your frequency function, keeps everything in good order, I used if/else statements for mine and it is a mess to read/follow

// Helper functions for music
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
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

    char num[2];
    char den[2];
    num[0] = fraction[0];
    num[1] = '\0';
    den[0] = fraction[2];
    den[1] = '\0';
    float numerator = atoi(num);
    float denominator = atoi(den);
    float division = numerator / denominator;

    if (division == .125)
    {
        return 1;
    }
    else if (division == .25)
    {
        return 2;
    }
    else if (division == .375)
    {
        return 3;
    }
    else if (division == .5)
    {
        return 4;
    }

    else
    {
        return false;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char longNote[3]; // stores enough room for a note such as A#5
    char shortNote[2]; // stores enough room for a note such as A5
    char octave[2]; // stores enough room for the octave of any note
    string test; // will be used for our switch statment. the note will be stored in here
    float hertzFloat; // float will be used for math purposes. cannot divide integers or we will lose the decimals
    int hertz; // this will be returned. our hertz must be an integer
    // float octaveFloat; //
    // float semiTones = 0;
    char accidental[2]; // the accidental, if any, will be stored in here

    if (isdigit(note[1])) // if note is only A5, C3, F7, etc
    {
        shortNote[0] = note[0]; // shortNote will end up being only the A, B, C, etc
        shortNote[1] = '\0';
        octave[0] = note[1]; // octave will end up being only the 1, 2, 3, etc
        octave[1] = '\0';
        test = shortNote; // stores as a test variable for our switch statement
    }
    else  // if note has an accidental A#4, Cb8, etc.
    {
        longNote[0] = note[0]; // longNote will end up being the A#, Ab, C#, Cb, etc
        longNote[1] = note[1];
        longNote[2] = '\0';
        octave[0] = note[2]; // octave will end up being only the 1, 2, 3, etc
        octave[1] = '\0';
        test = longNote; // stores as a test variable for our switch statement
        // char accidental[2];
        accidental[0] = note[1]; // accidental will be used to strcmp. strcmp will only take a char * so we need to store it this way
        accidental[1] = '\0';
    }

    // octaveFloat = atoi(octave);
    int noteLength = strlen(test); // will be used to check length later on, to determine if we have an accidental or not

    switch (test[0]) // this accounts for notes A-G
    {
        case 'A':
            hertzFloat = 440;
            break;
        case 'B':
            hertzFloat = 440 * pow(2.0, 2.0 / 12.0);
            break;
        case 'C':
            hertzFloat = 440 / pow(2.0, 9.0 / 12.0);
            break;
        case 'D':
            hertzFloat = 440 / pow(2.0, 7.0 / 12.0);
            break;
        case 'E':
            hertzFloat = 440 / pow(2.0, 5.0 / 12.0);
            break;
        case 'F':
            hertzFloat = 440 / pow(2.0, 4.0 / 12.0);
            break;
        case 'G':
            hertzFloat = 440 / pow(2.0, 2.0 / 12.0);
            break;
    }

    switch (octave[0]) // once we have accounted for the note, we do the math for the octave
    {
        case 49: // 1
            hertzFloat /= 8;
            break;
        case 50: // 2
            hertzFloat /= 4;
            break;
        case 51: // 3
            hertzFloat /= 2;
            break;
        case 52: // 4
            hertzFloat = hertzFloat * 1;
            break;
        case 53: // 5
            hertzFloat *= 2;
            break;
        case 54: // 6
            hertzFloat *= 4;
            break;
        case 55: // 7
            hertzFloat *= 8;
            break;
    }

    if (noteLength == 2) // if the note has an accidental, we must do the math below
    {
        if (!strcmp(accidental, "#"))
        {
            hertzFloat = hertzFloat * pow(2.0, 1.0 / 12.0); // uses multiplication if we have a sharp
        }
        else if (!strcmp(accidental, "b"))
        {
            hertzFloat = hertzFloat / pow(2.0, 1.0 / 12.0); // uses division if we have a flat
        }
    }

    hertz = round(hertzFloat); // rounds out answer and stores as an integer. important!
    return hertz; // returns hertz as an integer
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    // if s represents a rest, return true
    // else, return false

    string lineEnd = "";
    if (!strcmp(s, lineEnd))
    {
        return true;
    }
    else
    {
        return false;
    }
}





// if (!strcmp(test, "A") || !strcmp(test, "A#") || !strcmp(test, "Ab"))
// {
//     if (!strcmp(test, "A"))
//     {
//         semiTones = (octaveFloat - 4) * 12;
//         hertzFloat = round((pow(2, (semiTones / 12)) * 440));
//     }
//     else if (!strcmp(test, "A#"))
//     {
//         semiTones = (octaveFloat - 4) * 12;
//         hertzFloat = (pow(2, (semiTones / 12)) * 440);
//         hertzFloat = round(hertzFloat * (pow(2, (1.0 / 12))));
//     }
//     else
//     {
//         semiTones = (octaveFloat - 4) * 12;
//         hertzFloat = (pow(2, (semiTones / 12)) * 440);
//         hertzFloat = round(hertzFloat / (pow(2, (1.0 / 12))));
//     }

// }

// else  if (!strcmp(test, "B") || !strcmp(test, "Bb"))
// {
//     if (!strcmp(test, "B"))
//     {
//         semiTones = ((octaveFloat - 4) * 12) + 2;
//         hertzFloat = round((pow(2, (semiTones / 12)) * 440));
//     }
//     else
//     {
//         semiTones = ((octaveFloat - 4) * 12) + 2;
//         hertzFloat = (pow(2, (semiTones / 12)) * 440);
//         hertzFloat = round(hertzFloat / (pow(2, (1.0 / 12))));
//     }
// }

// else  if (!strcmp(test, "C") || !strcmp(test, "C#") || !strcmp(test, "Cb"))
// {
//     if (!strcmp(test, "C"))
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 9;
//         hertzFloat = round((pow(2, (semiTones / 12)) * 440));
//     }
//     else if (!strcmp(test, "C#"))
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 9;
//         hertzFloat = (pow(2, (semiTones / 12)) * 440);
//         hertzFloat = round(hertzFloat * (pow(2, (1.0 / 12))));
//     }
//     else
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 9;
//         hertzFloat = (pow(2, (semiTones / 12)) * 440);
//         hertzFloat = round(hertzFloat / (pow(2, (1.0 / 12))));
//     }
// }

// else  if (!strcmp(test, "D") || !strcmp(test, "D#") || !strcmp(test, "Db"))
// {
//     if (!strcmp(test, "D"))
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 7;
//         hertzFloat = round((pow(2, (semiTones / 12)) * 440));
//     }
//     else if (!strcmp(test, "D#"))
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 7;
//         hertzFloat = (pow(2, (semiTones / 12)) * 440);
//         hertzFloat = round(hertzFloat * (pow(2, (1.0 / 12))));
//     }
//     else
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 7;
//         hertzFloat = (pow(2, (semiTones / 12)) * 440);
//         hertzFloat = round(hertzFloat / (pow(2, (1.0 / 12))));
//     }
// }

// else  if (!strcmp(test, "E") || !strcmp(test, "Eb"))
// {
//     if (!strcmp(test, "E"))
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 5;
//         hertzFloat = round((pow(2, (semiTones / 12)) * 440));
//     }
//     else
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 5;
//         hertzFloat = (pow(2, (semiTones / 12)) * 440);
//         hertzFloat = round(hertzFloat / (pow(2, (1.0 / 12))));
//     }
// }

// else  if (!strcmp(test, "F") || !strcmp(test, "F#") || !strcmp(test, "Fb"))
// {
//     if (!strcmp(test, "F"))
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 4;
//         hertzFloat = round((pow(2, (semiTones / 12)) * 440));
//     }
//     else if (!strcmp(test, "F#"))
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 4;
//         hertzFloat = (pow(2, (semiTones / 12)) * 440);
//         hertzFloat = round(hertzFloat * (pow(2, (1.0 / 12))));
//     }
//     else
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 4;
//         hertzFloat = (pow(2, (semiTones / 12)) * 440);
//         hertzFloat = round(hertzFloat / (pow(2, (1.0 / 12))));
//     }
// }

// else  if (!strcmp(test, "G") || !strcmp(test, "G#") || !strcmp(test, "Gb"))
// {
//     if (!strcmp(test, "G"))
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 2;
//         hertzFloat = round((pow(2, (semiTones / 12)) * 440));
//     }
//     else if (!strcmp(test, "G#"))
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 2;
//         hertzFloat = (pow(2, (semiTones / 12)) * 440);
//         hertzFloat = round(hertzFloat * (pow(2, (1.0 / 12))));
//     }
//     else
//     {
//         semiTones = ((octaveFloat - 4) * 12) - 2;
//         hertzFloat = (pow(2, (semiTones / 12)) * 440);
//         hertzFloat = round(hertzFloat / (pow(2, (1.0 / 12))));
//     }
// }

// else
// {
//     return 1;
// }
