/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Brief description of this file/module
 * Due: 9/21/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */


#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //Making the varaibles
    string Date, ISBN, Title;
    int Qty;
    double Price;
    const double Tax_Rate = 0.06;


    cout << "Serendipity Booksellers" << endl;
    cout << " Cashier Module" << endl;
    cout << " " << endl;
    //The user Input to Ouput later or do calculations
    cout << "Date: ";
    cin >> Date;
    cout << "Quantity of Book: ";
    cin >> Qty;
    cout << "ISBN: ";
    cin >> ISBN;
    cout << "Title: ";
    cin.ignore(); // It Removes The LeftOver of the newline
    getline(cin, Title); // it Reads the whole line
    cout << "Price: ";
    cin >> Price;

    // The calculations
    double subtotal = Qty * Price;
    double Tax = subtotal * Tax_Rate;
    double Total = subtotal + Tax;

    cout << endl;
    cout << "Serendipity Booksellers"<< endl;
    cout << endl;
    cout << "Date: " << Date << endl;
    cout << endl;
    // The alignment and the spaces wide as you set in document
    cout << left << setw(5) << "Qty"
         << left << setw(14) << "ISBN"
         << left << setw(24) << "Title"
         << right << setw(7) << "Price"
         << right << setw(12) << "Subtotal" << endl;
    cout << "________________________________________________________________" << endl;

    // The alignment and the spaces wide as you set in document
    cout << left << setw(5) << Qty
         << left << setw(14) << ISBN
         << left << setw(24) << Title
         << right << setw(7) << fixed << setprecision(2) << Price
         << right << setw(12) << fixed << setprecision(2) << subtotal << endl;

    // The alignment and the spaces wide as you set in document
    //Showing the Calulatiions I made earlier
    cout << endl
         << setw(25) << "Subtotal" << setw(15) << subtotal << endl
         << setw(25) << "Tax" << setw(15) << Tax << endl
         << setw(25) << "Total" << setw(15) << Total << endl;
    cout << endl;
    cout << "Thank you for Shopping at Serendipity!" << endl;
}
