/*
Samuel Kundrát
xkundrs00
260012
*/

// CONSTANTS for max size of array and for conversion between lower and upper case
#define MAXARRAYSIZE 101
#define UP 'A' - 'a'
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// declarations of needed functions
char *getAllowedKey(char inputArray[MAXARRAYSIZE], int *rpt, int *inDatabase);
int isIn(char array[], char letter);
char *getFirstLetter();
int isStringInLine(char inputString[MAXARRAYSIZE], char lineString[]);

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    char *allowed;
    char array[MAXARRAYSIZE];
    char buffer;

    int rpt = 0;
    int inDatabase = 0;

    // conversion of input array of chars into upper case
    if (argc > 1)
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                array[i] = argv[1][i] + UP;
            }
            else
            {
                array[i] = argv[1][i];
            }
            i++;
        }
    }

    // switch for number of arguments variations
    switch (argc)
    {
    case 1:
        printf("Enable: %s", getFirstLetter());
        break;

    case 2:
        // checker for only alphabetical input
        while (argv[1][j] != '\0')
        {
            if (!isalpha(argv[1][j]) && argv[1][j] != ' ')
            {
                printf("Wrong input!");
                return 1;
            }
            j++;
        }

        allowed = getAllowedKey(array, &rpt, &inDatabase);
        // checkes if input is even in database
        if (allowed[0] == '\0' && (rpt == 0 && inDatabase == 0))
        {
            printf("Not found");
            return 1;
        }
        else
        {
            // checks if input matches only one address in database
            if (rpt == 0 && inDatabase == 1)
            {
                printf("Found: ");
                for (i = 0; argv[1][i] != '\0'; i++)
                {
                    printf("%c", array[i]);
                }
                for (i = 0; allowed[i] != '\0'; i++)
                {
                    printf("%c", allowed[i]);
                }

                return 0;
            }

            printf("Enable: ");
            // alpha sort for enabled keys
            for (i = 0; allowed[i] != '\0'; i++)
            {
                for (j = 0; allowed[j] != '\0'; j++)
                {
                    if (allowed[j] > allowed[j + 1] && allowed[j + 1] != '\0')
                    {
                        buffer = allowed[j];
                        allowed[j] = allowed[j + 1];
                        allowed[j + 1] = buffer;
                    }
                }
            }
            // print for enabled keys
            while (allowed[k] != '\0')
            {
                printf("%c", allowed[k]);
                k++;
            }
        }
        break;
        // if number of arguments  does not match any case
    default:
        printf("Wrong input!");
        return 1;
        break;
    }
    return 0;
}

// function that checks that strings matches
int isStringInLine(char inputString[MAXARRAYSIZE], char lineString[])
{
    int k = 0;
    int isIn = 0;
    while (inputString[k] != '\0')
    {
        if (inputString[k] == lineString[k])
        {
            isIn = 1;
        }
        else
        {
            return 0;
        }
        k++;
    }
    return isIn;
}

// function that returns every possible key after string match or only matching string in database
char *getAllowedKey(char inputArray[MAXARRAYSIZE], int *rpt, int *inDatabase)
{
    int i = 0;
    char letter;

    *inDatabase = 0;
    *rpt = 0;

    char lineString[MAXARRAYSIZE];
    static char letterArray[MAXARRAYSIZE] = {0};
    static char wordBufer[MAXARRAYSIZE];

    while ((letter = getchar()) != EOF)
    {
        i = 0;
        while (lineString[i] != '\0')
        {
            lineString[i] = 0;
            i++;
        }
        i = 0;
        while (letter != '\n' && letter != EOF)
        {
            if (letter >= 'a' && letter <= 'z')
            {
                lineString[i] = letter + UP;
                letter = getchar();
            }
            else
            {
                lineString[i] = letter;
                letter = getchar();
            }
            i++;
        }

        i = 0;
        if (isStringInLine(inputArray, lineString) == 1)
        {
            i = 0;
            while (lineString[i] == inputArray[i])
            {
                i++;
            }
            if (isIn(letterArray, lineString[i]) == 0)
            {
                letterArray[*inDatabase] = lineString[i];
                int k = 0;
                while (lineString[i] != '\0')
                {
                    wordBufer[k] = lineString[i];
                    k++;
                    i++;
                }

                (*inDatabase)++;
            }
            else
            {
                (*rpt)++;
            }
        }
        i = 0;
    }

    if (*rpt == 0 && *inDatabase == 1)
    {
        return wordBufer;
    }

    return letterArray;
}

// function that returns first letter of every word in database
char *getFirstLetter()
{
    int letter;
    int i = 0;
    char buffer;
    static char letterArray[MAXARRAYSIZE] = {0};

    while ((letter = getchar()) != EOF)
    {
        if (letter == '\n' || i == 0)
        {
            if (i == 0)
            {
                letterArray[i] = letter;
                i++;
            }
            else
            {
                char pismenko = getchar();
                if (isIn(letterArray, pismenko) != 1)
                {
                    letterArray[i] = pismenko;
                    i++;
                }
            }
        }
    }

    for (int i = 0; letterArray[i] != '\0'; i++)
    {
        for (int j = 0; letterArray[j] != '\0'; j++)
        {
            if (letterArray[j] > letterArray[j + 1] && letterArray[j + 1] != '\0')
            {
                buffer = letterArray[j];
                letterArray[j] = letterArray[j + 1];
                letterArray[j + 1] = buffer;
            }
        }
    }
    return letterArray;
}

// function that returns wheter letter is already in array or not
int isIn(char array[], char letter)
{
    int isIn = 0;
    int i = 0;

    while (array[i] != '\0')
    {
        if (letter == array[i])
        {
            isIn = 1;
            return isIn;
        }
        else
        {
            isIn = 0;
        }
        i++;
    }
    return isIn;
}