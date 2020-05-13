#ifndef _MENUP_DOT_H
#define _MENUP_DOT_H
#include <stdio.h>
#include <stdlib.h>
#include "cabeceraJ.h"
#include "screenC.h"











void menu();






void menu4(){
  cM();
  printf("\n                        ~~~~~~~~~ Menu ~~~~~~~~\n\n" );
  printf("                             1.- VOLVER A JUGAR\n" );
  printf("                             2.- SALIR DEL JUEGO\n" );


}




void menu3(){
  cM();

  printf("\n                      ~~~~~~~~Menu Principal~~~~~~~\n" );


  printf("\n                              JUGAR\n" );
  printf("                                JUGADOR VS. CPU\n" );
  printf("                                   DIFICULTAD\n" );
  printf("                                   1.- ~~FÁCIL~~~\n");
  printf("                                   2.- ~~NORMAL~~\n");
  printf("                                   3.- ~~DÍFICL~~\n");
  printf("                                   4.- ~~REGRESAR~~\n" );
  printf("                             COMO SE JUEGA\n" );
  printf("                             MARCADORES\n" );
  printf("                             SALIR\n" );

}


void menu2(){

  cM();

  printf("\n                        ~~~~~~~~Menu Principal~~~~~~~\n\n" );
  printf("                                JUGAR\n" );
  printf("                                   1.- JUGADOR VS. CPU\n" );
  printf("                                   2.- ~~REGRESAR~~\n" );
  printf("                                COMO SE JUEGA\n" );
  printf("                                MARCADORES\n" );
  printf("                                SALIR\n"  );
}





void menu(){
  cM();
  printf("\n                      ~~~~~~~~Menu Principal~~~~~~~\n\n" );
  printf("                               1.- JUGAR\n" );
  printf("                               2.- COMO SE JUEGA\n" );
  printf("                               3.- MARCADORES\n" );
  printf("                               4.- SALIR\n"  );
}
#endif //_MENUP_DOT_H
