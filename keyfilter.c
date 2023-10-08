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
                //printf("%d %c %d", isIn(i, letterArray, pismenko), pismenko, i);
                printf("isIn:%d\n", isIn(i, letterArray, pismenko));
                printf("pismenko: %c\n", pismenko);
                printf("i=%d\n", i);
                if (isIn(i, letterArray, pismenko) != 1)
                {
                    
                    //
                    
                    letterArray[i] = pismenko;
                    printf("%c\n", letterArray[i]);
                    i++;   
                }
                //scanf("%s", &letterArray[i]);
                //printf("%c\n", letterArray[i]);
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%c", letterArray[i]);
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





