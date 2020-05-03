#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tableros.h"
#include "cabeceraJ.h"
#include "MenuP.h"
#include <string.h>
#include<ctype.h>


char c;
int colorRand[5];
char color[5];
int rColor;
int checkarray(int *array, int len, int rColor) {
  int i;
  for (i = 0; i < len; i++) {
    if (array[i] == rColor)
    return 0;
  }
  return 1;
}



void facil(char t1[12][5], char t2[12][5]){
  char c;
  char comando[20];

  JO:
  for (int i = 0; i < 5;i++){
    for (int j = 0; j < 12; j++){
      if(i == 0){
        t1[j][0] = '1';
        t2[j][0] = '1';
      }
      if(i == 1){
        t1[j][1] = '2';
        t2[j][1] = '2';
      }
      if(i == 2){
        t1[j][2] = '3';
        t2[j][2] = '3';
      }
      if(i == 3){
        t1[j][3] = '4';
        t2[j][3] = '4';
      }
      if(i == 4){
        t1[j][4] = '5';
        t2[j][4] = '5';
      }
    }

  }
  tablero(t1, t2);
  system("clear");


  int colorRand[5], i = 0, rColor;
  char color[5];
  srand(time(0));

  while (i < 5) {
    rColor = rand() % 8 + 1;
    if (checkarray(colorRand, i, rColor)) {
      colorRand[i++] = rColor;

    }


  }
  for (int i = 0; i <= 4; i++){
    if (colorRand[i] == 1){
      colorRand[i] = 65;
      color[i] = colorRand[i];
    }else if (colorRand[i] == 2){
      colorRand[i] = 82;
      color[i] = colorRand[i];

    }else if (colorRand[i] == 3){
      colorRand[i] = 86;
      color[i] = colorRand[i];

    }else if (colorRand[i] == 4){
      colorRand[i] = 71;
      color[i] = colorRand[i];

    }else if (colorRand[i] == 5){
      colorRand[i] = 77;
      color[i] = colorRand[i];

    }else if (colorRand[i] == 6){
      colorRand[i] = 78;
      color[i] = colorRand[i];

    }else if (colorRand[i] == 7){
      colorRand[i] = 66;
      color[i] = colorRand[i];

    }else if (colorRand[i] == 8){
      colorRand[i] = 67;
      color[i] = colorRand[i];

    }

  }



  int nF = 0;
  int intentos = 0;
  int intentosJ = 0;
  int correctas;
  char jColor;
  int jTablero;
  fflush(stdin);
  regreso:
  system("clear");
  tablero(t1, t2);
  correctas = 0;

  scanf("%c %d", &jColor, &jTablero);

  if(jColor == 'R' || jColor == 'G' || jColor == 'A' || jColor == 'N' || jColor == 'V' || jColor == 'B' || jColor == 'M' || jColor == 'C' || jColor == '/' || jColor == '$'
|| jColor == 'a' || jColor == 'r' || jColor == 'g' || jColor == 'n' || jColor == 'v' || jColor == 'c' || jColor == 'm' || jColor == 'b'){
jColor = toupper(jColor);
    switch (jTablero) {
      case 1:
      for (int i= 0; i <= 4; i++){
        if (jColor == t1[nF][i]){
          goto regreso;
          break;
        }
      }
      t1[nF][0] = jColor;
      system("clear");
      tablero(t1, t2);
      goto regreso;
      break;



      case 2:
      for (int i= 0; i <= 4; i++){
        if (jColor == t1[nF][i]){
          goto regreso;
          break;
        }
      }
      t1[nF][1] = jColor;
      system("clear");
      tablero(t1, t2);
      goto regreso;
      break;

      case 3:
      for (int i= 0; i <= 4; i++){
        if (jColor == t1[nF][i]){
          goto regreso;
          break;
        }
      }
      t1[nF][2] = jColor;
      system("clear");
      tablero(t1, t2);
      goto regreso;
      break;

      case 4:
      for (int i= 0; i <= 4; i++){
        if (jColor == t1[nF][i]){
          goto regreso;
          break;
        }
      }
      t1[nF][3] = jColor;
      system("clear");
      tablero(t1, t2);
      goto regreso;
      break;

      case 5:
      for (int i= 0; i <= 4; i++){
        if (jColor == t1[nF][i]){
          goto regreso;
          break;
        }
      }
      t1[nF][4] = jColor;
      system("clear");
      tablero(t1, t2);



      if (t1[nF][3] == '/' && t1[nF][4] == '$'){
        comando1:

        printf("//Introduce el comando!\n");
        scanf("%s",comando );
        system("clear");
        tablero(t1,t2);
        printf("Comando: %s ", comando);
        if (strcmp(comando, "trampa") == 0){  nF++; intentos++;
          system(" spd-say CHEATER");
          c = getchar();
          printf("\n La combinación es: %c %c %c %c %c\n",color[0], color[1], color[2], color[3], color[4]);
          getchar();
          goto regreso;
          break;

        }else if (strcmp(comando,"salir") == 0){
          system(" spd-say GOODBYE");
          system("rhythmbox-client --stop");
          system("clear");
          exit(0);
          break;
        }else if(strcmp(comando, "salirC") == 0){
          c = getchar();
          getchar();
          goto regreso;
        }else {
          printf("\nERROR Comando %s no existe\n", comando );
          goto comando1;
        }
        break;
      }else {
        goto seguir;
        break;
      }

      seguir:

      for (int i = 1; i <= 4; i++){
        if(t1[nF][0] == color[0]){
          t2[nF][0] = 'X'; correctas ++;
        }else if (t1[nF][0] == color[i]){
          t2[nF][0] = 'O';
        }
      }

      for (int i = 2; i <= 4; i++){
        if(t1[nF][1] == color[1]){
          t2[nF][1] = 'X'; correctas ++;

        }else if (t1[nF][1] == color[i]){
          t2[nF][1] = 'O';
        }
      }

      for (int i = 3; i <= 4; i++){
        if(t1[nF][2] == color[2]){
          t2[nF][2] = 'X'; correctas ++;
        }else if (t1[nF][2] == color[i]){
          t2[nF][2] = 'O';
        }
      }

      for (int i = 4; i <= 4; i++){
        if(t1[nF][3] == color[3]){
          t2[nF][3] = 'X'; correctas ++;
        }else if (t1[nF][3] == color[i]){
          t2[nF][3] = 'O';
        }
      }

      for (int i = 0; i <= 3; i++){
        if(t1[nF][4] == color[4]){
          t2[nF][4] = 'X'; correctas ++;
        }else if (t1[nF][4] == color[i]){
          t2[nF][4] = 'O';
        }
      }
      system("clear");
      printf("%d\n", correctas );
      tablero(t1, t2);
      nF++; intentos ++; intentosJ ++;
      if (intentos < 12){
        if (correctas == 14){
          system("clear");
          char username[20];
          cM();
          printf("\n\n\t\t\t FELICIDADES, GANASTE!!!! \n");
          printf("\t\t\tLOGRASTE EN %d INTENTOS!!!! \n\n", intentosJ);
          system(" spd-say CONGRATULATIONS");
          char username1[20];
          do{
            printf("//Introduce un username de 6 caracteres para der guardado en los Marcadores!\n");
            printf("Username :   ");
            scanf("%s",username1 );

          }while( strlen(username1) < 6 || strlen(username1) > 6 );
          FILE *UsernameS = fopen("Scores.text", "a");
          fprintf(UsernameS, "\n\t\t%s\t\t%d\n",username1,correctas);
          fclose(UsernameS);
          system("clear");

          menu4();
          int mf;
          mF:
          scanf("%d", &mf);
          switch (mf) {
            case 1:
            system("clear");
            goto JO;
            break;

            case 2:
            system(" spd-say GOODBYE");
            system("rhythmbox-client --stop");
            system("clear");
            exit(0);
            break;

            default:
            goto mF;
            break;

          }

          break;
        }
      }else if (intentos == 12){
        if(correctas != 14){
          system("clear");
          cM();
          system("rhythmbox-client --stop");
          printf("\n\n\n\t\t\t\tPERDISTE!!!! =(\n\n" );
          system(" spd-say HA' 'HA' 'HA' 'HA' 'HA' 'HA' 'HA' 'HA' 'LOSER");
          printf("\n La combinación correcta era %c %c %c %c %c\n\n",color[0], color[1], color[2], color[3], color[4]);

          char name[20];
          do{
            printf("//Introduce un username de 6 caracteres para ser guardado en los Marcadores!\n");
            printf("Username :   ");
            scanf("%s",name );

          }while( strlen(name) < 6 || strlen(name) > 6 );
          FILE *ss = fopen("Scores.text", "a");
          fprintf(ss, "\n\t\t|%s|\t\t\t|%d|\n",name, correctas);
          fclose(ss);
          system("clear");

          menu4();
          int mf;
          mc:
          scanf("%d", &mf);
          switch (mf) {
            case 1:
            system("clear");
            goto JO;
            break;

            case 2:
            system(" spd-say GOODBYE");
            system("rhythmbox-client --stop");
            system("clear");
            exit(0);
            break;

            default:
            goto mc;
            break;

          }


        }


      }else {
        goto regreso;
        break;
      }


      default:
      goto regreso;
      break;
    }
  }else{
    system("clear");
    goto regreso;
  }
}
