/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Places to go insde the program
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
    
    int choice;
    do{
        //Places to go inside the program
    cout << "Serendipity Booksellers" << endl;
    cout << "       Main Menu" << endl;
    cout << "1. Cashier Module" << endl;
    cout << "2. Inventory Database Module" << endl;
    cout << "3. Report Module" << endl;
    cout << "4. Exit" << endl;
    cout << " " << endl;
    cout << "Enter your Choice: \n";
    cin >> choice;

    while(choice < 1 || choice > 4){
        cout << "Invalid Choice" << endl;
        cin >> choice;
    }
    
    switch(choice){
        case 1:
            cout << "Cashier Module" << endl;
            break;
        case 2:
            cout << "Inventory Database Module" << endl;
            break;
        case 3:
            cout << "Report Module" << endl;
            break;
        case 4:
            cout << "Exit" << endl;
            break;
    }
    }while (choice != 4);

    

    
    return 0;
}