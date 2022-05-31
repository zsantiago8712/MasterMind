#include "game.h"
#include<ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define TOTAL_ACIERTOS 5

static void printTablero(const char** tableroJugador, const char** tableroCPU, Dificultad dif);
static unsigned char checkLeterRepeticion(const unsigned char letra, const char* row);
static unsigned char checkLeter(const char letra, const char colors[5]);
static void scoreboardUpdate(const unsigned char lose, File* file, const unsigned short intentos, const char combinacion[5]);
static void initGame(Game* game);
static void jugar(Game* game);
static unsigned char checkOption(const unsigned short option, Game_state state);
static void menuPrincipal(void);
static void subMenuJugar(void);
static void subMenuFinal(void);
static void destroyGame(Game* game);
static void salir(Game* game);
static void ayuda(Game* game);
static void scoreBoard(Game* game);

void mainLoop(void){

    Game game;
    void (*functions[4])(Game* game) = { jugar, scoreBoard, ayuda, salir };
    void (*menuFunctions[3])() = { menuPrincipal, subMenuJugar, subMenuFinal };

    initGame(&game);

    while(TRUE) {

        if(game.state == MENU_PRINCIPAL || game.state == SUB_MENU_JUGAR || game.state == SUB_MENU_FINAL)
            (menuFunctions[game.state])();

        scanf("%hd", &game.menuOpcionSelected);
        if(checkOption(game.menuOpcionSelected, game.state) == TRUE){

            if(game.state == MENU_PRINCIPAL && game.menuOpcionSelected == 1)
                game.state = SUB_MENU_JUGAR;
            else if(game.state == SUB_MENU_FINAL && game.menuOpcionSelected == 2)
                (functions[game.menuOpcionSelected])(&game); 
            else if(game.state == SUB_MENU_JUGAR && game.menuOpcionSelected == 4)
                game.state = MENU_PRINCIPAL;
            else
                (functions[game.menuOpcionSelected - 1])(&game);                    
        }
    }

}


static unsigned char checkOption(const unsigned short option, Game_state state){
    switch(state) {
        case MENU_PRINCIPAL: case SUB_MENU_JUGAR:
            if(option >= 1 && option <= 4)
                return TRUE;
            break;
        case SUB_MENU_FINAL:
            if(option > 0 && option < 3)
                return TRUE;
        default:
            break;
    }
    return FALSE;
}



static void initGame(Game* game){
    game->menuOpcionSelected = 0;
    game->dif = FACIL;
    game->state = MENU_PRINCIPAL;
    initFile(&game->file, "scoreboar.txt");
}


static void destroyGame(Game* game){
    destroyPLayers(&game->players);
    destroyFile(&game->file);
}

static void jugar(Game* game){

    unsigned short index;
    unsigned char lose;
    char letra;

    game->state = PLAYING;

    initPlayers(&game->players, game->dif);

    do{

        printTablero((const char**)game->players.tableroJugador, (const char**)game->players.tableroCPU, game->dif);
        printf("-> ");
        scanf("%hd %c", &index, &letra);

        letra = toupper(letra);
        if(index >= 1 && index <= 5 && checkLeterRepeticion(letra, game->players.tableroJugador[game->players.intentos]) == FALSE){
            if(checkLeter(letra, game->players.cpuColors) == TRUE){
                game->players.tableroCPU[game->players.intentos][index] = 'X';
                game->players.aciertos += 1;
            }else
                game->players.tableroCPU[game->players.intentos][index] = 'O';

            game->players.tableroJugador[game->players.intentos][index] = letra;

        }

        if(index == 5)
            game->players.intentos += 1;

    }while(game->players.intentos < game->dif || game->players.aciertos < TOTAL_ACIERTOS);

    if(game->players.aciertos == 5)
        lose = FALSE;
    else
        lose = TRUE;

    scoreboardUpdate(lose, &game->file, game->players.intentos, game->players.cpuColors);
}


static unsigned char checkLeter(const char letra, const char colors[5]){
    for(unsigned char i = 0; i < 5; i++){
        if(letra == colors[i])
            return TRUE;
    }

    return FALSE;
}

static unsigned char checkLeterRepeticion(const unsigned char letra, const char* row){
    for(unsigned char i = 0; i < 5; i++){
        if(letra == row[i])
            return TRUE;
    }

    return FALSE;
}


