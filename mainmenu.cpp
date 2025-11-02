/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi 
 * Description: Main menu to go to the other modules.
 * Due: 11/2/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */

#include <iostream>
#include <cctype>
#include "mainmenu.h"
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"
using namespace std;

char bookTitle[MAX_BOOKS][TITLE_SIZE];
char isbn[MAX_BOOKS][ISBN_SIZE];
char author[MAX_BOOKS][AUTHOR_SIZE];
char publisher[MAX_BOOKS][PUBLISHER_SIZE];
char dateAdded[MAX_BOOKS][DATE_SIZE];
int qtyOnHand[MAX_BOOKS];
double wholesale[MAX_BOOKS];
double retail[MAX_BOOKS];

void strUpper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    int choice;
    
    for (int i = 0; i < MAX_BOOKS; i++) {
        bookTitle[i][0] = '\0';
        isbn[i][0] = '\0';
        author[i][0] = '\0';
        publisher[i][0] = '\0';
        dateAdded[i][0] = '\0';
        qtyOnHand[i] = 0;
        wholesale[i] = 0.0;
        retail[i] = 0.0;
    }
    
    do {
        cout << "\n       Serendipity Booksellers\n";
        cout << "              Main Menu\n\n";
        cout << "  1. Cashier Module\n";
        cout << "  2. Inventory Database Module\n";
        cout << "  3. Report Module\n";
        cout << "  4. Exit\n\n";
        cout << "  Enter Your Choice: ";
        cin >> choice;
        cin.ignore();
        
        while (choice < 1 || choice > 4) {
            cout << "\n  Please enter a number in the range 1 - 4.\n";
            cout << "  Enter Your Choice: ";
            cin >> choice;
            cin.ignore();
        }
        
        switch (choice) {
            case 1:
                cashier();
                break;
            case 2:
                invMenu();
                break;
            case 3:
                reports();
                break;
            case 4:
                cout << "\nExiting program...\n";
                break;
        }
    } while (choice != 4);
    
    return 0;
}