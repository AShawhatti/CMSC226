/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Handles the Cashier Module, calculating totals, tax, and printing receipts for book sales.
 * Due: 10/12/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Hassan Shawhatti
 */


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void cashier() {
    string Date, ISBN, Title;
    int Qty;
    double Price;
    const double Tax_Rate = 0.06;
    char Repetition;
    do {
        cout << "Serendipity Booksellers\nCashier Module\n";
        cout << "Date: "; cin >> Date;
        cout << "Quantity of Book: "; cin >> Qty;
        cout << "ISBN: "; cin >> ISBN;
        cin.ignore();
        cout << "Title: "; getline(cin, Title);
        cout << "Price: "; cin >> Price;
        double subtotal = Qty * Price;
        double Tax = subtotal * Tax_Rate;
        double Total = subtotal + Tax;
        cout << "\nSerendipity Booksellers\n";
        cout << "Date: " << Date << "\n\n";
        cout << left << setw(5) << "Qty" << left << setw(14) << "ISBN"
             << left << setw(24) << "Title" << right << setw(7) << "Price"
             << right << setw(12) << "Subtotal\n";
        cout << "______________________________________________________________\n";
        cout << left << setw(5) << Qty << left << setw(14) << ISBN
             << left << setw(24) << Title << right << setw(7) << fixed << setprecision(2) << Price
             << right << setw(12) << fixed << setprecision(2) << subtotal << endl;
        cout << setw(25) << "Subtotal" << setw(15) << subtotal << endl
             << setw(25) << "Tax" << setw(15) << Tax << endl
             << setw(25) << "Total" << setw(15) << Total << endl << endl;
        cout << "Do you buy a book again at Serendipity? (Y/N): ";
        cin >> Repetition;
    } while(Repetition == 'Y' || Repetition == 'y');
    cout << "Thank you for Shopping at Serendipity!\n";
}
