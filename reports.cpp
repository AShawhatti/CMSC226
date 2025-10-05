/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Does the same thing as the other one we just added functions for the cout instead of hard coding it
 * Due: 10/05/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */


#include <iostream>
using namespace std;

void repListing()   { cout << "You selected Inventory Listing." << endl; }
void repWholesale() { cout << "You selected Inventory Wholesale Value." << endl; }
void repRetail()    { cout << "You selected Inventory Retail Value." << endl; }
void repQty()       { cout << "You selected Listing By Quantity." << endl; }
void repCost()      { cout << "You selected Listing By Cost." << endl; }
void repAge()       { cout << "You selected Listing By Age." << endl; }
void reports()
{
    //Self Explaining
    int choice;
    do{
    cout << "Serendipity Booksellers" << endl;
    cout << "    Reports" << endl;
    cout << "1. Inventory Listing" << endl;
    cout << "2. Inventory Wholesale Value" << endl;
    cout << "3. Inventory Retail Value" << endl;
    cout << "4. Listing by Quantity" << endl;
    cout << "5. Listing by Cost" << endl;
    cout << "6. Listing by Age" << endl;
    cout << "7. Return to the Main Menu" << endl;
    cout << endl;
    cout << "Enter your Choice: \n";
     cin >> choice;
     
     //whether the choice is valid
     while (choice < 1 || choice > 7){
         cout << "Invalid Choice" << endl;
         cin >> choice;
     }

     switch (choice) {
            case 1: repListing(); break;
            case 2: repWholesale(); break;
            case 3: repRetail(); break;
            case 4: repQty(); break;
            case 5: repCost(); break;
            case 6: repAge(); break;
            case 7: cout << "Returning to Main Menu" << endl; break;
        }
 }while (choice != 7); 
}