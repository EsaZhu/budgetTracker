//
// Created by Elisa on 2025-05-19.
//

//any code used to read the input file and extract the fields from each row

#include "data.h"
#include "main.c"
#include <stdio.h>
#include <string.h>


// char id[100];
// char date[100];
// char type[100];
// char category[100];
// char description[100];
// char amount[100];

char line[256];
void fileRead(FILE* file){

  while (fgets(line, sizeof(line), file) != NULL) {
    //process each line in the text file
    char *token;
    char *rest = line;

    while ((token = strtok_r(rest, ",", &rest))) {

    }
  }


}
