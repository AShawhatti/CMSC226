/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Does the same thing as the other one we just added functions for the cout instead of hard coding it
 * Due: 10/19/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Hassan Shawhatti
 */


#include <iostream>
#include <iomanip>
#include <algorithm>
#include "globals.h"
#include "functionPrototypes.h"
using namespace std;

void repListing() {
    cout << "Serendipity Booksellers - Inventory Listing\n";
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (bookTitle[i] != "") {
            cout << left << setw(20) << bookTitle[i] << setw(15) << isbn[i]
                 << setw(15) << author[i] << setw(15) << publisher[i]
                 << setw(15) << dateAdded[i] << setw(10) << qtyOnHand[i]
                 << setw(10) << wholesale[i] << setw(10) << retail[i] << endl;
        }
    }
}

void repWholesale() {
    double total = 0;
    cout << "Serendipity Booksellers - Wholesale Report\n";
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (bookTitle[i] != "") {
            cout << left << setw(20) << bookTitle[i] << setw(15) << isbn[i]
                 << setw(10) << qtyOnHand[i] << setw(10) << wholesale[i] << endl;
            total += qtyOnHand[i] * wholesale[i];
        }
    }
    cout << "Total Wholesale Value: " << total << endl;
}

void repRetail() {
    double total = 0;
    cout << "Serendipity Booksellers - Retail Report\n";
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (bookTitle[i] != "") {
            cout << left << setw(20) << bookTitle[i] << setw(15) << isbn[i]
                 << setw(10) << qtyOnHand[i] << setw(10) << retail[i] << endl;
            total += qtyOnHand[i] * retail[i];
        }
    }
    cout << "Total Retail Value: " << total << endl;
}

void repQty() {
    int* index = new int[MAX_BOOKS];
    for (int i = 0; i < MAX_BOOKS; i++) index[i] = i;

    sort(index, index + MAX_BOOKS, [](int a, int b) {
        return qtyOnHand[a] > qtyOnHand[b];
    });

    cout << "Serendipity Booksellers - Listing by Quantity\n";
    for (int i = 0; i < MAX_BOOKS; i++) {
        int j = index[i];
        if (bookTitle[j] != "")
            cout << left << setw(20) << bookTitle[j] << setw(15) << isbn[j]
                 << setw(10) << qtyOnHand[j] << endl;
    }
    delete[] index;
}

void repCost() {
    int* index = new int[MAX_BOOKS];
    for (int i = 0; i < MAX_BOOKS; i++) index[i] = i;

    sort(index, index + MAX_BOOKS, [](int a, int b) {
        return wholesale[a] > wholesale[b];
    });

    cout << "Serendipity Booksellers - Listing by Cost\n";
    for (int i = 0; i < MAX_BOOKS; i++) {
        int j = index[i];
        if (bookTitle[j] != "")
            cout << left << setw(20) << bookTitle[j] << setw(15) << isbn[j]
                 << setw(10) << qtyOnHand[j] << setw(10) << wholesale[j] << endl;
    }
    delete[] index;
}

void repAge() {
    int* index = new int[MAX_BOOKS];
    for (int i = 0; i < MAX_BOOKS; i++) index[i] = i;

    sort(index, index + MAX_BOOKS, [](int a, int b) {
        return dateAdded[a] > dateAdded[b];
    });

    cout << "Serendipity Booksellers - Listing by Age\n";
    for (int i = 0; i < MAX_BOOKS; i++) {
        int j = index[i];
        if (bookTitle[j] != "")
            cout << left << setw(20) << bookTitle[j] << setw(15) << isbn[j]
                 << setw(10) << qtyOnHand[j] << setw(15) << dateAdded[j] << endl;
    }
    delete[] index;
}

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
