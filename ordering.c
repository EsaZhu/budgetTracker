//
// Created by Elisa on 2025-05-19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

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
          qsort(e, sizeof(struct entry), sizeof(struct entry), sortByID);
          printf("Entries sorted by ID\n");
          break;
        case 2:
          qsort(e, sizeof(struct entry), sizeof(struct entry), sortByDate);
          printf("Entries sorted by Date\n");
          break;
        case 3:
          qsort(e, sizeof(struct entry), sizeof(struct entry), sortByAmount);
          printf("Entries sorted by Amount\n");
          break;
        case 4:
          qsort(e, sizeof(struct entry), sizeof(struct entry), sortByDescription);
          printf("Entries sorted by Description\n");
          break;
      }

      return e;

}





#include "ordering.h"
