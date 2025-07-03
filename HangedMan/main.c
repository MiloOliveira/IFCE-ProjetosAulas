#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "HangedMan.h"
#define MaxCharacter 15

char HangedManWord[MaxCharacter];
char PreviousGuesses[26] = {'\0'};
char Guess;

int WordSelectedSize, FlagA;
int HangedManCheck[MaxCharacter] = {0};
int HP = 6;

int main() {
     int Win;
    
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
        
        do {
            FlagA = 0;
          printf("Escolha uma letra \n");
          scanf(" %c", &Guess);
          if (Guess < 65 || Guess > 90) {
            printf("Chute inválido \n");
            FlagA = 1;
            continue;
          } 
          printf("\t %c \n", Guess);
          LetterAlreadyUsed();
        } while (FlagA != 0);

        
        //Contagem se houve acerto ou não
        RoundHitCheck = 0;
        for (int aa = 0; aa < WordSelectedSize; aa++) {
            if (Guess == HangedManWord[aa]) {
                HangedManCheck[aa] = 1;
                RoundHitCheck = 1;
                Win-=1;
            }
        } 

        if (RoundHitCheck == 0) {
            HP--;
            printf("Letra errada! Tentativas restantes: %d\n", HP);
        }    

    } while (HP > 0 && Win > 0);

    EndGame();

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



int LetterAlreadyUsed() {
     for (int i = 0; i < 26; i++) {
          if (PreviousGuesses[i] == Guess) {
               printf("Letra já chutada antes. Escolha outra \n");
               Guess = '\0';
               FlagA = 1;
               break;
          } else if (PreviousGuesses[i] == '\0') {
               PreviousGuesses[i] = Guess;
                break;
          } else {
               continue;
          }
    };
     return 0;
}

void EndGame() {
    if (HP == 0) {
        printf("Você perdeu! A palavra era: %s\n", HangedManWord);
    } else {
        printf("Você escapou de seu destino cruel. Parabéns, coma um bolinho como presente\n");
        printf("          . . .\n");
    printf(" \\0/      |_|_|\n");
    printf("  |    __|_____|__\n");
    printf(" / \\    |       |\n");
    }

}

void RegisterNewWord() {
    char Regist;
    char NewWord[MaxCharacter];
    printf("Quer registrar uma nova palavra? (S/N)\n");
    scanf(" %c", &Regist);

    switch (Regist) {
    case 'S':
    case 's':
            printf("Escreva a palavra nova. Até no máximo %d caracteres.\n", MaxCharacter);
            fgets(NewWord, sizeof(NewWord), stdin);

             
            break;
    case 'N':
    case 'n':
            break;
    default:
        break;
    }

   
}
/*
void CheckNewWord() {
    int MaxWords;
    FILE* f;
            f = fopen("d:\\Semestre 1\\HangMan\\HangedMan\\Words.txt","r");
            if(f == NULL) {
                printf("Banco de dados de palavras não disponível\n");
                exit(1);
            }
            fseek(f, 0, SEEK_SET);
            fscanf(f, "%d", &MaxWords);
            for (int i = 1; i < MaxWords; i++) {
                fscanf(f, "%s", HangedManWord);
            }
}
*/