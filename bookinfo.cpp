/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi 
 * Description: Shows information for a single book
 * Due: 11/2/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */

#include <iostream>
#include <iomanip>
#include "bookinfo.h"
using namespace std;

void bookInfo(char isbn[], char title[], char author[], char publisher[], char date[], int qty, double wholesaleCost, double retailPrice) {
    cout << "\nSerendipity Booksellers\n";
    cout << "     Book Information\n\n";
    cout << "ISBN: " << isbn << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Date Added: " << date << endl;
    cout << "Quantity-On-Hand: " << qty << endl;
    cout << "Wholesale Cost: " << fixed << setprecision(2) << wholesaleCost << endl;
    cout << "Retail Price: " << fixed << setprecision(2) << retailPrice << endl;
}