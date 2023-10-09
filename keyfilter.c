#include <stdio.h>

// void scanFile(char letter, char array[1][1]);

char *getFirstLetter();
int isIn(int arraySize, char array[], char letter);
char *getAllowedKey(char inputArray[1000]);
int isStrinInDatabase(char inputString[1000], char lineString[]);

int main(int argc, char *argv[])
{
    int letter, i, j;
    char array[1000];
    char *firstLetters = getFirstLetter();
    char *nextLetter;
    i = 0;
    if (argc > 1)
    {
        while (argv[1][i] != '\0')
        {
            array[i] = argv[1][i];
            i++;
        }
    }

    i = 0;
    nextLetter = getAllowedKey(array);
    printf("%c", nextLetter[0]);
    i = 0;
    j = 0;
    if (argc == 1)
    {
        while (firstLetters[i] != '\0')
        {
            printf("%c\n", firstLetters[i]);
            i++;
        }
    }
    else
    {
        i = 0;
        printf("Enable: ");
        while (nextLetter[i] != '\0')
        {
            printf("%c ", nextLetter[i]);
            i++;
        }
    }
    return 0;
}
char *getFirstLetter()
{
    int letter;
    int i = 0;
    // int isIn = 0;
    static char letterArray[1000] = {0};
    while ((letter = getchar()) != EOF)
    {
        if (letter == '\n' || i == 0)
        {
            if (i == 0)
            {
                letterArray[i] = letter;
                // printf("%c\n", letterArray[i]);
                i++;
            }
            else
            {
                char pismenko = getchar();
                if (isIn(i, letterArray, pismenko) != 1)
                {
                    letterArray[i] = pismenko;
                    // printf("%c\n", letterArray[i]);
                    i++;
                }
            }
        }
    }
    return letterArray;
}

int isIn(int arraySize, char array[], char letter)
{
    int isIn = 0;
    for (int i = 0; i < arraySize; i++)
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
    }
    return isIn;
}

char *getAllowedKey(char inputArray[1000])
{
    int i = 0;
    int j = 0;
    char letter;
    char lineString[100];
    static char letterArray[1000];

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
            lineString[i] = letter;
            letter = getchar();
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
            letterArray[j] = lineString[i];
            j++;
        }
        i = 0;
    }
    return letterArray;
}

int isStrinInDatabase(char inputString[1000], char lineString[])
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

// tu funkciu na prve pismenka vyuzit
// porovnanavie riadkov ako stringov