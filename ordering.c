//
// Created by Elisa on 2025-05-19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "budget.h"

// Any code related to sorting the entries

int sortByID(const void *a, const void *b){
   return ((struct entry*)a)->id - ((struct entry*)b)->id;
}
int sortByDate(const void *a, const void *b){
  return ((struct entry*)a)->date - ((struct entry*)b)->date;
}
int sortByAmount(const void *a, const void *b){
  return ((struct entry*)a)->amount - ((struct entry*)b)->amount;
}
int sortByDescription(const void *a, const void *b){
  return ((struct entry*)a)->description - ((struct entry*)b)->description;
}




struct entry* sortEntries(struct entry e[]){
      int choice = -1;
      printf("Choose an option:\n"
             "1. Sort by ID\n"
             "2. Sort by Date\n"
             "3. Sort by Amount\n"
             "4. Sort by Description\n");
      do{
        scanf("%d", &choice);
      } while(choice < 1 || choice > 4);

      switch(choice){
        case 1:
          qsort(e, arraySize, sizeof(struct entry), sortByID);
          printf("Entries sorted by ID\n");
          break;
        case 2:
          qsort(e, arraySize, sizeof(struct entry), sortByDate);
          printf("Entries sorted by Date\n");
          break;
        case 3:
          qsort(e, arraySize, sizeof(struct entry), sortByAmount);
          printf("Entries sorted by Amount\n");
          break;
        case 4:
          qsort(e, arraySize, sizeof(struct entry), sortByDescription);
          printf("Entries sorted by Description\n");
          break;
      }

      return e;

}


void filterByMonth(struct entry entries[]){

  int year;
  int month;

  printf("Enter year (YYYY): ");
  scanf("%d", &year);
  printf("Enter month (1-12): ");
  scanf("%d", &month);

  char date[8];
  snprintf(date, sizeof(date), "%04d-%02d", year, month); //create a string from the inputs

  struct entry *newEntry = malloc(sizeof(struct entry) * arraySize);
  if(!newEntry){
    fprintf(stderr, "Memory allocation error\n");
    return;
  }
  int match = 0;

  for(int i = 0; i < arraySize; i++){
    if(strncmp(entries[i].date, date, 7) == 0){
      newEntry[match] = entries[i];
      match++;

    }
  }

  if(match > 0){
    displayAllEntries(newEntry, match);
  } else {
    printf("No entries found for %s\n", date);
  }

  free(newEntry);

}



#include "ordering.h"
