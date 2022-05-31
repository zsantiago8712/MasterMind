#pragma once

#define TRUE 1
#define FALSE 0

typedef struct players{

    unsigned short intentos;
    unsigned short aciertos;

    char** tableroJugador;
    char** tableroCPU;
    int size;

    char cpuColors[5];

}Players;


void initPlayers(Players* players, unsigned char size);
void destroyPLayers(Players* players);