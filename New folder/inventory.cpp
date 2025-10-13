#include <iostream>
#include <string>
#include "globals.h"
#include "functionPrototypes.h"
using namespace std;

void addBook() {
    int index = -1;
    for(int i = 0; i < MAX_BOOKS; i++)
        if(bookTitle[i] == "") { index = i; break; }
    if(index == -1) { cout << "Inventory full.\n"; return; }

    cin.ignore();
    cout << "Enter Book Title: "; getline(cin, bookTitle[index]);
    cout << "Enter ISBN: "; getline(cin, isbn[index]);
    cout << "Enter Author: "; getline(cin, author[index]);
    cout << "Enter Publisher: "; getline(cin, publisher[index]);
    cout << "Enter Date Added (MM-DD-YYYY): "; getline(cin, dateAdded[index]);
    cout << "Enter Quantity On Hand: "; cin >> qtyOnHand[index];
    cout << "Enter Wholesale Price: "; cin >> wholesale[index];
    cout << "Enter Retail Price: "; cin >> retail[index];
    cin.ignore();
    cout << "Book added successfully.\n";
}

void lookUpBook() {
    cin.ignore();
    string title;
    cout << "Enter Book Title to look up: "; getline(cin, title);
    int index = -1;
    for(int i = 0; i < MAX_BOOKS; i++)
        if(bookTitle[i] == title) { index = i; break; }
    if(index == -1) { cout << "Book not in inventory.\n"; return; }
    bookInfo(isbn[index], bookTitle[index], author[index], publisher[index],
             dateAdded[index], qtyOnHand[index], wholesale[index], retail[index]);
}

void editBook() {
    cin.ignore();
    string title;
    cout << "Enter Book Title to edit: "; getline(cin, title);
    int index = -1;
    for(int i = 0; i < MAX_BOOKS; i++)
        if(bookTitle[i] == title) { index = i; break; }
    if(index == -1) { cout << "Book not in inventory.\n"; return; }
    bookInfo(isbn[index], bookTitle[index], author[index], publisher[index],
             dateAdded[index], qtyOnHand[index], wholesale[index], retail[index]);

    int choice;
    cout << "Select field to edit (1-Title, 2-ISBN, 3-Author, 4-Publisher, 5-Date, 6-Qty, 7-Wholesale, 8-Retail): ";
    cin >> choice; cin.ignore();
    switch(choice) {
        case 1: getline(cin, bookTitle[index]); break;
        case 2: getline(cin, isbn[index]); break;
        case 3: getline(cin, author[index]); break;
        case 4: getline(cin, publisher[index]); break;
        case 5: getline(cin, dateAdded[index]); break;
        case 6: cin >> qtyOnHand[index]; break;
        case 7: cin >> wholesale[index]; break;
        case 8: cin >> retail[index]; break;
    }
    cin.ignore();
    cout << "Book updated successfully.\n";
}

void deleteBook() {
    cin.ignore();
    string title;
    cout << "Enter Book Title to delete: "; getline(cin, title);
    int index = -1;
    for(int i = 0; i < MAX_BOOKS; i++)
        if(bookTitle[i] == title) { index = i; break; }
    if(index == -1) { cout << "Book not in inventory.\n"; return; }
    bookInfo(isbn[index], bookTitle[index], author[index], publisher[index],
             dateAdded[index], qtyOnHand[index], wholesale[index], retail[index]);
    char confirm;
    cout << "Are you sure you want to delete? (Y/N): "; cin >> confirm;
    if(confirm == 'Y' || confirm == 'y') {
        bookTitle[index] = ""; isbn[index] = ""; author[index] = "";
        publisher[index] = ""; dateAdded[index] = ""; qtyOnHand[index]=0;
        wholesale[index]=0; retail[index]=0;
        cout << "Book deleted successfully.\n";
    } else cout << "Deletion canceled.\n";
}
