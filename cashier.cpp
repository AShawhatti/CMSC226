/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Calculates the book cost and how much of it you want then adds it to the total then asks if you wanna buy again
 * Due: 10/19/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Hassan Shawhatti
 */


#include <iostream>
#include <iomanip>
#include "functionPrototypes.h"
#include "globals.h"
#include <string>
using namespace std;

void cashier() {
    const double Tax_Rate = 0.06;
    char anotherTrans;
    do {
        string Date;
        cout << "Serendipity Booksellers\nCashier Module\n";
        cout << "Date: ";
        cin >> Date;

        double subtotal = 0;
        double tax = 0;
        double total = 0;
        char moreBooks;

        do {
            string isbnInput;
            cout << "Enter ISBN: ";
            cin >> isbnInput;

            int found = -1;
            for (int i = 0; i < MAX_BOOKS; i++) {
                if (isbn[i] == isbnInput) {
                    found = i;
                    break;
                }
            }

            if (found == -1) {
                char retry;
                cout << "Book not found. Re-enter ISBN? (Y/N): ";
                cin >> retry;
                if (retry == 'Y' || retry == 'y') continue;
                else break;
            }

            int qty;
            cout << "Quantity of Book: ";
            cin >> qty;

            if (qty > qtyOnHand[found]) {
                cout << "Not enough copies in stock.\n";
                return;
            }

            double price = retail[found];
            double itemSubtotal = qty * price;
            subtotal += itemSubtotal;
            qtyOnHand[found] -= qty;

            cout << left << setw(5) << qty << left << setw(14) << isbn[found]
                 << left << setw(24) << bookTitle[found] << right << setw(7)
                 << fixed << setprecision(2) << price << right << setw(12)
                 << fixed << setprecision(2) << itemSubtotal << endl;

            cout << "Add another book? (Y/N): ";
            cin >> moreBooks;
        } while (moreBooks == 'Y' || moreBooks == 'y');

        tax = subtotal * Tax_Rate;
        total = subtotal + tax;

        cout << setw(25) << "Subtotal" << setw(15) << subtotal << endl
             << setw(25) << "Tax" << setw(15) << tax << endl
             << setw(25) << "Total" << setw(15) << total << endl << endl;

        cout << "Do you want to start a new transaction? (Y/N): ";
        cin >> anotherTrans;
    } while (anotherTrans == 'Y' || anotherTrans == 'y');

    cout << "Thank you for Shopping at Serendipity!\n";
}
