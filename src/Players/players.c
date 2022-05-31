#include "players.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



static unsigned char repeteadeColor(const char colorsCPU[5], const unsigned char lenght, const unsigned char color);
static void getRandomColors(char colorsCPU[5]);
static void createTbaleros(char** tableroJugador, char** tableroCPU, unsigned int size);
static void fillTableros(char** tableroJugador, char** tableroCPU, unsigned char size);


void initPlayers(Players* players, unsigned char size){
    players->intentos = 0;
    players->aciertos = 0;
    players->size = size;
    getRandomColors(players->cpuColors);
    createTbaleros(players->tableroJugador, players->tableroCPU, size);    
}

void destroyPLayers(Players* players){
    for(unsigned int i = 0; i < players->size; i++){
        free(players->tableroJugador[i]);
        free(players->tableroCPU[i]);
        players->tableroJugador[i] = NULL;
        players->tableroCPU[i] = NULL;
    }

    free(players->tableroJugador);
    free(players->tableroCPU);
    players->tableroJugador = NULL;
    players->tableroCPU = NULL;

    players->intentos = 0;
    players->aciertos = 0;
    players->size = 0;

    memset(players->cpuColors, 0, sizeof(players->cpuColors));
}


static void getRandomColors(char colorsCPU[5]){

    const char colors[8] = {'A', 'R', 'V', 'G', 'M', 'N', 'B', 'C'};
    unsigned char lenght = 0;
    int color;


    srand(time(NULL));

    while(lenght < 5){
        color = rand() % 7 - 0;
        if(repeteadeColor(colorsCPU, lenght, color) == FALSE){
            colorsCPU[lenght] = color;
            lenght ++;
        }     
    }
}

static unsigned char repeteadeColor(const char colorsCPU[5], const unsigned char lenght, const unsigned char color) {

    for(unsigned char i = 0; i < lenght; i++) {
        if(color == colorsCPU[i])
            return TRUE;
    }
    return FALSE;
}

static void createTbaleros(char** tableroJugador, char** tableroCPU, unsigned int size){
    tableroJugador = (char**) calloc(size, sizeof(char*));
    tableroCPU = (char**) calloc(size, sizeof(char*));

    for(unsigned char i = 0; i < size; i++){
        tableroJugador[i] = (char*) calloc(5, sizeof(char));
        tableroCPU[i] = (char*) calloc(5, sizeof(char));
    }

    
    fillTableros(tableroJugador, tableroCPU, size);
}


static void fillTableros(char** tableroJugador, char** tableroCPU, unsigned char size){
    for(unsigned int i = 0; i < size; i++){
        for(unsigned int j = 0; j < 5; j++){
            tableroJugador[i][j] = (j + 1) + '0';
            tableroCPU[i][j] = (j + 1) + '0';
        }
    }
}