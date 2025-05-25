#include <stdio.h>
#include <stdlib.h>

#include "data.c"

// main function with basic GUI

int main(void) {

    //Open the text file
    FILE *fptr;
    fptr = fopen("finances.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        fclose(fptr);
        return 1;
    }




    int choice;

    void menu() {
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
        scanf("%d", &choice);
    }

    menu();

    switch (choice) {
        case 1:
            system("clear");
            menu();
        case 2:
            system("clear");
             menu();
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            printf("Goodbye and thanks for using our budget tracker app\n");
            break;
        default:
            printf("Invalid Choice\n");
            system("clear");
            menu();

    }

    return 0;
}