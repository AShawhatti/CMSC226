/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: called the function prototypes and then used them instead of printing the sentence that was hard coded. Now we can actually connect to the other files.
 * Due: 10/05/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


void cashier();
void invMenu();
void bookInfo();
void reports();

int main() {
    int choice;

    do {
        cout << "Serendipity Booksellers" << endl;
        cout << "       Main Menu" << endl;
        cout << "1. Cashier Module" << endl;
        cout << "2. Inventory Database Module" << endl;
        cout << "3. Report Module" << endl;
        cout << "4. Book Information" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your Choice: ";
        cin >> choice;
         
            while (choice < 1 || choice > 5) {
            cout << "Invalid choice. Try again: ";
            cin >> choice;
        }
        switch (choice) {
            case 1: cashier(); break;
            case 2: invMenu(); break;
            case 3: reports(); break;
            case 4: bookInfo(); break;
            case 5: cout << "Exiting... Goodbye!\n"; break;
        }
    } while (choice != 5);

    return 0;
}

