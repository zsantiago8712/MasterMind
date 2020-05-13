#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tableros.h"
#include "cabeceraJ.h"
#include "MenuP.h"
#include <string.h>
#include <ctype.h>
#include "trophy.h"



void limpiarBufer(){
  char c;
 while((c = getchar()) != '\n' && c != EOF);
}



char c;
int colorRand[5];
char color[5];
int rColor;
int checkarray1(int *array, int len, int rColor) {
  int i;
  for (i = 0; i < len; i++) {
    if (array[i] == rColor)
    return 0;
  }
  return 1;
}



void normal(char tN[12][5], char tN2[12][5]){
  char c;

  char comando[20];

  JO:
  for (int i = 0; i < 5;i++){
    for (int j = 0; j < 12; j++){
      if(i == 0){
        tN[j][0] = '1';
        tN2[j][0] = '1';
      }
      if(i == 1){
        tN[j][1] = '2';
        tN2[j][1] = '2';
      }
      if(i == 2){
        tN[j][2] = '3';
        tN2[j][2] = '3';
      }
      if(i == 3){
        tN[j][3] = '4';
        tN2[j][3] = '4';
      }
      if(i == 4){
        tN[j][4] = '5';
        tN2[j][4] = '5';
      }
    }

  }
  tableroNormal(tN, tN2);
  system("clear");


  int colorRand[5], i = 0, rColor;
  char color[5];
  srand(time(0));

  while (i < 5) {
    rColor = rand() % 8 + 1;
    if (checkarray1(colorRand, i, rColor)) {
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
  int jtableroNormal;
  fflush(stdin);
  regreso:
  system("clear");
  tableroNormal(tN, tN2);
  correctas = 0;

  scanf("%c %d", &jColor, &jtableroNormal);
  if(jColor == 'R' || jColor == 'G' || jColor == 'A' || jColor == 'N' || jColor == 'V' || jColor == 'B' || jColor == 'M' || jColor == 'C' || jColor == '/' || jColor == '$'
|| jColor == 'a' || jColor == 'r' || jColor == 'g' || jColor == 'n' || jColor == 'v' || jColor == 'c' || jColor == 'm' || jColor == 'b'){
    jColor = toupper(jColor);
    switch (jtableroNormal) {
      case 1:
      for (int i= 0; i <= 4; i++){
        if (jColor == tN[nF][i]){
          goto regreso;
          break;
        }
      }
      tN[nF][0] = jColor;
      system("clear");
      tableroNormal(tN, tN2);
      goto regreso;
      break;



      case 2:
      for (int i= 0; i <= 4; i++){
        if (jColor == tN[nF][i]){
          goto regreso;
          break;
        }
      }
      tN[nF][1] = jColor;
      system("clear");
      tableroNormal(tN, tN2);
      goto regreso;
      break;

      case 3:
      for (int i= 0; i <= 4; i++){
        if (jColor == tN[nF][i]){
          goto regreso;
          break;
        }
      }
      tN[nF][2] = jColor;
      system("clear");
      tableroNormal(tN, tN2);
      goto regreso;
      break;

      case 4:
      for (int i= 0; i <= 4; i++){
        if (jColor == tN[nF][i]){
          goto regreso;
          break;
        }
      }
      tN[nF][3] = jColor;
      system("clear");
      tableroNormal(tN, tN2);
      goto regreso;
      break;

      case 5:
      for (int i= 0; i <= 4; i++){
        if (jColor == tN[nF][i]){
          goto regreso;
          break;
        }
      }
      tN[nF][4] = jColor;
      system("clear");
      tableroNormal(tN, tN2);



      if (tN[nF][3] == '/' && tN[nF][4] == '$'){
        comando1:

        printf("//Introduce el comando!\n");
        scanf("%s",comando );
        system("clear");
        tableroNormal(tN,tN2);
        printf("Comando: %s ", comando);
        if (strcmp(comando, "trampa") == 0){  nF++; intentos++;
          c = getchar();
          printf("\n La combinación es: %c %c %c %c %c",color[0], color[1], color[2], color[3], color[4]);
          printf("\n\n\t   PRESIONE CUALQUIER TECLA PARA SEGUIR JUGANDO\n" );
          getchar();
          goto regreso;
          break;

        }else if (strcmp(comando,"salir") == 0){
          system("clear");
          exit(0);
          break;
        }else if(strcmp(comando, "salirC") == 0){
          c = getchar();
          printf("\n\n\t   PRESIONE CUALQUIER TECLA PARA SEGUIR JUGANDO\n" );
          getchar();
          goto regreso;
        }else if (strcmp(comando, "toño") == 0){
          c = getchar();
          system("clear");
          easterEgg();
          getchar();
          system("resize -s 32 72");
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
        if(tN[nF][0] == color[0]){
          tN2[nF][0] = 'X'; correctas ++;
        }else if (tN[nF][0] == color[i]){
          tN2[nF][0] = 'O';
        }
      }

      for (int i = 2; i <= 4; i++){
        if(tN[nF][1] == color[1]){
          tN2[nF][1] = 'X'; correctas ++;

        }else if (tN[nF][1] == color[i]){
          tN2[nF][1] = 'O';
        }
      }

      for (int i = 3; i <= 4; i++){
        if(tN[nF][2] == color[2]){
          tN2[nF][2] = 'X'; correctas ++;
        }else if (tN[nF][2] == color[i]){
          tN2[nF][2] = 'O';
        }
      }

      for (int i = 4; i <= 4; i++){
        if(tN[nF][3] == color[3]){
          tN2[nF][3] = 'X'; correctas ++;
        }else if (tN[nF][3] == color[i]){
          tN2[nF][3] = 'O';
        }
      }

      for (int i = 0; i <= 3; i++){
        if(tN[nF][4] == color[4]){
          tN2[nF][4] = 'X'; correctas ++;
        }else if (tN[nF][4] == color[i]){
          tN2[nF][4] = 'O';
        }
      }
      system("clear");
      printf("%d\n", correctas );
      tableroNormal(tN, tN2);
      nF++; intentos ++; intentosJ ++;
      if (intentos < 8){
        if (correctas == 14){
          system("clear");
          char username[20];
          cM();
          winner();
          printf("\n\n\t\t\t FELICIDADES, GANASTE!!!1 \n");
          printf("\t\t\tLOGRASTE EN %d INTENTOS!!!! \n\n", intentosJ);
          char username1[20];
          do{
            printf("//Introduce un username de 7 caracteres para der guardado en los Marcadores!\n");
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
          limpiarBufer();
          switch (mf) {
            case 1:
            system("clear");
            goto JO;
            break;

            case 2:
            system("clear");
            exit(0);
            break;

            default:
            goto mF;
            break;

          }

          break;
        }
      }else if (intentos == 8){
        if(correctas != 14){
          system("clear");
          cM();
          printf("\n\n\n\t\t\t\tPERDISTE!!!! =(\n\n" );
          printf("\n La combinación correcta era %c %c %c %c %c\n\n",color[0], color[1], color[2], color[3], color[4]);

          char name[20];
          do{
            printf("//Introduce un username de 7 caracteres para ser guardado en los Marcadores!\n");
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
          limpiarBufer();
          switch (mf) {
            case 1:
            system("clear");
            goto JO;
            break;

            case 2:
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
