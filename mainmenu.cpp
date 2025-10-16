/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Same thing shows menu validates it then depending on what user did it goes to that module.
 * Due: 10/19/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */

#include <iostream>
#include "functionPrototypes.h"
using namespace std;

int main() {
    int choice;
    do {
        cout << "Serendipity Booksellers\nMain Menu\n";
        cout << "1. Cashier Module\n2. Inventory Database Module\n";
        cout << "3. Report Module\n4. Book Information\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        while(choice < 1 || choice > 5) {
            cout << "Invalid choice. Try again: ";
            cin >> choice;
        }

        switch(choice) {
            case 1: cashier(); break;
            case 2: invMenu(); break;
            case 3: reports(); break;
            case 4: bookInfo("","","","","",0,0,0); break;
            case 5: cout << "Exiting... Goodbye!\n"; break;
        }
    } while(choice != 5);

    return 0;
}
