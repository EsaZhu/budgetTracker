//
// Created by Elisa on 2025-05-19.
//

//any code used to read the input file and extract the fields from each row

#include "data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arraySize = 0;

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("Error opening file\n");
    }
    return file;
}

struct entry parseLine(char input[]) {

    printf("test2");

    char tempInput[1024];
    strcpy(tempInput, input);

    //tokenize the input array based on "|" delimiter
    char* dataId  = strtok(tempInput, "|");
    char* dataDate = strtok(NULL, "|");
    char* dataType = strtok(NULL, "|");
    char* dataCategory = strtok(NULL, "|");
    char* dataDescription = strtok(NULL, "|");
    char* dataAmount = strtok(NULL, "|");

    //Secntion data into correct struct
    struct entry tempEntry;
    tempEntry.id = atoi(dataId);
    memcpy(tempEntry.date, dataDate, strlen(dataDate));
    memcpy(tempEntry.type, dataType, strlen(dataType));
    memcpy(tempEntry.category, dataCategory, strlen(dataCategory));
    memcpy(tempEntry.description, dataDescription, strlen(dataDescription));
    tempEntry.amount = atof(dataAmount);


    return tempEntry;

}

//function to take the text from finance.txt and dynamically resizes the struct array

struct entry* fileInput() {

    printf("test1");

  int rows = 0;
  struct entry* entry = (struct entry*)malloc(1*sizeof(*entry));
  FILE *filePtr = fopen("finance.txt", "r");
  char row_buffer[1024];

  int i = 0;
  while (fgets(row_buffer, 256, filePtr) != NULL) {
    rows++;
    entry = realloc(entry, sizeof(*entry) * rows);
    char* temp = (char*)malloc(strlen(row_buffer));
    printf("test");
    printf("%s", temp);

    strncpy(temp, row_buffer, strlen(row_buffer) - 1);
    struct entry tempEntry = parseLine(temp);
    entry[i] = tempEntry;

    i++;
    free(temp);
  }

  arraySize = rows;
  fclose(filePtr);
  return entry;

}



int close_file(FILE* file) {
    if (file == NULL) {
        return 1;
    }
    fclose(file);
    return 0;
}




// redo

int totalLines = 0;

struct entry* readLine() {

  FILE* filePtr;
  int bufferLength = 100;
  char buffer[bufferLength];

  int rows = 0;
  filePtr = fopen("finance.txt", "r");
  while(fgets(buffer, bufferLength, filePtr) != NULL) {
    rows++;

  }


}