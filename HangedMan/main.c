#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
     #define MaxWords 5
     char WordsBank[3][MaxWords][12] = {
          {
           "Mari",
          "Omori",
          "Aubrey",
          "Kel",
          "Hero"
          },
          {
               "Sweetheart",
               "Humprey",
               "Husband",
               "Unbread",
               "Chicken",
          }, 
          {
               "Paperclip",
               "Baseball",
               "OrangeJoe",
               "LOLsword",
               "OragneJack",
          },
     };

     /*          
               "Hero",
               "Basil",
               "Aubrey",
               "Mari",
               "Sunny"

               "Sweetheart",
               "Humprey",
               "Husband",
               "Unbread",
               "Chicken",
          },
          {
               "Paperclip",
               "Baseball",
               "OrangeJoe",
               "LOLsword",
               "OragneJack",
          },
     };
     */
    for (int ab = 0; ab < 3; ab++) {
     for (int aa = 0; aa < MaxWords; aa++) {
          printf("%s \n", WordsBank[ab][aa]);
     }
     printf("-------- \n");
    }
     
     return 0;
}
