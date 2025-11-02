#ifndef MAINMENU_H
#define MAINMENU_H

const int MAX_BOOKS = 20;
const int TITLE_SIZE = 51;
const int ISBN_SIZE = 14;
const int AUTHOR_SIZE = 31;
const int PUBLISHER_SIZE = 31;
const int DATE_SIZE = 11;

extern char bookTitle[MAX_BOOKS][TITLE_SIZE];
extern char isbn[MAX_BOOKS][ISBN_SIZE];
extern char author[MAX_BOOKS][AUTHOR_SIZE];
extern char publisher[MAX_BOOKS][PUBLISHER_SIZE];
extern char dateAdded[MAX_BOOKS][DATE_SIZE];
extern int qtyOnHand[MAX_BOOKS];
extern double wholesale[MAX_BOOKS];
extern double retail[MAX_BOOKS];

void strUpper(char *str);

#endif