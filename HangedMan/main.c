#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "Words.txt"
#define WordSize 12


char WordSelected[WordSize];
int WordLength;



void WordGet() {
     int WordsAmount, RandomSelectedWord;
     
     FILE* f;
     f = fopen("Words.txt", "r+");
     if(f == 0) {
          printf("Banco de dados de palavras não disponível \n");
     }
     fscanf(f,"%d", &WordsAmount);
     RandomSelectedWord = rand() % WordsAmount;
     for (int i = 0; i < RandomSelectedWord; i++) {
          fscanf(f, "%s", &WordSelected);
     }
     fclose(f);

     WordLength = strlen(WordSelected);
}

int main() {
     srand(time(NULL));
     int LetterDiscovered[WordSize] = {0};
     char LetterGuess;
     int Won, Tries;

     
     do {
          printf("Escreva uma letra para chutar");
          scanf(" %c", &LetterGuess);
          for (int i = 0; i < WordLength; i++) {
               if (WordSelected[i] == LetterGuess) {
                    LetterDiscovered[i] = 1;
               }
          }

          for (int i = 0; i < WordLength; i++){
               if (LetterDiscovered[i] == 1) {
                    printf("%c ", WordSelected[i]);
               } else {
                    printf("_ ");
               }
          }

     } while (Won != 1 || Tries != 0);


     return 0;
}
