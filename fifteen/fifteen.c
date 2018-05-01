//PRjm: good use a variable names, I like how when doing the for loops, you use row and column instead of letters to make it more descriptive
// the use of the blankspace variable also makes it very clear what is going on
//comments for the if/else statements in the move function would be helpful, it is difficult to tell what is happening (I did the same thing, and looking at my own code now it is tough to read)
//good comments in your won function, interesting way of checking if the last tile is correct (that it equals 0) - the function is easy to follow


/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;


// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n", DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    // int board[d][d];

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    // TODO
    //  for each row
    //     for each column
    //         set value for tile

    // int board[d][d];
    int maxNum = (d * d) - 1;
    int row;
    int column;


    for (row = 0; row < d; row++)
    {
        for (column = 0; column < d; column++)
        {
            board[row][column] = maxNum;
            maxNum--;
        }
    }

    if (d % 2 == 0)
    {
        board[row - 1][column - 3] = 1; // changes [3][1]
        board[row - 1][column - 2] = 2; // changes [3][2]
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    string blankSpace = " __";

    for (int row = 0; row < d; row++)
    {
        for (int column = 0; column < d; column++)
        {
            if (board[row][column] == 0)
            {
                printf("%2s |", blankSpace);
            }
            else
            {
                printf(" %2i |", board[row][column]);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    // TODO

    int tileRow;
    int tileColumn;
    int row;
    int column;
    int blankRow;
    int blankColumn;

    if (tile < 0 || tile > (d * d - 1))
    {
        return false;
    }

    for (row = 0; row < d; row++)
    {
        for (column = 0; column < d; column++)
        {
            if (board[row][column] == 0)
            {
                blankRow = row;
                blankColumn = column;
            }
            if (board[row][column] == tile)
            {
                tileRow = row;
                tileColumn = column;
            }
        }
    }

    if (board[tileRow][tileColumn + 1] == 0 && tileColumn + 1 < d)
    {
        // printf("were good\n");
        board[blankRow][blankColumn] = board[tileRow][tileColumn];
        blankRow = tileRow;
        blankColumn = tileColumn;
        board[tileRow][tileColumn] = 0;
        return true;

    }
    else if (board[tileRow][tileColumn - 1] == 0 && tileColumn - 1 >= 0)
    {
        // printf("were good!\n");
        board[blankRow][blankColumn] = board[tileRow][tileColumn];
        blankRow = tileRow;
        blankColumn = tileColumn;
        board[tileRow][tileColumn] = 0;
        return true;
    }
    else if (board[tileRow - 1][tileColumn] == 0 && tileRow - 1 >= 0)
    {
        // printf("were good!!\n");
        board[blankRow][blankColumn] = board[tileRow][tileColumn];
        blankRow = tileRow;
        blankColumn = tileColumn;
        board[tileRow][tileColumn] = 0;
        return true;
    }
    else if (board[tileRow + 1][tileColumn] == 0 && tileRow + 1 < d)
    {
        // printf("were good!!!\n");
        board[blankRow][blankColumn] = board[tileRow][tileColumn];
        blankRow = tileRow;
        blankColumn = tileColumn;
        board[tileRow][tileColumn] = 0;
        return true;
    }

    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    // TODO
    int column;
    int row;
    int test = 1;

    // loop thru entire board
    // to start, if the first number on board == 1 (test), then increment test to 2 and check again to see if the next number == 2.
    // then increment test. if it does not equal the test, then it will fall through to return false
    for (row = 0; row < d; row++)
    {
        for (column = 0; column < d; column++)
        {
            if (board[row][column] == test)
            {
                test++;
            }
        }
    }

    // this will check if test makes it up to the last number on the board before 0 (the last tile. if it does, it needs to check
    // if the the last number on the board is indeed 0. if it is, we know we have won and return true. if not, return false
    if (test == (d * d))
    {
        if (board[d - 1][d - 1] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false; // if the numbers are not in order the code should fall to here and return false


}
