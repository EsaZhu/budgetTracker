//
// Created by Elisa on 2025-05-19.
//

#include "budget.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//the code used to carry out the logic of the menu options - biggest file -

void displayAllEntries(struct entry e[], int size){
 	 printf("\nFinances Summary\n"
         	"=================\n"
            "ID    Date         Type       Category     Description     Amount\n"
         	 "----------------------------------------------------------------- \n");

     for(int i = 0; i < size; i++){
     	printf("%-6d%-13s%-11s%-13s%-16s%11.2lf\n",
              e[i].id,
              e[i].date,
              e[i].type,
              e[i].category,
              e[i].description,
              e[i].amount);
     }
}

//calculate all of the entries
void expenseDistribution(struct entry entries[]){

  double totalIncome = 0.0;
  double totalExpenses = 0.0;
  double totalNeeds = 0.0;
  double totalWants = 0.0;
  double netBalance = 0.0;

  for(int i = 0; i < arraySize; i++){

    if(strcmp(entries[i].type, "income") == 0) {
      totalIncome += entries[i].amount;
    }
    else if(strcmp(entries[i].type, "expense") == 0) {
      totalExpenses += entries[i].amount;

      if(strcmp(entries[i].category, "Needs") == 0) {
		totalNeeds += entries[i].amount;
      }

      else if(strcmp(entries[i].category, "Wants") == 0) {
           totalWants += entries[i].amount;
      }
    }

  }

  netBalance = totalIncome - totalExpenses;

  double needsExpense = totalNeeds/totalExpenses * 100;
  double needsIncome = totalNeeds/totalIncome * 100;

  double wantsExpense = totalWants/totalExpenses * 100;
  double wantsIncome = totalWants/totalIncome * 100;

	printf("\n===== Expense Distribution Report =====\n"
         "Total Income: $%.2lf\n"
         "Total Expenses: $%.2lf\n"
         "Needs: $%.2lf (%.2lf%% of expenses, %.2lf%% of income)\n"
         "Wants: $%.2lf (%.2lf%% of expenses, %.2lf%% of income)\n"
         "Net Balance: $%.2lf\n",
         totalIncome, totalExpenses, totalNeeds, needsExpense, needsIncome, totalWants, wantsExpense, wantsIncome, netBalance);

  	printf("=====================================\n");
}

struct entry* addIncomeOrExpenseEntry(struct entry entries[]){

  char enter = 0;
  char date[11] = {0};
  char type[20] = {0};
  char category[20] = {0};
  char description[100] = {0};
  double amount = 0;

  int id = (arraySize > 0) ? entries[arraySize-1].id + 1 : 1; //create a new ID which is 1 more than the last

  printf("Use today's date? (y/n) ");
  scanf(" %c", &enter); // skip white space. take input of character type

  if(enter == 'n' || enter == 'N') {
      printf("Enter date (YYYY-MM-DD): ");
      scanf("%10s", date); //limit input length to 10 chars
  } else {
      time_t rawtime;
      struct tm * timeinfo;
      // YYYY-MM-DD format
      time(&rawtime);
      timeinfo = localtime(&rawtime);
      strftime(date, sizeof(date), "%Y-%m-%d", timeinfo);
  }


  printf("Type (income/expense): ");
  scanf("%19s", type);
  printf("Category: ");
  scanf("%19s", category);
  printf("Description: ");
  scanf("%99s", description);
  printf("Amount: $");
  scanf("%lf", &amount);

  //reallocate memory
 	struct entry* newEntries = realloc(entries, sizeof(struct entry) * (arraySize + 1));
        if(!newEntries) {
          fprintf(stderr, "Memory Allocation Failed\n");
          return entries; // return the original array if the allocation of memory fails to create a new array. this could be due to lack of space
        }


  //add a new entry
  newEntries[arraySize].id = id;
  strncpy(newEntries[arraySize].date, date, sizeof(newEntries[arraySize].date) - 1);
  strncpy(newEntries[arraySize].type, type, sizeof(newEntries[arraySize].type) - 1);
  strncpy(newEntries[arraySize].category, category, sizeof(newEntries[arraySize].category) - 1);
  strncpy(newEntries[arraySize].description, description, sizeof(entries[arraySize].description) - 1);
  newEntries[arraySize].amount = amount;

  //null-termination
  newEntries[arraySize].date[sizeof(newEntries[arraySize].date) - 1] = '\0';
  newEntries[arraySize].type[sizeof(newEntries[arraySize].type) - 1] = '\0';
  newEntries[arraySize].category[sizeof(newEntries[arraySize].category) - 1] = '\0';
  newEntries[arraySize].description[sizeof(newEntries[arraySize].description) - 1] = '\0';

  arraySize++;
  printf("Entry added successfully with ID: %-6d\n", id);
  return newEntries;


}


void modifyEntry(struct entry entries[]){
  displayAllEntries(entries, arraySize);

  int id;
  int choice;
  char newDate[11] = {0};
  double newAmount;
  int entryNum;

  int i = 0;
  int foundID = 0;

  do{
    printf("Enter ID of entry to modify: ");
  	scanf("%d", &id);
    for(i = 0;i<arraySize;i++){
      if(id == entries[i].id){
        foundID = 1;
        break;
      }
    }

  }while(foundID != 1);




  printf("\n");
  printf("Current details:\n");
      entryNum = i;
      printf("ID: %-6d\n", entries[i].id);
      printf("Date: %s\n", entries[i].date);
      printf("Type: %s\n", entries[i].type);
      printf("Category: %s\n", entries[i].category);
      printf("Description: %s\n", entries[i].description);
      printf("Amount: $%.2lf\n", entries[i].amount);


  do{
    printf("What would you like to modify?\n"
         "1. Date\n"
         "2. Amount\n");
    scanf("%d", &choice);
  }while(choice < 1 || choice > 2);

  switch(choice){
    case 1:
      printf("Enter a new date (YYYY-MM-DD): ");
      scanf("%10s", newDate);
      strncpy(entries[entryNum].date, newDate, 10);
      entries[entryNum].date[10] = '\0';
      break;

    case 2:
      printf("Enter a new amount: $");
      scanf("%lf", &newAmount);
      entries[entryNum].amount = newAmount;
      break;

  }

  printf("Entry updated successfully.\n");

}




#include "budget.h"
