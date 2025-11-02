/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi 
 * Description: Book operations to see what you want to do the books.
 * Due: 11/2/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include "invmenu.h"
#include "bookinfo.h"
#include "mainmenu.h"
using namespace std;

void invMenu() {
    int choice;
    
    do {
        cout << "\n  Serendipity Booksellers\n";
        cout << "    Inventory Database\n\n";
        cout << "  1. Look Up a Book\n";
        cout << "  2. Add a Book\n";
        cout << "  3. Edit a Book's Record\n";
        cout << "  4. Delete a Book\n";
        cout << "  5. Return to the Main Menu\n\n";
        cout << "  Enter Your Choice: ";
        cin >> choice;
        cin.ignore();
        
        while (choice < 1 || choice > 5) {
            cout << "\n  Please enter a number in the range 1 - 5.\n";
            cout << "  Enter Your Choice: ";
            cin >> choice;
            cin.ignore();
        }
        
        switch (choice) {
            case 1:
                lookUpBook();
                break;
            case 2:
                addBook();
                break;
            case 3:
                editBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                break;
        }
    } while (choice != 5);
}

void lookUpBook() {
    char searchTitle[TITLE_SIZE];
    bool found = false;
    
    cout << "\nEnter part of the book title: ";
    cin.getline(searchTitle, TITLE_SIZE);
    strUpper(searchTitle);
    
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (bookTitle[i][0] != '\0' && strstr(bookTitle[i], searchTitle) != NULL) {
            cout << "\nBook found: " << bookTitle[i] << endl;
            cout << "Is this the book you are looking for? (Y/N): ";
            char response;
            cin >> response;
            cin.ignore();
            
            if (toupper(response) == 'Y') {
                bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i]);
                found = true;
                break;
            }
        }
    }
    
    if (!found) {
        cout << "\nBook not found in inventory.\n";
    }
}

void addBook() {
    int emptySlot = -1;
    
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (bookTitle[i][0] == '\0') {
            emptySlot = i;
            break;
        }
    }
    
    if (emptySlot == -1) {
        cout << "\nInventory is full. Cannot add more books.\n";
        return;
    }
    
    cout << "\nBook Title: ";
    cin.getline(bookTitle[emptySlot], TITLE_SIZE);
    strUpper(bookTitle[emptySlot]);
    
    cout << "ISBN Number: ";
    cin.getline(isbn[emptySlot], ISBN_SIZE);
    strUpper(isbn[emptySlot]);
    
    cout << "Author's Name: ";
    cin.getline(author[emptySlot], AUTHOR_SIZE);
    strUpper(author[emptySlot]);
    
    cout << "Publisher's Name: ";
    cin.getline(publisher[emptySlot], PUBLISHER_SIZE);
    strUpper(publisher[emptySlot]);
    
    cout << "Date Added (MM-DD-YYYY): ";
    cin.getline(dateAdded[emptySlot], DATE_SIZE);
    
    cout << "Quantity: ";
    cin >> qtyOnHand[emptySlot];
    
    cout << "Wholesale Cost: ";
    cin >> wholesale[emptySlot];
    
    cout << "Retail Price: ";
    cin >> retail[emptySlot];
    cin.ignore();
    
    cout << "\nBook added successfully.\n";
}

void editBook() {
    char searchTitle[TITLE_SIZE];
    bool found = false;
    
    cout << "\nEnter part of the book title: ";
    cin.getline(searchTitle, TITLE_SIZE);
    strUpper(searchTitle);
    
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (bookTitle[i][0] != '\0' && strstr(bookTitle[i], searchTitle) != NULL) {
            cout << "\nBook found: " << bookTitle[i] << endl;
            cout << "Is this the book you want to edit? (Y/N): ";
            char response;
            cin >> response;
            cin.ignore();
            
            if (toupper(response) == 'Y') {
                bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i]);
                
                cout << "\nWhich field do you want to change?\n";
                cout << "1. Title\n";
                cout << "2. ISBN\n";
                cout << "3. Author\n";
                cout << "4. Publisher\n";
                cout << "5. Date Added\n";
                cout << "6. Quantity\n";
                cout << "7. Wholesale Cost\n";
                cout << "8. Retail Price\n";
                cout << "Enter choice: ";
                
                int fieldChoice;
                cin >> fieldChoice;
                cin.ignore();
                
                switch (fieldChoice) {
                    case 1:
                        cout << "New Title: ";
                        cin.getline(bookTitle[i], TITLE_SIZE);
                        strUpper(bookTitle[i]);
                        break;
                    case 2:
                        cout << "New ISBN: ";
                        cin.getline(isbn[i], ISBN_SIZE);
                        strUpper(isbn[i]);
                        break;
                    case 3:
                        cout << "New Author: ";
                        cin.getline(author[i], AUTHOR_SIZE);
                        strUpper(author[i]);
                        break;
                    case 4:
                        cout << "New Publisher: ";
                        cin.getline(publisher[i], PUBLISHER_SIZE);
                        strUpper(publisher[i]);
                        break;
                    case 5:
                        cout << "New Date (MM-DD-YYYY): ";
                        cin.getline(dateAdded[i], DATE_SIZE);
                        break;
                    case 6:
                        cout << "New Quantity: ";
                        cin >> qtyOnHand[i];
                        cin.ignore();
                        break;
                    case 7:
                        cout << "New Wholesale Cost: ";
                        cin >> wholesale[i];
                        cin.ignore();
                        break;
                    case 8:
                        cout << "New Retail Price: ";
                        cin >> retail[i];
                        cin.ignore();
                        break;
                }
                
                cout << "\nBook updated successfully.\n";
                found = true;
                break;
            }
        }
    }
    
    if (!found) {
        cout << "\nBook not found in inventory.\n";
    }
}

void deleteBook() {
    char searchTitle[TITLE_SIZE];
    bool found = false;
    
    cout << "\nEnter part of the book title: ";
    cin.getline(searchTitle, TITLE_SIZE);
    strUpper(searchTitle);
    
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (bookTitle[i][0] != '\0' && strstr(bookTitle[i], searchTitle) != NULL) {
            cout << "\nBook found: " << bookTitle[i] << endl;
            cout << "Is this the book you want to delete? (Y/N): ";
            char response;
            cin >> response;
            cin.ignore();
            
            if (toupper(response) == 'Y') {
                bookInfo(isbn[i], bookTitle[i], author[i], publisher[i], dateAdded[i], qtyOnHand[i], wholesale[i], retail[i]);
                
                cout << "\nAre you sure you want to delete this book? (Y/N): ";
                char confirm;
                cin >> confirm;
                cin.ignore();
                
                if (toupper(confirm) == 'Y') {
                    bookTitle[i][0] = '\0';
                    isbn[i][0] = '\0';
                    author[i][0] = '\0';
                    publisher[i][0] = '\0';
                    dateAdded[i][0] = '\0';
                    qtyOnHand[i] = 0;
                    wholesale[i] = 0.0;
                    retail[i] = 0.0;
                    
                    cout << "\nBook deleted successfully.\n";
                }
                found = true;
                break;
            }
        }
    }
    
    if (!found) {
        cout << "\nBook not found in inventory.\n";
    }
}