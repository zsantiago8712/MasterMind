#ifndef _INSTR_DOT_H
#define _INSTR_DOT_H_

#include <stdio.h>
#include <stdlib.h>


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_LIGHTGRAY "\x1b[37m"
#define ANSI_COLOR_BLANCO "\x1b[39m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BLACK "\x1b[30m"


void instru(){


  printf("\n\t\t     ~~~~~~~~~~~~~~COMO SE JUEGA~~~~~~~~~~~~~~~~~~\n" );
  printf("\n\nMastermind es un juego de habilidad y lócgica que consiste en descubrir una  secuencia  de  colores  oculta.\n" );
  printf("En  Mastermind  compiten  el  jugador y la CPU,  la CPU  creará un  código oculto  con  5  \n" );
  printf(" iniciales de colores: (Amarillo(A), Rojo(R), Verde(V), Gris(G), Morado(M), Negro(N), Blanco(B) y Cafe(C)), pudiendo  hacer  las  combinaciones  con  los  8 colores disponibles, la Cpu no repetira colores ne la combinación.\n"  );
  printf("El  código no se presentara hasta el final,\n" );
  printf("¡OJO! LA COMPUTADORA TOMARÁ COMO QEU ACABSTE DE INTRODUCRI LA COMBINACÓN\n");
  printf("deberás acertar la combianción en  el  menor  número  posible  de jugadas.\n"  );
  printf("Para  descifrar  el  código secreto de  colores  el  jugador  deberá  ir  probando  combinaciones  aleatorias  de \n" );
  printf("iniciales de colores (da igual si escribes en mayuscula o en minuscula), y en cada combinación, la CPU debe darle pistas mediante las 'O' y 'X'.  \n");
  printf("Por cada letra acertada en inicial del color y posición, colocará una 'X', y  por  cada  color  acertado  pero \n" );
  printf("en  un  lugar  equivocado  colocará  una  'O'. ¡ATENCION! Si aparece una 'O' em la posicion 3 del tablero, la CPU solo checara las posiciones de adelante, en este caso seria la posicion 4 y 5.\n" );
  printf("Para poder introducir comandos se deberá poner un '/' en la posición 4 y un '$' en la posicion 5 del tablero, se desplegara debajo del tablero la barra de comandos, donde podras escirbir para escribir el comando.\n" );
  printf("La lista de comandos es:\n" );
  printf("\t1.- 'salir', este comado funciona para salir del juego.\n" );
  printf("\t2.- 'salirC', es para salir de la barra de comandos.\n" );

}

#endif //_INSTR_DOT_H_
