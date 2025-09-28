/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Actions to be performed on the book
 * Due: 9/28/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Hassan Shawhatti
 */


#include <iostream>
using namespace std;
int main()
{ 
    //Actions to be performed on the book
    int choice;
    do{
    cout << "Serendipity Booksellers" << endl;
    cout << "       Inventory Database" << endl;
    cout << "1. LookUp a Book" << endl;
    cout << "2. Edit a Book's Record" << endl;
    cout << "3. Delete a Book" << endl;
    cout << "4. Return to the Main Menu" << endl;
    cout << endl;
    cout << "Enter your Choice: \n";
    cin >> choice;
    
    while (choice < 1 || choice > 4){
         cout << "Invalid Choice" << endl;
         cin >> choice;
     }
     switch (choice){
        case 1:
            cout << "LookUp a Book" << endl;
            break;
        case 2:
            cout << "Edit a Book's Record" << endl;
            break;
        case 3:
            cout << "Delete a Book" << endl;
            break;
        case 4:
            cout << "Return to the Main Menu" << endl;
            break;
     }
    }while (choice != 4);
    return 0;
}