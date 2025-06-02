//
// Created by Elisa on 2025-05-19.
//

#ifndef DATA_H
#define DATA_H

#include <stdio.h>

// Store the extracted fields from each row by grouping related data items of different types.
// Must create a struct named Entry with all the fields in each line of the txt file


typedef struct entry {
    int id;
    char date[101];
    char type[101];
    char category[101];
    char description[101];
    double amount;
} Entry;

extern int arraySize;

//create function prototypes for opening, parsing, and closing the txt file
// a function prototype is a function declaration: returnType functionName(type1 parameter1, ...);

//opening a file. Return a pointer to a file. Take parameters for a filename and the mode of the file (open and close).
FILE* openFile(const char* filename, const char* mode);

// dynamically size a struct array. It creates an array to store all the values in the file.
struct entry* fileInput();

//parsing a file. Return a pointer to an entry and takes as a parameter a string (line from the file)
struct entry parseLine(char input[]);

//closing a file
int close_file(FILE* file);


#endif //DATA_H
//Including guards (#ifndef, #define, and #endif) to prevent header file from
// being included multiple times in a single compilation unit.
