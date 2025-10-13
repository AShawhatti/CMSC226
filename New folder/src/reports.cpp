/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Does the same thing as the other one we just added functions for the cout instead of hard coding it
 * Due: 10/05/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */


#include <iostream>
#include "functionPrototypes.h"
using namespace std;

void repListing()   { cout << "You selected Inventory Listing.\n"; }
void repWholesale() { cout << "You selected Inventory Wholesale Value.\n"; }
void repRetail()    { cout << "You selected Inventory Retail Value.\n"; }
void repQty()       { cout << "You selected Listing By Quantity.\n"; }
void repCost()      { cout << "You selected Listing By Cost.\n"; }
void repAge()       { cout << "You selected Listing By Age.\n"; }

void reports() {
    int choice;
    do {
        cout << "Serendipity Booksellers\nReports\n";
        cout << "1. Inventory Listing\n2. Inventory Wholesale Value\n3. Inventory Retail Value\n";
        cout << "4. Listing by Quantity\n5. Listing by Cost\n6. Listing by Age\n7. Return to Main Menu\n";
        cin >> choice;
        while (choice < 1 || choice > 7) cin >> choice;
        switch(choice) {
            case 1: repListing(); break;
            case 2: repWholesale(); break;
            case 3: repRetail(); break;
            case 4: repQty(); break;
            case 5: repCost(); break;
            case 6: repAge(); break;
            case 7: cout << "Returning to Main Menu\n"; break;
        }
    } while(choice != 7);
}
