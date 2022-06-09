#include "files.h"
#include <stdlib.h>
#include <string.h>

static inline void closeFile(File* file);
static unsigned char openFile(FILE* file, const char* fileName);
static int getSizeFiel(FILE* file);

void initFile(File* file, const char* fileName){
    file->fileName = strdup(fileName);
    file->file = NULL;
}


void destroyFile(File* file){
    free(file->fileName);
    file->fileName = NULL;

    free(file->data);
    file->data = NULL;
}

void readFile(File* file){

    int sizeFile = 0;
    if(!openFile(file->file, file->fileName))
        return;


    sizeFile = getSizeFiel(file->file);
    if(sizeFile == 0)
        return;

    
    file->data = calloc(sizeFile, sizeof(char));
    fread(file->data, 1, sizeFile, file->file);

    closeFile(file);
}


void writeFile(File* file, const char* data){

    if(openFile(file->file, file->fileName))
        return;

    fprintf(file->file, "%s", data);

    closeFile(file);
}


static unsigned char openFile(FILE* file, const char* fileName){
    file = fopen(fileName, "w");

    if(!file)
        return 0;

    return 1;
}


static inline void closeFile(File* file){
    fclose(file->file);
    file->file = NULL;
}


static int getSizeFiel(FILE* file){

    int sizeFile = 0;

    fseek(file, 0, SEEK_END);
    sizeFile = ftell(file);
    rewind(file);

    return sizeFile;
}