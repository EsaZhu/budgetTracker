#include <stdio.h>
#include <stdlib.h>


#include "data.h"
#include "ordering.h"
#include "budget.h"

// main function with basic GUI

int main() {

   struct entry* entries = fileInput();


    int choice = -1;

    do{
       printf("Budget Tracking System\n"
               "=====================\n"
               "1. Display all entries\n"
               "2. Expense Distribution\n"
               "3. Sort Entries\n"
               "4. Add Income/Expense Entry\n"
               "5. Modify Entry\n"
               "6. Filter by Month\n"
               "7. Exit\n");
        printf("Choice: ");
        do{
            scanf("%d", &choice);
        }while(choice < 1 || choice > 7);

        system("clear");

            switch (choice) {
            case 1:
                printf("hello");
                displayAllEntries(entries);
                break;
            case 2:
                expenseDistribution(entries);
                break;
            case 3:
                entries = sortEntries(entries);
                break;
            case 4:
                entries = addIncomeOrExpenseEntry(entries);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                break;

         }


    }while(choice != 7);
    printf("Goodbye and thanks for using our budget tracker app\n");
    return 0;
}