/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi 
 * Description: Direct your customers to the module they perfer.
 * Due: 11/2/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Hassan Shawhatti
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

void strUpper(char *textString) {
    int index = 0;
    while (textString[index] != '\0') {
        textString[index] = toupper(textString[index]);
        index++;
    }
}

int main() {
    int userSelection;
    bool keepRunning = true;
    
    int counter = 0;
    while (counter < MAX_BOOKS) {
        bookTitle[counter][0] = '\0';
        isbn[counter][0] = '\0';
        author[counter][0] = '\0';
        publisher[counter][0] = '\0';
        dateAdded[counter][0] = '\0';
        qtyOnHand[counter] = 0;
        wholesale[counter] = 0.0;
        retail[counter] = 0.0;
        counter++;
    }
    
    while (keepRunning) {
        cout << "\n       Serendipity Booksellers\n";
        cout << "              Main Menu\n\n";
        cout << "  1. Cashier Module\n";
        cout << "  2. Inventory Database Module\n";
        cout << "  3. Report Module\n";
        cout << "  4. Exit\n\n";
        cout << "  Enter Your Choice: ";
        cin >> userSelection;
        cin.ignore();
        
        bool validInput = false;
        while (!validInput) {
            if (userSelection >= 1 && userSelection <= 4) {
                validInput = true;
            } else {
                cout << "\n  Please enter a number in the range 1 - 4.\n";
                cout << "  Enter Your Choice: ";
                cin >> userSelection;
                cin.ignore();
            }
        }
        
        if (userSelection == 1) {
            cashier();
        } else if (userSelection == 2) {
            invMenu();
        } else if (userSelection == 3) {
            reports();
        } else if (userSelection == 4) {
            cout << "\nExiting program...\n";
            keepRunning = false;
        }
    }
    
    return 0;
}