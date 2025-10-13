#ifndef FUNCTION_PROTOTYPES_H
#define FUNCTION_PROTOTYPES_H

#include <string>
using namespace std;
#include "globals.h"

void cashier();
void invMenu();
void reports();
void bookInfo(string, string, string, string, string, int, double, double);
void addBook();
void lookUpBook();
void editBook();
void deleteBook();
void repListing();
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();

#endif
