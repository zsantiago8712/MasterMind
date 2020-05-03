#include <stdio.h>
#include <stdlib.h>
#include "cabeceraJ.h"


void Scores(){
cM();
printf("\n\t\t\t~~~~~USERNAME~~~      ~~~~~SCORE~~~~~~\n" );
FILE *scores = fopen ( "Scores.text", "r" );
	if (scores==NULL) {fputs ("File error",stderr); exit (1);}

char Scrs[150];
  while(!feof(scores)){
    fgets(Scrs, 150, scores);
    puts(Scrs);
  }
	fclose ( scores );
}
