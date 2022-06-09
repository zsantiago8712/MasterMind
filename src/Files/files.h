#pragma once

#include <stdio.h>



typedef struct file{
    
    char *fileName;
    FILE* file;
    char* data;

}File;


void initFile(File* file, const char* fileName);
void destroyFile(File* file);

void readFile(File* file);
void writeFile(File* file, const char* data);
