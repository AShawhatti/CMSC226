/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Did all the inventory reports such as listing, wholesale, retail, quantity, cost and age.
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

void repListing() {
    cout << "Inventory Listing\n\n";
    cout << left << setw(24) << "Title" << setw(14) << "ISBN" 
         << setw(14) << "Author" << setw(14) << "Publisher" 
         << setw(12) << "Date Added" << setw(6) << "Qty" 
         << setw(10) << "Wholesale" << setw(10) << "Retail" << endl;
    cout << string(104,'_') << endl;
    for(int i = 0; i < MAX_BOOKS; i++)
        if(bookTitle[i] != "")
            cout << left << setw(24) << bookTitle[i] 
                 << setw(14) << isbn[i] 
                 << setw(14) << author[i] 
                 << setw(14) << publisher[i] 
                 << setw(12) << dateAdded[i] 
                 << setw(6) << qtyOnHand[i] 
                 << setw(10) << fixed << setprecision(2) << wholesale[i] 
                 << setw(10) << fixed << setprecision(2) << retail[i] << endl;
}

void repWholesale() {
    double total = 0;
    cout << "Inventory Wholesale Value\n\n";
    cout << left << setw(24) << "Title" << setw(14) << "ISBN" 
         << setw(6) << "Qty" << setw(10) << "Wholesale" << endl;
    cout << string(54,'_') << endl;
    for(int i = 0; i < MAX_BOOKS; i++)
        if(bookTitle[i] != "") {
            cout << left << setw(24) << bookTitle[i] 
                 << setw(14) << isbn[i] 
                 << setw(6) << qtyOnHand[i] 
                 << setw(10) << fixed << setprecision(2) << wholesale[i] << endl;
            total += qtyOnHand[i]*wholesale[i];
        }
    cout << "\nTotal Wholesale Value: " << fixed << setprecision(2) << total << endl;
}

void repRetail() {
    double total = 0;
    cout << "Inventory Retail Value\n\n";
    cout << left << setw(24) << "Title" << setw(14) << "ISBN" 
         << setw(6) << "Qty" << setw(10) << "Retail" << endl;
    cout << string(54,'_') << endl;
    for(int i = 0; i < MAX_BOOKS; i++)
        if(bookTitle[i] != "") {
            cout << left << setw(24) << bookTitle[i] 
                 << setw(14) << isbn[i] 
                 << setw(6) << qtyOnHand[i] 
                 << setw(10) << fixed << setprecision(2) << retail[i] << endl;
            total += qtyOnHand[i]*retail[i];
        }
    cout << "\nTotal Retail Value: " << fixed << setprecision(2) << total << endl;
}

void repQty() {
    int* ptr[MAX_BOOKS];
    int count = 0;
    for(int i = 0; i < MAX_BOOKS; i++)
        if(bookTitle[i] != "") ptr[count++] = &qtyOnHand[i];

    for(int i = 0; i < count-1; i++)
        for(int j = i+1; j < count; j++)
            if(*ptr[i] < *ptr[j]) swap(ptr[i], ptr[j]);

    cout << "Inventory Sorted by Quantity\n\n";
    cout << left << setw(24) << "Title" << setw(14) << "ISBN" << setw(6) << "Qty" << endl;
    cout << string(44,'_') << endl;
    for(int i = 0; i < count; i++)
        for(int j = 0; j < MAX_BOOKS; j++)
            if(&qtyOnHand[j] == ptr[i])
                cout << left << setw(24) << bookTitle[j] 
                     << setw(14) << isbn[j] 
                     << setw(6) << qtyOnHand[j] << endl;
}

void repCost() {
    double* ptr[MAX_BOOKS];
    int count = 0;
    for(int i = 0; i < MAX_BOOKS; i++)
        if(bookTitle[i] != "") ptr[count++] = &wholesale[i];

    for(int i = 0; i < count-1; i++)
        for(int j = i+1; j < count; j++)
            if(*ptr[i] < *ptr[j]) swap(ptr[i], ptr[j]);

    cout << "Inventory Sorted by Wholesale Cost\n\n";
    cout << left << setw(24) << "Title" << setw(14) << "ISBN" 
         << setw(6) << "Qty" << setw(10) << "Wholesale" << endl;
    cout << string(54,'_') << endl;
    for(int i = 0; i < count; i++)
        for(int j = 0; j < MAX_BOOKS; j++)
            if(&wholesale[j] == ptr[i])
                cout << left << setw(24) << bookTitle[j] 
                     << setw(14) << isbn[j] 
                     << setw(6) << qtyOnHand[j] 
                     << setw(10) << fixed << setprecision(2) << wholesale[j] << endl;
}

void repAge() {
    string* ptr[MAX_BOOKS];
    int count = 0;
    for(int i = 0; i < MAX_BOOKS; i++)
        if(bookTitle[i] != "") ptr[count++] = &dateAdded[i];

    for(int i = 0; i < count-1; i++)
        for(int j = i+1; j < count; j++)
            if(*ptr[i] < *ptr[j]) swap(ptr[i], ptr[j]);

    cout << "Inventory Sorted by Date Added\n\n";
    cout << left << setw(24) << "Title" << setw(14) << "ISBN" 
         << setw(6) << "Qty" << setw(12) << "Date Added" << endl;
    cout << string(56,'_') << endl;
    for(int i = 0; i < count; i++)
        for(int j = 0; j < MAX_BOOKS; j++)
            if(&dateAdded[j] == ptr[i])
                cout << left << setw(24) << bookTitle[j] 
                     << setw(14) << isbn[j] 
                     << setw(6) << qtyOnHand[j] 
                     << setw(12) << dateAdded[j] << endl;
}

void reports() {
    int choice;
    do {
        cout << "Serendipity Booksellers\nReports\n";
        cout << "1. Inventory Listing\n2. Inventory Wholesale Value\n3. Inventory Retail Value\n";
        cout << "4. Listing by Quantity\n5. Listing by Cost\n6. Listing by Age\n7. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        while(choice < 1 || choice > 7) cin >> choice;
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
