/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: Still the same as last time it just gives you information about the book. And added void so it could be called 
 * Due: 10/12/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */

#include <iostream>
#include "globals.h"
using namespace std;

void bookInfo(string isbnNum, string title, string authorName, string publisherName,
              string date, int qty, double wholesalePrice, double retailPrice)
{
    cout << "Serendipity Booksellers\nBook Information\n";
    cout << "ISBN: " << isbnNum << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << authorName << endl;
    cout << "Publisher: " << publisherName << endl;
    cout << "Date Added: " << date << endl;
    cout << "Quantity-On-Hand: " << qty << endl;
    cout << "Wholesale Cost: " << wholesalePrice << endl;
    cout << "Retail Price: " << retailPrice << endl;
}
