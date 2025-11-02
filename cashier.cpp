/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi 
 * Description: calculates book sales and gives receipts so you can check your taxes.
 * Due: 11/2/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "cashier.h"
#include "mainmenu.h"
using namespace std;

const double TAX_RATE = 0.06;

void cashier() {
    char continueTransaction;
    
    do {
        char date[20];
        char isbnInput[ISBN_SIZE];
        int qty;
        double subtotal = 0.0;
        double tax = 0.0;
        double total = 0.0;
        int itemCount = 0;
        
        struct SaleItem {
            char isbn[ISBN_SIZE];
            char title[TITLE_SIZE];
            double price;
            int qty;
            double itemSubtotal;
        };
        
        SaleItem items[MAX_BOOKS];
        
        cout << "\n\nSerendipity Booksellers\n";
        cout << "         Cashier Module\n\n";
        cout << "Date: ";
        cin.getline(date, 20);
        
        char anotherBook;
        do {
            cout << "\nISBN: ";
            cin.getline(isbnInput, ISBN_SIZE);
            
            strUpper(isbnInput);
            
            int bookIndex = -1;
            for (int i = 0; i < MAX_BOOKS; i++) {
                if (strcmp(isbn[i], isbnInput) == 0) {
                    bookIndex = i;
                    break;
                }
            }
            
            if (bookIndex == -1) {
                cout << "ISBN not found in inventory.\n";
                cout << "Do you want to re-enter the ISBN? (Y/N): ";
                char retry;
                cin >> retry;
                cin.ignore();
                if (toupper(retry) == 'Y') {
                    continue;
                } else {
                    break;
                }
            }
            
            cout << "Title: " << bookTitle[bookIndex] << endl;
            cout << "Price: $" << fixed << setprecision(2) << retail[bookIndex] << endl;
            cout << "Quantity: ";
            cin >> qty;
            cin.ignore();
            
            if (qty > qtyOnHand[bookIndex]) {
                cout << "Not enough copies in stock. Only " << qtyOnHand[bookIndex] << " available.\n";
                continue;
            }
            
            qtyOnHand[bookIndex] -= qty;
            
            strcpy(items[itemCount].isbn, isbn[bookIndex]);
            strcpy(items[itemCount].title, bookTitle[bookIndex]);
            items[itemCount].price = retail[bookIndex];
            items[itemCount].qty = qty;
            items[itemCount].itemSubtotal = retail[bookIndex] * qty;
            itemCount++;
            
            cout << "\nAre there other titles being purchased? (Y/N): ";
            cin >> anotherBook;
            cin.ignore();
        } while (toupper(anotherBook) == 'Y' && itemCount < MAX_BOOKS);
        
        if (itemCount > 0) {
            cout << "\n\n";
            cout << "       Serendipity Booksellers\n\n";
            cout << "Date: " << date << "\n\n";
            
            cout << "Qty" << "\t" << "ISBN" << "\t\t" << "Title" << "\t\t\t\t" << "Price" << "\t\t" << "Subtotal\n";
            cout << "_______________________________________________________________________________\n\n";
            
            for (int i = 0; i < itemCount; i++) {
                cout << items[i].qty << "\t";
                cout << left << setw(14) << items[i].isbn;
                cout << left << setw(24) << items[i].title;
                cout << right << setw(7) << fixed << setprecision(2) << items[i].price << "\t\t";
                cout << right << setw(12) << fixed << setprecision(2) << items[i].itemSubtotal << endl;
                subtotal += items[i].itemSubtotal;
            }
            
            tax = subtotal * TAX_RATE;
            total = subtotal + tax;
            
            cout << "\n\n";
            cout << right << setw(9) << " " << "Subtotal" << right << setw(61) << fixed << setprecision(2) << subtotal << endl;
            cout << right << setw(14) << " " << "Tax" << right << setw(56) << fixed << setprecision(2) << tax << endl;
            cout << right << setw(12) << " " << "Total" << right << setw(58) << fixed << setprecision(2) << total << endl;
            
            cout << "\nThank You for Shopping at Serendipity!\n";
        }
        
        cout << "\nDo you want to process another transaction? (Y/N): ";
        cin >> continueTransaction;
        cin.ignore();
    } while (toupper(continueTransaction) == 'Y');
}