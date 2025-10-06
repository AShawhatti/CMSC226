/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Added and using functions for deciding which report you want
 * Due: 10/05/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Hassan Shawhatti
 */


#include <iostream>
using namespace std;

void reportsListing()   { cout << "You clicked on Inventory Listing." << endl; }
void reportsWholesaleValue() { cout << "You clicked on Inventory Wholesale Value." << endl; }
void reportsRetailValue()    { cout << "You clicked on Inventory Retail Value." << endl; }
void reportsQty()       { cout << "You clicked on Listing By Quantity." << endl; }
void reportsCost()      { cout << "You clicked on Listing By Cost." << endl; }
void reportsAge()       { cout << "You clicked on Listing By Age." << endl; }
void reports()
{
    
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
     
     
     while (choice < 1 || choice > 7){
         cout << "Invalid Choice" << endl;
         cin >> choice;
     }

     switch (choice) {
            case 1: reportsListing(); break;
            case 2: reportsWholesaleValue(); break;
            case 3: reportsRetailValue(); break;
            case 4: reportsQty(); break;
            case 5: reportsCost(); break;
            case 6: reportsAge(); break;
            case 7: cout << "Returning to Main Menu" << endl; break;
        }
 }while (choice != 7); 
}