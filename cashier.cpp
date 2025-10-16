/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Let user buy mutiple books and lookup the ISBN.
 * Due: 10/19/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "globals.h"
#include "functionPrototypes.h"
using namespace std;

void cashier() {
    const double Tax_Rate = 0.06;
    char anotherCustomer;

    do {
        cout << "Serendipity Booksellers\nCashier Module\n";
        string date;
        cout << "Date: ";
        cin >> date;
        cin.ignore();

        string enteredIsbn;
        int foundIndex = -1;
        cout << "Enter ISBN: ";
        cin.ignore();
        getline(cin, enteredIsbn);

        
        for (int i = 0; i < MAX_BOOKS; i++) {
            if (isbn[i] == enteredIsbn && bookTitle[i] != "") {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex == -1) {
            cout << "Book not in inventory.\n";
        } else {
            int qtyRequested;
            cout << "Quantity to purchase: ";
            cin >> qtyRequested;
            cin.ignore();

            double subtotal = qtyRequested * retail[foundIndex];
            double tax = subtotal * Tax_Rate;
            double total = subtotal + tax;

            cout << "\nReceipt:\n";
            cout << left << setw(24) << "Title" << setw(10) << "Qty" << setw(10) << "Price" << setw(10) << "Subtotal\n";
            cout << left << setw(24) << bookTitle[foundIndex]
                 << setw(10) << qtyRequested
                 << setw(10) << fixed << setprecision(2) << retail[foundIndex]
                 << setw(10) << fixed << setprecision(2) << subtotal << endl;

            cout << setw(34) << "Tax: " << setw(10) << fixed << setprecision(2) << tax << endl;
            cout << setw(34) << "Total: " << setw(10) << fixed << setprecision(2) << total << endl;

            
            qtyOnHand[foundIndex] -= qtyRequested;
        }

        cout << "Do you want another customer transaction? (Y/N): ";
        cin >> anotherCustomer;
        cin.ignore();

    } while (anotherCustomer == 'Y' || anotherCustomer == 'y');

    cout << "Thank you for shopping at Serendipity!\n";
}
