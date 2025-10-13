/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Displays the Inventory Database menu and calls the functions to look up, add, edit, or delete books.
 * Due: 10/12/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Hassan Shawhatti
 */


#include <iostream>
#include "functionPrototypes.h"
using namespace std;

void invMenu()
{
    int choice;
    do {
        cout << "Serendipity Booksellers\n";
        cout << "       Inventory Database\n";
        cout << "1. Look Up a Book\n";
        cout << "2. Add a Book\n";
        cout << "3. Edit a Book\n";
        cout << "4. Delete a Book\n";
        cout << "5. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        while (choice < 1 || choice > 5) {
            cout << "Invalid choice. Enter again: ";
            cin >> choice;
        }

        switch (choice) {
            case 1: lookUpBook(); break;
            case 2: addBook(); break;
            case 3: editBook(); break;
            case 4: deleteBook(); break;
            case 5: break;
        }
    } while (choice != 5);
}
