#ifndef _SCREENC_DOT_H_
#define _SCREENC_DOT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "DibujoMM.h"





void pantallaC(){

  MasterMind();

  printf("\n\n\t LOADING " );
fflush(stdout);
  for (int i = 0; i <= 10; i++){ //30 realista
    printf("███");
    sleep(1);
    fflush(stdout);

  }

}



void pantallaCa(){

  MasterMind();
  printf("\n\n\t LOADING " );

  char ch = 219;
  for (int i = 0; i <= 10; i++){ //30 realista
    printf("███");
    sleep(1);
    fflush(stdout);
  }


}



#endif //_SCREENC_DOT_H_
