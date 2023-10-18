#define maxArraySize 101
#define up 'A' - 'a'
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *getAllowedKey(char inputArray[maxArraySize], int *rpt, int *inDatabase);
int isIn(char array[], char letter);
void getFirstLetter();
int isStringInLine(char inputString[maxArraySize], char lineString[]);
int isStringInDatabase(char inputString[maxArraySize]);
int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    char array[maxArraySize];
    char *allowed;
    char buffer;
    int rpt = 0;
    int inDatabase = 0;

    if (argc > 1)
    {
        while (argv[1][i] != '\0')
        {

            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                array[i] = argv[1][i] + up;
            }
            else
            {
                array[i] = argv[1][i];
            }

            i++;
        }
    }

    switch (argc)
    {
    case 1:
        getFirstLetter();
        break;

    case 2:
        while (argv[1][j] != '\0')
        {

            if (!isalpha(argv[1][j]) && argv[1][j] != ' ')
            {
                printf("Wrong input!");
                return 1;
            }
            j++;
        }
        i = 0;
        allowed = getAllowedKey(array, &rpt, &inDatabase);
        // printf("%c, %d, %d", allowed[0], rpt, inDatabase);
        if (allowed[0] == '\0' && (rpt == 0 && inDatabase == 0))
        {
            printf("Not found");
            return 1;
        }
        else
        {
            if (rpt == 0 && inDatabase == 1)
            {
                printf("Found: ");
                for (int i = 0; argv[1][i] != '\0'; i++)
                {
                    printf("%c", array[i]);
                }
                for (int i = 0; allowed[i] != '\0'; i++)
                {
                    printf("%c", allowed[i]);
                }

                return 0;
            }

            printf("Enable: ");
            for (int i = 0; allowed[i] != '\0'; i++)
            {
                for (int j = 0; allowed[j] != '\0'; j++)
                {
                    if (allowed[j] > allowed[j + 1] && allowed[j + 1] != '\0')
                    {
                        buffer = allowed[j];
                        allowed[j] = allowed[j + 1];
                        allowed[j + 1] = buffer;
                    }
                }
            }

            while (allowed[i] != '\0')
            {
                printf("%c", allowed[i]);
                i++;
            }
        }

        break;
    default:
        printf("Wrong input!");
        return 1;
        break;
    }
    return 0;
}

int isStringInLine(char inputString[maxArraySize], char lineString[])
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

char *getAllowedKey(char inputArray[maxArraySize], int *rpt, int *inDatabase)
{
    int i = 0;
    *inDatabase = 0;
    char letter;

    *rpt = 0;
    char lineString[maxArraySize];
    static char letterArray[maxArraySize] = {0};
    static char wordBufer[maxArraySize];

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
                lineString[i] = letter + up;
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

void getFirstLetter()
{
    int letter;
    int i = 0;
    static char letterArray[maxArraySize] = {0};
    while ((letter = getchar()) != EOF)
    {
        if (letter == '\n' || i == 0)
        {
            if (i == 0)
            {
                letterArray[i] = letter;
                printf("%c\n", letterArray[i]);
                i++;
            }
            else
            {
                char pismenko = getchar();
                if (isIn(letterArray, pismenko) != 1)
                {
                    letterArray[i] = pismenko;
                    printf("%c\n", letterArray[i]);
                    i++;
                }
            }
        }
    }
}

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
