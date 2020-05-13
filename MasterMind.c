#include <stdio.h>
#include <stdlib.h>
#include "PantallaPrincipal.h"
#include "MenuP.h"
#include "screenC.h"
#include "difFacil.h"
#include "instr.h"
#include "difNormal.h"
#include "difDificil.h"
#include "ScoresGame.h"



 void limpiarBuffer(){
   char c;
  while((c = getchar()) != '\n' && c != EOF);
}

char c;


int  main(void){

  system("resize -s 32 72");
  printf("\033[32m\n" );
  system("clear");
  PantallaP();
  getchar();
  system("clear");
  pantallaC();
  system("spd-say WELCOME");


  menu:
  system("clear");
  menu();
  int menu;

  scanf("%d", &menu);
  limpiarBuffer();

  switch (menu) {
    case 1:
    system("clear");


    menu2:

    menu2();
    int men;
    re:

    scanf("%d", &men );
    limpiarBuffer();
    switch (men) {
      case 1:
      system("clear");
      JO:
      menu3();
      int mn;
      rr:

      scanf("%d", &mn );
    limpiarBuffer();
      switch (mn) {
        case 1:
        system("clear");
        pantallaCa();
        system("clear");
        facil(t1, t2);

        break;

        case 2:
        system("clear");
        pantallaC();
        system("clear");
        normal(tN, tN2);

        break;

        case 3:
        system("clear");
        pantallaC();
        system("clear");
        dificil(dF, dF2);
        break;

        case 4:
        system("clear");
        goto menu2;
        limpiarBuffer();

        break;




        default:
        goto rr;
        break;


      }

      case 2:
      goto menu;
      break;

      default:
      goto re;
      break;
    }


    case 2:
    c = getchar();
    system("clear");
    instru();
    getchar();
    goto menu;
    break;

    case 3:
    c = getchar();
    system("clear");
    Scores();
    getchar();
    goto menu;
    system("clear");
    break;

    case 4:
    system(" spd-say GOODBYE");
    system("clear");
    exit(0);
    break;

    default:
    system("clear");
    goto menu;
    break;
  }
}
