#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "HangedMan.h"
#define MaxCharacter 12

char HangedManWord[MaxCharacter];
char Guess;

int WordSelectedSize;
int HangedManCheck[MaxCharacter] = {0};


int main() {
     int Win, Hanged;
     int HP = 6; 
     int RoundHitCheck;
    
    //Escolhe uma palavra
    srand(time(0));
    WordChoser();
    WordSelectedSize = strlen(HangedManWord);
    
    Win = WordSelectedSize;
    do {
        //Imprime a palavra na Tela, com letras já descobertas e espaços em branco
        for (int bb = 0; bb < WordSelectedSize; bb++) {
            if (HangedManCheck[bb] == 0) {
                printf ("_ ");
            } else {
                printf("%c ",HangedManWord[bb]);
            }
        } 
        printf("\n");
        
       // do {
          printf("Escolha uma letra \n");
          scanf(" %c", &Guess);
          Guess = toupper(Guess);
      //  LetterAlreadyUsed();
      //  } while (LetterAlreadyUsed());

        
        //Contagem se houve acerto ou não
        RoundHitCheck = 0;
        for (int aa = 0; aa < WordSelectedSize; aa++) {
            if (Guess == HangedManWord[aa]) {
                HangedManCheck[aa] = 1;
                RoundHitCheck = 1;
                Win-=1;
            }
        } 

        printf("\n  %d \n", Win);
        if (RoundHitCheck == 0) {
            HP--;
            printf("Letra errada! Tentativas restantes: %d\n", HP);
        }    

    } while (HP > 0 && Win > 0);

    if (HP == 0) {
        printf("Você perdeu! A palavra era: %s\n", HangedManWord);
    }

    return 0;
}


void WordChoser() {
     int MaxWords;

     FILE* f;
     f = fopen("d:\\Semestre 1\\HangMan\\HangedMan\\Words.txt","r");
     if(f == NULL) {
          printf("Banco de dados de palavras não disponível\n");
          exit(1);
     }
     fscanf(f, "%d", &MaxWords);

     int  WordSelected = rand() % MaxWords;
     for (int i = 0; i < WordSelected; i++) {
          fscanf(f, "%s", HangedManWord);
     }

     fclose(f);
}

/*

char PreviousGuesses[26] = {0};
int LetterAlreadyUsed() {
     for (int i = 0; i < 26; i++) {
          if (PreviousGuesses[i] == '\0') {
               PreviousGuesses[i] = Guess;
               return 0;
          } else if (PreviousGuesses[i] == Guess) {
               printf("Letra já chutada antes. Escolha outra \n");
               Guess = '\0';
               return 1;
          } else {
               continue;
          }
     };
     return 0;
}

*/