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

void displayAllEntries(struct entry e[]){
 	 printf("\nFinances Summary\n"
         	"=================\n"
            "ID    Date         Type       Category     Description     Amount\n"
         	 "‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐ \n");

     for(int i = 0; i < arraySize; i++){
     	printf("%-6d%-13s%-11s%-13s%-16s%-11.2lf\n",
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
    else if(strcmp(entries[i].type, "total") == 0) {
      totalExpenses += entries[i].amount;
      if(strcmp(entries[i].category, "needs") == 0) {
		totalNeeds += entries[i].amount;
      }
      else if(strcmp(entries[i].category, "wants") == 0) {
           totalWants += entries[i].amount;
      }
    }

  }

  netBalance = totalIncome - totalExpenses;

	printf("\n===== Expense Distribution Report =====\n"
         "Total Income: $%.2lf\n"
         "Total Expenses: $%.2lf\n"
         "Needs: $%.2lf\n"
         "Wants: $%.2lf\n"
         "Net Balance: $%.2lf\n",
         totalIncome, totalExpenses, totalNeeds, totalWants, netBalance);

  	printf("=====================================\n");
}

struct entry* addIncomeOrExpenseEntry(struct entry entries[]){

  char enter;

  char date;
  char type;
  char category;
  char description;
  double amount;
  int id = entries[arraySize].id + 1;

  printf("Use today's date? (y/n)");
  scanf("%s", &enter);
  if(enter == 'n' || enter == 'N') {
      printf("Enter date (YYYY-MM-DD): ");
      scanf("%s", &date);
  } else {
      time_t rawtime;
      struct tm * timeinfo;
      // YYYY-MM-DD format
      time(&rawtime);
      timeinfo = localtime(&rawtime);
      strftime(&date, 11, "%Y-%m-%d", timeinfo);
  }
  printf("Type (income/expense): ");
  scanf("%s", &type);
  printf("Category: ");
  scanf("%s", &category);
  printf("Description: ");
  scanf("%s", &description);
  printf("Amount: ");
  scanf("%lf", &amount);

  int newSize = arraySize + 1;

  struct entry newEntry[newSize];

  for(int i = 0; i < newSize; i++){
    newEntry[i] = entries[i];
  }

  entries[newSize].id = id;
  strcpy(entries[newSize].date, &date);
  strcpy(entries[newSize].type, &type);
  strcpy(entries[newSize].category, &category);
  strcpy(entries[newSize].description, &description);
  entries[newSize].amount = amount;

  arraySize++;


  printf("Entry added successfully with ID: %-6d\n", id);



}

void modifyEntry(struct entry entries[]){
  displayAllEntries(entries);

  int id;
  int choice;
  char newDate;
  double newAmount;
  int entryNum;

  printf("Enter ID of entry to modify: ");
  scanf("%d", &id);
  printf("Current details:\n");
  for(int i = 0; i < arraySize; i++){
    if(id == entries[i].id){
      entryNum = i;
      printf("ID: %-6d\n", entries[i].id);
      printf("Date: %s\n", entries[i].date);
      printf("Type: %s\n", entries[i].type);
      printf("Category: %s\n", entries[i].category);
      printf("Description: %s\n", entries[i].description);
      printf("Amount: %.2lf\n", entries[i].amount);
      break;
    }
  }

  printf("What would you like to modify?\n"
         "1. Date"
         "2. Amount");

  scanf("%d", &choice);
  switch(choice){
    case 1:
      printf("Enter a new date (YYYY-MM-DD): ");
      scanf("%s", &newDate);
      strcpy(entries[entryNum].date, &newDate);
      break;
    case 2:
      printf("Enter a new amount: ");
      scanf("%lf", &newAmount);
      entries[entryNum].amount = newAmount;
      break;

  }

  printf("Entry updated successfully.\n");

}


#include "budget.h"
