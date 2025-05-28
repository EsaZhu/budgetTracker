//
// Created by Elisa on 2025-05-19.
//

//any code used to read the input file and extract the fields from each row

#include "data.h"
#include <stdio.h>
#include <string.h>


struct entry* parseLine(char input[]) {
    //creating a duplicate of input array to avoid segmentation errors
    struct entry* tempEntry = malloc(strlen(input) + 1);
    strcpy(tempEntry, input);

    //allocate memory for new entry
    struct entry* entry = malloc(sizeof(struct entry));
    if (entry == NULL) {
        return NULL;
    }

    //tokenize the input array based on "|" delimiter
    char* dataId  = strtok(tempEntry, "|");
    char* dataDate = strtok(NULL, "|");
    char* dataType = strtok(NULL, "|");
    char* dataCategory = strtok(NULL, "|");
    char* dataDescription = strtok(NULL, "|");
    char* dataAmount = strtok(NULL, "|");
    if (dataId == NULL || dataDate == NULL || dataType == NULL || dataCategory == NULL || dataAmount == NULL) {
        return NULL;
    }

    //Copying string tokens into the char array of the entry. Converting string tokens to appropriate type.
    if (sizeof(dataId) == sizeof(int)) {
        entry->id = atoi(dataId);
    }

    memcpy(entry->date, dataDate, sizeof(entry->date));
    memcpy(entry->type, dataType, sizeof(entry->type));
    memcpy(entry->category, dataCategory, sizeof(entry->category));
    memcpy(entry->description, dataDescription, sizeof(entry->description));
    if (sizeof(dataAmount) == sizeof(double)) {
        entry->amount = atof(dataAmount);
    }


}

