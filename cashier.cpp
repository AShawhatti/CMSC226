/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: When given the information about the book or if there are more books and check the date then it calculates how much it will cost to buy it
 * Due: 9/28/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */


#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //declaring variables
    const double Tax_Rate = 0.06;
    char Anothertime;
    double Price;
    string Date, ISBN, Title;
    int Qty;  

    do{
    cout << "Serendipity Booksellers" << endl;
    cout << " Cashier Module" << endl;
    cout << " " << endl;

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
    //The user input

   
    double subtotal = Qty * Price;
    double Tax = subtotal * Tax_Rate;
    double Total = subtotal + Tax;
    //Calculating the subtotal tax and total
     
    //doing output and formatting
    cout << endl;
    cout << "Serendipity Booksellers\n";
    cout << endl;
    cout << "Date: " << Date << endl;
    cout << endl;
    cout << left << setw(5) << "Qty"
         << left << setw(14) << "ISBN"
         << left << setw(24) << "Title"
         << right << setw(7) << "Price"
         << right << setw(12) << "Subtotal" << endl;
    cout << "________________________________________________________________" << endl;

    
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

    cout << "Do you want to buy another book? (Y/N)" << endl;
    cin >> Anothertime;
    } while (Anothertime == 'Y' || Anothertime == 'y');


    cout << "Thank you for Shopping at Serendipity!" << endl;
    return 0;
}
