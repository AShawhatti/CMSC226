#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
using namespace std;

const int MAX_BOOKS = 20;

extern string bookTitle[MAX_BOOKS];
extern string isbn[MAX_BOOKS];
extern string author[MAX_BOOKS];
extern string publisher[MAX_BOOKS];
extern string dateAdded[MAX_BOOKS];
extern int qtyOnHand[MAX_BOOKS];
extern double wholesale[MAX_BOOKS];
extern double retail[MAX_BOOKS];

#endif
