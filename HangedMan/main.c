#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "HangedMan.h"
#define MaxCharacter 15
#define MaxNameLength 15
#define MaxScore 100

char HangedManWord[MaxCharacter];
char NewWord[MaxCharacter];

char PreviousGuesses[26] = {'\0'};
char Guess;

int WordSelectedSize;
int FlagA, FlagB; 
int HangedManCheck[MaxCharacter] = {0};
int HP = 6, TowerSize, Score;
int MaxWords;

int TriesPerDif[3] = {10,8,6};
int DifSelected;

int main() {
     int Win;
    
     int RoundHitCheck;
    
    //Escolhe uma palavra
    srand(time(NULL));
    WordChoser();
    WordSelectedSize = strlen(HangedManWord);
    Win = WordSelectedSize;
    Dificulty();
    
    do {
        
        PrintTower();

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
    
    }
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
    PointCount();
    RegisterNewWord();
    CravingRank();

   
}

void Dificulty() {
    printf("Qual a Dificuldade? \n \t1.Fácil \n \t2.Médio \n \t3.Difícil \n");
    scanf("%d", &DifSelected);

    switch (DifSelected)
    {
    case 1:
    case 2:
    case 3:
        HP = TriesPerDif[DifSelected-1];
        TowerSize = HP;
        break;
    default:
        printf("Opção inválida, escreva denovo\n");
        break;
    }
}

void PrintTower() {
    for (int i = 1; i <= TowerSize; i++) {
        if (i == (HP)) {
            printf("___________\n");
            printf("|    0    |\n");
            printf("|  / | \\  |\n");
            printf("|   / \\   |\n");
        } else {
            printf("___________\n");
            printf("|         |\n");
            printf("|  %2d     |\n",i);
            printf("|         |\n");
        }
    }
}

void RegisterNewWord() {
    char Regist;
    char NewWord[MaxCharacter];
    printf("Quer registrar uma nova palavra? (S/N)\n");
    scanf(" %c", &Regist);
    while (getchar() != '\n'); // Clear input buffer

    switch (Regist) {
    case 'S':
        do {
            FlagB = 0;
            printf("Escreva a palavra nova. Até no máximo %d caracteres.\n", MaxCharacter);
            fgets(NewWord, sizeof(NewWord), stdin);
            // Remove trailing newline from fgets
            size_t len = strlen(NewWord);
            if (len > 0 && NewWord[len-1] == '\n') {
                NewWord[len-1] = '\0';
            }
            CheckNewWord();
        }while (FlagB == 1);

            FILE* f;
            f = fopen("d:\\Semestre 1\\HangMan\\HangedMan\\Words.txt","r+");
            if(f == NULL) {
                printf("Banco de dados de palavras não disponível\n");
                exit(1);
            }
            fseek(f, 0, SEEK_SET);
            MaxWords+=1;
            fprintf(f, "%d", MaxWords);
            fseek(f, 0, SEEK_END);
            fprintf(f, "\n%s", NewWord);
            break;
    case 'N':
            printf("Certo, até mais então.\n");
            break;
    default:
        break;
    }

   
}

void CheckNewWord() {
    char WordFromFile[MaxCharacter];
    FILE* f = fopen("d:\\Semestre 1\\HangMan\\HangedMan\\Words.txt", "r");
    if (f == NULL) {
        printf("Banco de dados de palavras não disponível\n");
        exit(1);
    }
    fscanf(f, "%d", &MaxWords);
    // Pula a primeira linha (o número de palavras)
    fseek(f, 0, SEEK_SET);
    int ch;
    while ((ch = fgetc(f)) != '\n' && ch != EOF);
    for (int i = 0; i < MaxWords; i++) {
        fscanf(f, "%s", WordFromFile);
        if (strcmp(NewWord, WordFromFile) == 0) {
            printf("Essa palavra já existe em nosso banco de dados\n");
            FlagB = 1;
            fclose(f);
            return;
        }
    }
    FlagB = 0;
    fclose(f);
}

void PointCount() {
    float DifValue[3] = {6, 8, 8};
    float DifWeight[3] = {1,1.5,2};
    Score += (1000 - (DifValue[DifSelected-1] * DifWeight[DifSelected-1] * (TriesPerDif[DifSelected-1] - HP) * 10));
    printf("Seu score: %d\n", Score);
}

void CravingRank() {
    int BestPoints;
    char Name[MaxNameLength];
     FILE* f;
     f = fopen("d:\\Semestre 1\\HangMan\\HangedMan\\Ranking.txt","r+");
     if(f == NULL) {
          printf("Ranking não disponível\n");
          exit(2);
     }
     fscanf(f, "%d", &BestPoints);

     if (Score > BestPoints) {
        printf("Novo High-score! Insira seu nome, máximo de %d caracteres\n", MaxNameLength);
        fgets(Name, sizeof(Name), stdin);
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", Score);
        fprintf(f, "\n%s",Name);
     }
}