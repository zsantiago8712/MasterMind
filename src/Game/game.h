#pragma once

#include "../Players/players.h"
#include "../Files/files.h"


typedef enum state {

    MENU_PRINCIPAL = 0,
    SUB_MENU_JUGAR,
    PLAYING,
    SCOREBOARD,
    AYUDA,
    SUB_MENU_FINAL,
    ESTADO_DESCONOCIDO

} Game_state;


typedef enum dificultad {

    DIFICIL = 5,
    NORMAL = 8,
    FACIL = 12,
    DIFICULTAD_DESCONOCIDA

} Dificultad;


typedef struct game{

    Players players;
    unsigned short menuOpcionSelected;
    Game_state state;
    Dificultad dif;
    File file; 

} Game;


void mainLoop(void);