#include <stdio.h>

//void scanFile(char letter, char array[1][1]);

void getFirstLetter();
int isIn(int arraySize, char array[], char letter);

int main(int argc, char *argv[]) {
    int letter, i;
    char letterArray[1000] = {0};


   // printf("%d", argc);
    if (argc == 1)
    {
        getFirstLetter();
                
    }else{
       for (int i = 0; i < 5; i++)
       {
        printf("%c", argv[1][i]);
       }
    }


    return 0;
}

void getFirstLetter(){
    int letter;
    int i = 0;
    //int isIn = 0;
    char letterArray[1000] = {0};
    while ((letter = getchar()) != EOF)
    {
        if (letter == '\n' || i == 0)
        {
            if (i == 0)
            {
                letterArray[i] = letter;
                printf("%c\n", letterArray[i]);
                i++;
            }else{
                char pismenko = getchar();
                if (isIn(i, letterArray, pismenko) != 1)
                {
                    letterArray[i] = pismenko;
                    printf("%c\n", letterArray[i]);
                    i++;   
                }
            }
        }
    }
}

int isIn(int arraySize, char array[], char letter){
    int isIn = 0;
    for (int i = 0; i < arraySize; i++)
    {
        if (letter == array[i])
        {
            isIn = 1;
            return isIn;
        }
        else{
            isIn = 0;
        }
    }
    return isIn;
}





