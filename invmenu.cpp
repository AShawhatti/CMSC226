/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi 
 * Description: Inventory Database to Handle 4 actions for a specific book.
 * Due: 11/2/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Hassan Shawhatti
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include "invmenu.h"
#include "bookinfo.h"
#include "mainmenu.h"
using namespace std;

void invMenu() {
    int menuChoice;
    bool stayInMenu = true;
    
    while (stayInMenu) {
        cout << "\n  Serendipity Booksellers\n";
        cout << "    Inventory Database\n\n";
        cout << "  1. Look Up a Book\n";
        cout << "  2. Add a Book\n";
        cout << "  3. Edit a Book's Record\n";
        cout << "  4. Delete a Book\n";
        cout << "  5. Return to the Main Menu\n\n";
        cout << "  Enter Your Choice: ";
        cin >> menuChoice;
        cin.ignore();
        
        bool inputIsValid = (menuChoice >= 1 && menuChoice <= 5);
        while (!inputIsValid) {
            cout << "\n  Please enter a number in the range 1 - 5.\n";
            cout << "  Enter Your Choice: ";
            cin >> menuChoice;
            cin.ignore();
            inputIsValid = (menuChoice >= 1 && menuChoice <= 5);
        }
        
        if (menuChoice == 1) {
            lookUpBook();
        } else if (menuChoice == 2) {
            addBook();
        } else if (menuChoice == 3) {
            editBook();
        } else if (menuChoice == 4) {
            deleteBook();
        } else {
            stayInMenu = false;
        }
    }
}

void lookUpBook() {
    char partialTitle[TITLE_SIZE];
    bool bookWasFound = false;
    
    cout << "\nEnter part of the book title: ";
    cin.getline(partialTitle, TITLE_SIZE);
    strUpper(partialTitle);
    
    int slot = 0;
    while (slot < MAX_BOOKS) {
        if (bookTitle[slot][0] != '\0') {
            char *matchResult = strstr(bookTitle[slot], partialTitle);
            if (matchResult != NULL) {
                cout << "\nBook found: " << bookTitle[slot] << endl;
                cout << "Is this the book you are looking for? (Y/N): ";
                char userResponse;
                cin >> userResponse;
                cin.ignore();
                
                if (toupper(userResponse) == 'Y') {
                    bookInfo(isbn[slot], bookTitle[slot], author[slot], publisher[slot], 
                            dateAdded[slot], qtyOnHand[slot], wholesale[slot], retail[slot]);
                    bookWasFound = true;
                    slot = MAX_BOOKS;
                }
            }
        }
        slot++;
    }
    
    if (!bookWasFound) {
        cout << "\nBook not found in inventory.\n";
    }
}

void addBook() {
    int availableSlot = -1;
    
    int position = 0;
    while (position < MAX_BOOKS && availableSlot == -1) {
        if (bookTitle[position][0] == '\0') {
            availableSlot = position;
        }
        position++;
    }
    
    if (availableSlot == -1) {
        cout << "\nInventory is full. Cannot add more books.\n";
        return;
    }
    
    cout << "\nBook Title: ";
    cin.getline(bookTitle[availableSlot], TITLE_SIZE);
    strUpper(bookTitle[availableSlot]);
    
    cout << "ISBN Number: ";
    cin.getline(isbn[availableSlot], ISBN_SIZE);
    strUpper(isbn[availableSlot]);
    
    cout << "Author's Name: ";
    cin.getline(author[availableSlot], AUTHOR_SIZE);
    strUpper(author[availableSlot]);
    
    cout << "Publisher's Name: ";
    cin.getline(publisher[availableSlot], PUBLISHER_SIZE);
    strUpper(publisher[availableSlot]);
    
    cout << "Date Added (MM-DD-YYYY): ";
    cin.getline(dateAdded[availableSlot], DATE_SIZE);
    
    cout << "Quantity: ";
    cin >> qtyOnHand[availableSlot];
    
    cout << "Wholesale Cost: ";
    cin >> wholesale[availableSlot];
    
    cout << "Retail Price: ";
    cin >> retail[availableSlot];
    cin.ignore();
    
    cout << "\nBook added successfully.\n";
}

