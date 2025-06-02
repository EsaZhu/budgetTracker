//
// Created by Elisa on 2025-05-19.
//

#ifndef BUDGET_H
#define BUDGET_H
#include "data.h"


void displayAllEntries(struct entry e[]);

void expenseDistribution(struct entry entries[]);

struct entry* addIncomeOrExpenseEntry(struct entry entries[]);

void modifyEntry(struct entry entries[]);


#endif //BUDGET_H
