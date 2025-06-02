//
// Created by Elisa on 2025-05-19.
//

#ifndef ORDERING_H
#define ORDERING_H
#include "budget.h"

int sortByID(const void* a, const void* b);
int sortByDate(const void* a, const void* b);
int sortByAmount(const void* a, const void* b);
int sortByDescription(const void* a, const void* b);

struct entry* sortEntries(struct entry e[]);
void filterByMonth(struct entry entries[]);

#endif //ORDERING_H
