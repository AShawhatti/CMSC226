/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi 
 * Description: six different analysis reports with sorting.    
 * Due: 11/2/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "reports.h"
#include "mainmenu.h"
using namespace std;

void reports() {
    int choice;
    
    do {
        cout << "\n  Serendipity Booksellers\n";
        cout << "         Reports\n\n";
        cout << "  1. Inventory Listing\n";
        cout << "  2. Inventory Wholesale Value\n";
        cout << "  3. Inventory Retail Value\n";
        cout << "  4. Listing by Quantity\n";
        cout << "  5. Listing by Cost\n";
        cout << "  6. Listing by Age\n";
        cout << "  7. Return to the Main Menu\n\n";
        cout << "  Enter Your Choice: ";
        cin >> choice;
        cin.ignore();
        
        while (choice < 1 || choice > 7) {
            cout << "\n  Please enter a number in the range 1 - 7.\n";
            cout << "  Enter Your Choice: ";
            cin >> choice;
            cin.ignore();
        }
        
        switch (choice) {
            case 1:
                repListing();
                break;
            case 2:
                repWholesale();
                break;
            case 3:
                repRetail();
                break;
            case 4:
                repQty();
                break;
            case 5:
                repCost();
                break;
            case 6:
                repAge();
                break;
            case 7:
                break;
        }
    } while (choice != 7);
}

void repListing() {
    cout << "\n       Inventory Listing Report\n\n";
    cout << left << setw(30) << "Title" << setw(15) << "ISBN" << setw(20) << "Author" 
         << setw(20) << "Publisher" << setw(12) << "Date Added" << setw(5) << "Qty" 
         << setw(10) << "Wholesale" << setw(10) << "Retail" << endl;
    cout << "---------------------------------------------------------------------------------";
    cout << "-----------------------------------------------------------------\n";
    
    int count = 0;
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (bookTitle[i][0] != '\0') {
            cout << left << setw(30) << bookTitle[i] << setw(15) << isbn[i] 
                 << setw(20) << author[i] << setw(20) << publisher[i] 
                 << setw(12) << dateAdded[i] << setw(5) << qtyOnHand[i] 
                 << setw(10) << fixed << setprecision(2) << wholesale[i] 
                 << setw(10) << fixed << setprecision(2) << retail[i] << endl;
            count++;
            
            if (count % 20 == 0) {
                cout << "\nPress Enter to continue...";
                cin.get();
            }
        }
    }
    
    if (count == 0) {
        cout << "No books in inventory.\n";
    }
}

void repWholesale() {
    cout << "\n       Inventory Wholesale Value Report\n\n";
    cout << left << setw(30) << "Title" << setw(15) << "ISBN" 
         << setw(10) << "Qty" << setw(15) << "Wholesale" << setw(15) << "Total Value" << endl;
    cout << "--------------------------------------------------------------------------------\n";
    
    double totalWholesaleValue = 0.0;
    int count = 0;
    
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (bookTitle[i][0] != '\0') {
            double itemValue = wholesale[i] * qtyOnHand[i];
            totalWholesaleValue += itemValue;
            
            cout << left << setw(30) << bookTitle[i] << setw(15) << isbn[i] 
                 << setw(10) << qtyOnHand[i] << setw(15) << fixed << setprecision(2) 
                 << wholesale[i] << setw(15) << fixed << setprecision(2) << itemValue << endl;
            count++;
            
            if (count % 20 == 0) {
                cout << "\nPress Enter to continue...";
                cin.get();
            }
        }
    }
    
    cout << "\nTotal Wholesale Value: $" << fixed << setprecision(2) << totalWholesaleValue << endl;
}

void repRetail() {
    cout << "\n       Inventory Retail Value Report\n\n";
    cout << left << setw(30) << "Title" << setw(15) << "ISBN" 
         << setw(10) << "Qty" << setw(15) << "Retail" << setw(15) << "Total Value" << endl;
    cout << "--------------------------------------------------------------------------------\n";
    
    double totalRetailValue = 0.0;
    int count = 0;
    
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (bookTitle[i][0] != '\0') {
            double itemValue = retail[i] * qtyOnHand[i];
            totalRetailValue += itemValue;
            
            cout << left << setw(30) << bookTitle[i] << setw(15) << isbn[i] 
                 << setw(10) << qtyOnHand[i] << setw(15) << fixed << setprecision(2) 
                 << retail[i] << setw(15) << fixed << setprecision(2) << itemValue << endl;
            count++;
            
            if (count % 20 == 0) {
                cout << "\nPress Enter to continue...";
                cin.get();
            }
        }
    }
    
    cout << "\nTotal Retail Value: $" << fixed << setprecision(2) << totalRetailValue << endl;
}

void repQty() {
    int indices[MAX_BOOKS];
    int validCount = 0;
    
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (bookTitle[i][0] != '\0') {
            indices[validCount++] = i;
        }
    }
    
    for (int i = 0; i < validCount - 1; i++) {
        for (int j = 0; j < validCount - i - 1; j++) {
            if (qtyOnHand[indices[j]] < qtyOnHand[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    
    cout << "\n       Listing by Quantity Report\n\n";
    cout << left << setw(30) << "Title" << setw(15) << "ISBN" << setw(10) << "Qty" << endl;
    cout << "--------------------------------------------------------\n";
    
    for (int i = 0; i < validCount; i++) {
        int idx = indices[i];
        cout << left << setw(30) << bookTitle[idx] << setw(15) << isbn[idx] 
             << setw(10) << qtyOnHand[idx] << endl;
        
        if ((i + 1) % 20 == 0) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }
}

void repCost() {
    int indices[MAX_BOOKS];
    int validCount = 0;
    
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (bookTitle[i][0] != '\0') {
            indices[validCount++] = i;
        }
    }
    
    for (int i = 0; i < validCount - 1; i++) {
        for (int j = 0; j < validCount - i - 1; j++) {
            if (wholesale[indices[j]] < wholesale[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    
    cout << "\n       Listing by Cost Report\n\n";
    cout << left << setw(30) << "Title" << setw(15) << "ISBN" 
         << setw(10) << "Qty" << setw(15) << "Wholesale" << endl;
    cout << "-----------------------------------------------------------------------\n";
    
    for (int i = 0; i < validCount; i++) {
        int idx = indices[i];
        cout << left << setw(30) << bookTitle[idx] << setw(15) << isbn[idx] 
             << setw(10) << qtyOnHand[idx] << setw(15) << fixed << setprecision(2) 
             << wholesale[idx] << endl;
        
        if ((i + 1) % 20 == 0) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }
}

void repAge() {
    int indices[MAX_BOOKS];
    int validCount = 0;
    
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (bookTitle[i][0] != '\0') {
            indices[validCount++] = i;
        }
    }
    
    for (int i = 0; i < validCount - 1; i++) {
        for (int j = 0; j < validCount - i - 1; j++) {
            if (strcmp(dateAdded[indices[j]], dateAdded[indices[j + 1]]) > 0) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    cout << "\n       Listing by Age Report\n\n";
    cout << left << setw(30) << "Title" << setw(15) << "ISBN" 
         << setw(10) << "Qty" << setw(15) << "Date Added" << endl;
    cout << "-----------------------------------------------------------------------\n";
    
    for (int i = 0; i < validCount; i++) {
        int idx = indices[i];
        cout << left << setw(30) << bookTitle[idx] << setw(15) << isbn[idx] 
             << setw(10) << qtyOnHand[idx] << setw(15) << dateAdded[idx] << endl;
        
        if ((i + 1) % 20 == 0) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }
}