static void printTablero(const char** tableroJugador, const char** tableroCPU, Dificultad dif){


    system("clear");
    if(dif >= DIFICULTAD_DESCONOCIDA || dif < DIFICIL){
        puts("ERROR: Dificultad DESCONOCIDA");
        return;
    }

    puts("\t\t~~~~~~~~~~~~~~~~~~MASTERMIND~~~~~~~~~~~~~~~~~~~~");
    puts("Teclea la letra del color y despues el numero donde quieres ponerla!\n");
    puts("\t\t\t  Tablero\t\t\t\tCoincidencias\n");
                 
    for(unsigned char i = 0; i < dif; i++){
        puts("\t\t----------------\t\t  ~~~~~~~~~~~~~~~~");
        printf("\t\t|" );

        for(unsigned char j = 0; j < 5; j++)
          printf(" %c|", tableroJugador[i][j]);

        printf("\t|");

        for(unsigned char j = 0; j < 5; j++)
          printf(" %c|", tableroCPU[i][j]);
    }
} 


static void endMessage(const char namePlayer[12], const unsigned char lose,  const unsigned short intentos, const char combinacion[5]){
    if(lose == TRUE){
        puts("\n\n\n\t\t\t\tPERDISTE!!!! =(\n" );
        printf("\nLA combinación correcta era %c %c %c %c %c\n\n", combinacion[0], combinacion[1], combinacion[2], combinacion[3], combinacion[4]);
        return;
    }

    puts("\n\n\t\t\t FELICIDADES, GANASTE!!!1");
    printf("\t\t\tLO LOGRASTE EN %d INTENTOS!!!! \n", intentos);
}


static void scoreboardUpdate(const unsigned char lose, File* file, const unsigned short intentos, const char combinacion[5]){
    char name[12];
    char info[15];

    printf("Ingresa tu usuraio\n-> ");
    fgets(name, sizeof(name), stdin);

    sprintf(info, "%s %d\nn", name, intentos);
    writeFile(file, info);

    endMessage(name, lose, intentos, combinacion);
}


static void salir(Game* game){
    destroyGame(game);
    exit(EXIT_SUCCESS);
}

void cabecera(void){

    system("clear");
    puts("\033[32m" );
    puts("\t  ███╗   ███╗ █████╗ ███████╗████████╗███████╗██████╗ ");
    puts("\t  ████╗ ████║██╔══██╗██╔════╝╚══██╔══╝██╔════╝██╔══██╗");
    puts("\t  ██╔████╔██║███████║███████╗   ██║   █████╗  ██████╔╝");
    puts("\t  ██║╚██╔╝██║██╔══██║╚════██║   ██║   ██╔══╝  ██╔══██╗");
    puts("\t  ██║ ╚═╝ ██║██║  ██║███████║   ██║   ███████╗██║  ██║");
    puts("\t  ╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝");
    puts("\t                                                  v1.0.0");
    puts("\t             ███╗   ███╗██╗███╗   ██╗██████╗");
    puts("\t             ████╗ ████║██║████╗  ██║██╔══██╗");
    puts("\t             ██╔████╔██║██║██╔██╗ ██║██║  ██║ ");
    puts("\t             ██║╚██╔╝██║██║██║╚██╗██║██║  ██║");
    puts("\t             ██║ ╚═╝ ██║██║██║ ╚████║██████╔╝" );
    puts("\t             ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═════╝");
}


static void menuPrincipal(void){

    cabecera();
    puts("\n                      ~~~~~~~~Menu Principal~~~~~~~\n" );
    puts("                               1.- JUGAR");
    puts("                               2.- COMO SE JUEGA");
    puts("                               3.- MARCADORES");
    puts("                               4.- SALIR");
}


static void subMenuJugar(void){

    cabecera();
    puts("                      ~~~~~~~~Menu Principal~~~~~~~");
    puts("                              JUGAR" );
    puts("                                JUGADOR VS. CPU");
    puts("                                   DIFICULTAD");
    puts("                                   1.- ~~FÁCIL~~~");
    puts("                                   2.- ~~NORMAL~~");
    puts("                                   3.- ~~DÍFICL~~");
    puts("                                   4.- ~~REGRESAR~~" );
    puts("                             COMO SE JUEGA");
    puts("                             MARCADORES");
    puts("                             SALIR");
}

static void subMenuFinal(void){

    cabecera();
    puts("\n                        ~~~~~~~~~ Menu ~~~~~~~~\n\n" );
    puts("                             1.- VOLVER A JUGAR\n" );
    puts("                             2.- SALIR DEL JUEGO\n" );
}


static void ayuda(Game* game){
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

static void scoreBoard(Game* game){
    readFile(&game->file);
    printf("%s", game->file.data);
}