/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi 
 * Description: Handles buying and selling of books and shows a receipt if sucessfull. 
 * Due: 11/2/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Hassan Shawhatti
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "cashier.h"
#include "mainmenu.h"
using namespace std;

const double SALES_TAX = 0.06;

void cashier() {
    char processAnother;
    bool continueProcessing = true;
    
    while (continueProcessing) {
        char transactionDate[20];
        char isbnLookup[ISBN_SIZE];
        int quantityPurchased;
        double runningSubtotal = 0.0;
        double salesTaxAmount = 0.0;
        double grandTotal = 0.0;
        int numberOfItems = 0;
        
        struct PurchasedItem {
            char itemISBN[ISBN_SIZE];
            char itemTitle[TITLE_SIZE];
            double unitPrice;
            int quantityBought;
            double lineTotal;
        };
        
        PurchasedItem purchaseList[MAX_BOOKS];
        
        cout << "\n\nSerendipity Booksellers\n";
        cout << "         Cashier Module\n\n";
        cout << "Date: ";
        cin.getline(transactionDate, 20);
        
        char addMoreBooks;
        bool keepAdding = true;
        
        while (keepAdding && numberOfItems < MAX_BOOKS) {
            cout << "\nISBN: ";
            cin.getline(isbnLookup, ISBN_SIZE);
            
            strUpper(isbnLookup);
            
            int foundAt = -1;
            int searchIndex = 0;
            while (searchIndex < MAX_BOOKS && foundAt == -1) {
                if (strcmp(isbn[searchIndex], isbnLookup) == 0) {
                    foundAt = searchIndex;
                }
                searchIndex++;
            }
            
            if (foundAt == -1) {
                cout << "ISBN not found in inventory.\n";
                cout << "Do you want to re-enter the ISBN? (Y/N): ";
                char retryChoice;
                cin >> retryChoice;
                cin.ignore();
                if (toupper(retryChoice) != 'Y') {
                    keepAdding = false;
                }
                continue;
            }
            
            cout << "Title: " << bookTitle[foundAt] << endl;
            cout << "Price: $" << fixed << setprecision(2) << retail[foundAt] << endl;
            cout << "Quantity: ";
            cin >> quantityPurchased;
            cin.ignore();
            
            if (quantityPurchased > qtyOnHand[foundAt]) {
                cout << "Not enough copies in stock. Only " << qtyOnHand[foundAt] << " available.\n";
                continue;
            }
            
            qtyOnHand[foundAt] = qtyOnHand[foundAt] - quantityPurchased;
            
            strcpy(purchaseList[numberOfItems].itemISBN, isbn[foundAt]);
            strcpy(purchaseList[numberOfItems].itemTitle, bookTitle[foundAt]);
            purchaseList[numberOfItems].unitPrice = retail[foundAt];
            purchaseList[numberOfItems].quantityBought = quantityPurchased;
            purchaseList[numberOfItems].lineTotal = retail[foundAt] * quantityPurchased;
            numberOfItems++;
            
            cout << "\nAre there other titles being purchased? (Y/N): ";
            cin >> addMoreBooks;
            cin.ignore();
            if (toupper(addMoreBooks) != 'Y') {
                keepAdding = false;
            }
        }
        
        if (numberOfItems > 0) {
            cout << "\n\n";
            cout << "       Serendipity Booksellers\n\n";
            cout << "Date: " << transactionDate << "\n\n";
            
            cout << "Qty" << "\t" << "ISBN" << "\t\t" << "Title" << "\t\t\t\t" << "Price" << "\t\t" << "Subtotal\n";
            cout << "_______________________________________________________________________________\n\n";
            
            int displayIndex = 0;
            while (displayIndex < numberOfItems) {
                cout << purchaseList[displayIndex].quantityBought << "\t";
                cout << left << setw(14) << purchaseList[displayIndex].itemISBN;
                cout << left << setw(24) << purchaseList[displayIndex].itemTitle;
                cout << right << setw(7) << fixed << setprecision(2) << purchaseList[displayIndex].unitPrice << "\t\t";
                cout << right << setw(12) << fixed << setprecision(2) << purchaseList[displayIndex].lineTotal << endl;
                runningSubtotal = runningSubtotal + purchaseList[displayIndex].lineTotal;
                displayIndex++;
            }
            
            salesTaxAmount = runningSubtotal * SALES_TAX;
            grandTotal = runningSubtotal + salesTaxAmount;
            
            cout << "\n\n";
            cout << right << setw(9) << " " << "Subtotal" << right << setw(61) << fixed << setprecision(2) << runningSubtotal << endl;
            cout << right << setw(14) << " " << "Tax" << right << setw(56) << fixed << setprecision(2) << salesTaxAmount << endl;
            cout << right << setw(12) << " " << "Total" << right << setw(58) << fixed << setprecision(2) << grandTotal << endl;
            
            cout << "\nThank You for Shopping at Serendipity!\n";
        }
        
        cout << "\nDo you want to process another transaction? (Y/N): ";
        cin >> processAnother;
        cin.ignore();
        if (toupper(processAnother) != 'Y') {
            continueProcessing = false;
        }
    }
}