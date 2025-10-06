/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Functions used to do cetain things to the inventory
 * Due: 10/05/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Hassan Shawhatti
 */


#include <iostream>
using namespace std;

void lookUpBook() { cout << "You selected Look Up Book." << endl; }
void addBook()    { cout << "You selected Add Book." << endl; }
void editBook()   { cout << "You selected Edit Book." << endl; }
void deleteBook() { cout << "You selected Delete Book." << endl; }

void invMenu()
{ 
    
    int choice;
    do{
    cout << "Serendipity Booksellers" << endl;
    cout << "       Inventory Database" << endl;
    cout << "1. LookUp a Book" << endl;
    cout << "2. Add a Book Record" << endl;
    cout << "3. Edit a Book's Record" << endl;
    cout << "4. Delete a Book" << endl;
    cout << "5. Return to the Main Menu" << endl;
    cout << endl;
    cout << "Enter your Choice: \n";
    cin >> choice;

     while (choice < 1 || choice > 5){
         cout << "Invalid Choice" << endl;
         cin >> choice;
     }
     switch (choice) {
            case 1: lookUpBook(); break;
            case 2: addBook(); break;
            case 3: editBook(); break;
            case 4: deleteBook(); break;
            case 5: cout << "Returning to Main Menu" << endl; break;
        }
    }while (choice != 5);
}