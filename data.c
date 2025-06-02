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

    struct entry tempEntry;
    char *tokens[6];
    char *token = strtok(input, "|");
    int i = 0;

    while(token != NULL && i < 6) {
      tokens[i++] = token;
      token = strtok(NULL, "|");

    }

    if(i != 6) {
      printf("Too many fields in input line\n");
      exit(EXIT_FAILURE);
    }

    tempEntry.id = atoi(tokens[0]);
    strncpy(tempEntry.date, tokens[1], MAX_FIELD_LENGTH);
    strncpy(tempEntry.type, tokens[2], MAX_FIELD_LENGTH);
    strncpy(tempEntry.category, tokens[3] , MAX_FIELD_LENGTH);
    strncpy(tempEntry.description, tokens[4] , MAX_FIELD_LENGTH);
    tempEntry.amount = atof(tokens[5]);

    tempEntry.date[MAX_FIELD_LENGTH] = '\0';
    tempEntry.type[MAX_FIELD_LENGTH] = '\0';
    tempEntry.category[MAX_FIELD_LENGTH] = '\0';
    tempEntry.description[MAX_FIELD_LENGTH] = '\0';

    return tempEntry;

}

struct entry* fileInput() {

  FILE* file = openFile("finances.txt", "r");
  if (file == NULL) {
      printf("Error opening file\n");
      exit(EXIT_FAILURE);
  }

  struct entry *entries = NULL;
  char row_buffer[MAX_LINE_LENGTH + 2];
  int capacity = 0;

  while(fgets(row_buffer, sizeof(row_buffer), file) != NULL) {

    size_t len = strlen(row_buffer);
    if (len > 0 && row_buffer[len - 1] == '\n') {
      row_buffer[len - 1] = '\0';
    }

    if(len == MAX_LINE_LENGTH + 1 && row_buffer[MAX_LINE_LENGTH] != '\n' && row_buffer[MAX_LINE_LENGTH] != '\0') {
      printf("Error: line too long\n");
      exit(EXIT_FAILURE);
    }

    if(arraySize >= capacity) {
      capacity = (capacity == 0) ? 1 : capacity * 2;
      struct entry *newEntries = (struct entry*)realloc(entries, sizeof(struct entry) * capacity);
      if (newEntries == NULL) {
        free(entries);
        printf("Memory allocation failed\n");

      }
      entries = newEntries;
    }

    entries[arraySize] = parseLine(row_buffer);
    arraySize++;

  }

  if(ferror(file)) {
    free(entries);
    printf("Error reading file\n");
    exit(EXIT_FAILURE);

  }

  fclose(file);
  return entries;

}

