//
// Created by Elisa on 2025-05-19.
//

#ifndef DATA_H
#define DATA_H

#include <stdio.h>

// Store the extracted fields from each row by grouping related data items of different types.
// Must create a struct named Entry with all the fields in each line of the txt file

#define MAX_FIELD_LENGTH 100 //all string fields are no longer than 100 characters.
#define MAX_LINE_LENGTH (6*MAX_FIELD_LENGTH+5) //  6 files + 5 delimiters

typedef struct entry {
    int id;
    char date[MAX_FIELD_LENGTH + 1];
    char type[MAX_FIELD_LENGTH + 1];
    char category[MAX_FIELD_LENGTH + 1];
    char description[MAX_FIELD_LENGTH + 1];
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



#endif //DATA_H
//Including guards (#ifndef, #define, and #endif) to prevent header file from
// being included multiple times in a single compilation unit.
