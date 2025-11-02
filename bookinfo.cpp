/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi 
 * Description: ouputs individual book information
 * Due: 11/2/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Hassan Shawhatti
 */

#include <iostream>
#include <iomanip>
#include "bookinfo.h"
using namespace std;

void bookInfo(char isbn[], char title[], char author[], char publisher[], 
              char date[], int qty, double wholesaleCost, double retailPrice) {
    cout << "\nSerendipity Booksellers\n";
    cout << "     Book Information\n\n";
    
    cout << "ISBN: ";
    cout << isbn << endl;
    
    cout << "Title: ";
    cout << title << endl;
    
    cout << "Author: ";
    cout << author << endl;
    
    cout << "Publisher: ";
    cout << publisher << endl;
    
    cout << "Date Added: ";
    cout << date << endl;
    
    cout << "Quantity-On-Hand: ";
    cout << qty << endl;
    
    cout << "Wholesale Cost: ";
    cout << fixed << setprecision(2) << wholesaleCost << endl;
    
    cout << "Retail Price: ";
    cout << fixed << setprecision(2) << retailPrice << endl;
}