void editBook() {
    char searchString[TITLE_SIZE];
    bool foundMatch = false;
    
    cout << "\nEnter part of the book title: ";
    cin.getline(searchString, TITLE_SIZE);
    strUpper(searchString);
    
    int index = 0;
    while (index < MAX_BOOKS && !foundMatch) {
        if (bookTitle[index][0] != '\0') {
            char *searchResult = strstr(bookTitle[index], searchString);
            if (searchResult != NULL) {
                cout << "\nBook found: " << bookTitle[index] << endl;
                cout << "Is this the book you want to edit? (Y/N): ";
                char answer;
                cin >> answer;
                cin.ignore();
                
                if (toupper(answer) == 'Y') {
                    bookInfo(isbn[index], bookTitle[index], author[index], publisher[index], 
                            dateAdded[index], qtyOnHand[index], wholesale[index], retail[index]);
                    
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
                    
                    int selection;
                    cin >> selection;
                    cin.ignore();
                    
                    if (selection == 1) {
                        cout << "New Title: ";
                        cin.getline(bookTitle[index], TITLE_SIZE);
                        strUpper(bookTitle[index]);
                    } else if (selection == 2) {
                        cout << "New ISBN: ";
                        cin.getline(isbn[index], ISBN_SIZE);
                        strUpper(isbn[index]);
                    } else if (selection == 3) {
                        cout << "New Author: ";
                        cin.getline(author[index], AUTHOR_SIZE);
                        strUpper(author[index]);
                    } else if (selection == 4) {
                        cout << "New Publisher: ";
                        cin.getline(publisher[index], PUBLISHER_SIZE);
                        strUpper(publisher[index]);
                    } else if (selection == 5) {
                        cout << "New Date (MM-DD-YYYY): ";
                        cin.getline(dateAdded[index], DATE_SIZE);
                    } else if (selection == 6) {
                        cout << "New Quantity: ";
                        cin >> qtyOnHand[index];
                        cin.ignore();
                    } else if (selection == 7) {
                        cout << "New Wholesale Cost: ";
                        cin >> wholesale[index];
                        cin.ignore();
                    } else if (selection == 8) {
                        cout << "New Retail Price: ";
                        cin >> retail[index];
                        cin.ignore();
                    }
                    
                    cout << "\nBook updated successfully.\n";
                    foundMatch = true;
                }
            }
        }
        index++;
    }
    
    if (!foundMatch) {
        cout << "\nBook not found in inventory.\n";
    }
}

void deleteBook() {
    char titleSearch[TITLE_SIZE];
    bool recordDeleted = false;
    
    cout << "\nEnter part of the book title: ";
    cin.getline(titleSearch, TITLE_SIZE);
    strUpper(titleSearch);
    
    int currentIndex = 0;
    while (currentIndex < MAX_BOOKS && !recordDeleted) {
        if (bookTitle[currentIndex][0] != '\0') {
            char *match = strstr(bookTitle[currentIndex], titleSearch);
            if (match != NULL) {
                cout << "\nBook found: " << bookTitle[currentIndex] << endl;
                cout << "Is this the book you want to delete? (Y/N): ";
                char userAnswer;
                cin >> userAnswer;
                cin.ignore();
                
                if (toupper(userAnswer) == 'Y') {
                    bookInfo(isbn[currentIndex], bookTitle[currentIndex], author[currentIndex], 
                            publisher[currentIndex], dateAdded[currentIndex], qtyOnHand[currentIndex], 
                            wholesale[currentIndex], retail[currentIndex]);
                    
                    cout << "\nAre you sure you want to delete this book? (Y/N): ";
                    char confirmDelete;
                    cin >> confirmDelete;
                    cin.ignore();
                    
                    if (toupper(confirmDelete) == 'Y') {
                        bookTitle[currentIndex][0] = '\0';
                        isbn[currentIndex][0] = '\0';
                        author[currentIndex][0] = '\0';
                        publisher[currentIndex][0] = '\0';
                        dateAdded[currentIndex][0] = '\0';
                        qtyOnHand[currentIndex] = 0;
                        wholesale[currentIndex] = 0.0;
                        retail[currentIndex] = 0.0;
                        
                        cout << "\nBook deleted successfully.\n";
                    }
                    recordDeleted = true;
                }
            }
        }
        currentIndex++;
    }
    
    if (!recordDeleted) {
        cout << "\nBook not found in inventory.\n";
    }
}