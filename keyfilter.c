#include <stdio.h>
#define maxSizeOfArray 1000

void getFirstLetter();
int isIn(char array[], char letter);
int isStrinInDatabase(char inputString[maxSizeOfArray], char lineString[]);
char *getAllowedKey(char inputArray[maxSizeOfArray]);
int main(int argc, char *argv[])
{
    int i = 0;
    char array[maxSizeOfArray];
    char *allowed;

    if (argc > 1)
    {
        while (argv[1][i] != '\0')
        {
            array[i] = argv[1][i];
            i++;
        }
    }

    switch (argc)
    {
    case 1:
        // skus este zadefinovat getFir... tuna, ale nech vracia pole
        getFirstLetter();
        break;

    case 2:
        i = 0;
        allowed = getAllowedKey(array);
        printf("enable: ");
        while (allowed[i] != '\0')
        {
            printf("%c", allowed[i]);
            i++;
        }
        break;
    default:
        break;
    }
}

int isStrinInDatabase(char inputString[maxSizeOfArray], char lineString[])
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

char *getAllowedKey(char inputArray[maxSizeOfArray])
{
    int i = 0;
    int j = 0;
    char letter;
    char lineString[maxSizeOfArray];
    static char letterArray[maxSizeOfArray] = {0};

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
            if (isIn(letterArray, lineString[i]) == 0)
            {
                letterArray[j] = lineString[i];
            }

            j++;
        }
        i = 0;
    }
    return letterArray;
}

void getFirstLetter()
{
    int letter;
    int i = 0;
    static char letterArray[maxSizeOfArray] = {0};
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