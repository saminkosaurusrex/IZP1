// treba osetrit: male velke pismena, a ked uz nieje zidna ina moznost nech to vypise mesto
#define maxArraySize 100
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *getAllowedKey(char inputArray[maxArraySize]);
int isIn(char array[], char letter);
void getFirstLetter();
int isStrinInDatabase(char inputString[maxArraySize], char lineString[]);
int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    char array[maxArraySize];
    char *allowed;
    int up = 'A' - 'a';
    int down = 'a' - 'A';
    char buffer;

    if (argc > 1)
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                array[i] = argv[1][i] + down;
            }
            else
            {
                array[i] = argv[1][i];
            }

            i++;
        }
    }

    // printf("%c", array[0]);

    switch (argc)
    {
    case 1:
        getFirstLetter();
        break;

    case 2:
        while (argv[1][j] != '\0')
        {
            if (!isalpha(argv[1][j]))
            {
                printf("Wrong input!");
                return 1;
            }
            j++;
        }
        i = 0;
        allowed = getAllowedKey(array);

        if (allowed[0] == '\0')
        {
            printf("Not found");
            return 1;
        }
        else
        {
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
                printf("%c", allowed[i] + up);
                i++;
            }
        }

        break;
    default:
        break;
    }
    return 0;
}

int isStrinInDatabase(char inputString[maxArraySize], char lineString[])
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

char *getAllowedKey(char inputArray[maxArraySize])
{
    int i = 0;
    int j = 0;
    // int p = 0;
    char letter;
    char lineString[maxArraySize];
    static char letterArray[maxArraySize] = {0};

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
            if (letter >= 'A' && letter <= 'Z')
            {
                lineString[i] = letter + 'a' - 'A';
                letter = getchar();
            }
            else
            {
                lineString[i] = letter;
                letter = getchar();
            }

            // lineString[i] = letter;

            i++;
        }
        i = 0;
        if (isStrinInDatabase(inputArray, lineString) == 1)
        {
            i = 0;
            while (lineString[i] == inputArray[i])
            {
                i++;
            }
            if (isIn(letterArray, lineString[i]) == 0)
            {
                letterArray[j] = lineString[i];
                j++;
            }
        }

        i = 0;
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