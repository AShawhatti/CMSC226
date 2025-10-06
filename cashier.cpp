/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Added void cashier instead of int main to it could be called
 * Due: 10/05/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Hassan Shawhatti
 */


#include <iostream>
#include <iomanip>
using namespace std;

void cashier() {
    string Date, ISBN, Title;
    int Qty;
    double Price;
    const double Tax_Rate = 0.06;
    char Repetition;

    do {
        cout << "Serendipity Booksellers" << endl;
        cout << " Cashier Module\n\n";

        cout << "Date: ";
        cin >> Date;
        cout << "Quantity of Book: ";
        cin >> Qty;
        cout << "ISBN: ";
        cin >> ISBN;
        cout << "Title: ";
        cin.ignore();
        getline(cin, Title);
        cout << "Price: ";
        cin >> Price;

        double subtotal = Qty * Price;
        double Tax = subtotal * Tax_Rate;
        double Total = subtotal + Tax;

        cout << "\nSerendipity Booksellers\n\n";
        cout << "Date: " << Date << endl << endl;
        cout << left << setw(5) << "Qty"
             << left << setw(14) << "ISBN"
             << left << setw(24) << "Title"
             << right << setw(7) << "Price"
             << right << setw(12) << "Subtotal" << endl;
        cout << "________________________________________________________________\n";
        cout << left << setw(5) << Qty
             << left << setw(14) << ISBN
             << left << setw(24) << Title
             << right << setw(7) << fixed << setprecision(2) << Price
             << right << setw(12) << fixed << setprecision(2) << subtotal << endl;
        cout << endl
             << setw(25) << "Subtotal" << setw(15) << subtotal << endl
             << setw(25) << "Tax" << setw(15) << Tax << endl
             << setw(25) << "Total" << setw(15) << Total << endl;
        cout << endl;

        cout << "Do you buy a book again at Serendipity? (Y/N): ";
        cin >> Repetition;
    } while (Repetition == 'y' || Repetition == 'Y');

    cout << "Thank you for Shopping at Serendipity!\n";
}
