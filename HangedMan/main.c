#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define MaxWords 5
#define MaxCharacter 12


int main() {
     int WordSelected, Win, RoundHitCheck;
     char Guess;
     char HangedManWord[MaxCharacter];
     int HangedManCheck[MaxCharacter];
     for (int aa = 0; aa < MaxCharacter; aa++) {
         HangedManCheck[aa] = 0;
     }
    int HP;
    int WordSelectedSize;

     char WordsBank[3][MaxWords][MaxCharacter] = {
         {
                "MARI",
                "OMORI",
                "AUBREY",
                "KEL",
                "HERO"
            },
            {
                "SWEETHEART",
                "HUMPREY",
                "HUSBAND",
                "UNBREAD",
                "CHICKEN"
            }, 
            {
                "PAPERCLIP",
                "BASEBALL",
                "ORANGEJOE",
                "LOLSWORD",
                "ORAGNEJACK"
            },
     };
     
    
    srand(time(0));
     
     WordSelected = rand() % MaxWords;
     strcpy(HangedManWord, WordsBank[2][WordSelected]);
     WordSelectedSize = strlen(HangedManWord);
     
     
     do {
        for (int bb = 0; bb < WordSelectedSize; bb++) {
             if (HangedManCheck[bb] == 0) {
                 printf ("_ ");
             } else {
                 printf("%c ",HangedManWord[bb]);
             }
         } 
         
        printf("Escolha uma letra \n");
        scanf(" %c", &Guess);
        Guess = toupper(Guess);
        
        RoundHitCheck = 0;
        for (int aa = 0; aa < WordSelectedSize; aa++) {
            if (Guess == HangedManWord[aa]) {
               HangedManCheck[aa] = 1;
               RoundHitCheck = 1;
           }
        } 
        
        if (RoundHitCheck == 0) {
            //HP--;
        }
          
     } while (HP == 0);

     return 0;
}
