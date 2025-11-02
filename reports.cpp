/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi 
 * Description: Sorted inventory reports showing wholesale value, retail value, quantity, cost, and age data
 * Due: 11/2/2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Hassan Shawhatti
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "reports.h"
#include "mainmenu.h"
using namespace std;

void reports() {
    int reportChoice;
    bool continueReports = true;
    
    while (continueReports) {
        cout << "\n  Serendipity Booksellers\n";
        cout << "         Reports\n\n";
        cout << "  1. Inventory Listing\n";
        cout << "  2. Inventory Wholesale Value\n";
        cout << "  3. Inventory Retail Value\n";
        cout << "  4. Listing by Quantity\n";
        cout << "  5. Listing by Cost\n";
        cout << "  6. Listing by Age\n";
        cout << "  7. Return to the Main Menu\n\n";
        cout << "  Enter Your Choice: ";
        cin >> reportChoice;
        cin.ignore();
        
        bool validChoice = (reportChoice >= 1 && reportChoice <= 7);
        while (!validChoice) {
            cout << "\n  Please enter a number in the range 1 - 7.\n";
            cout << "  Enter Your Choice: ";
            cin >> reportChoice;
            cin.ignore();
            validChoice = (reportChoice >= 1 && reportChoice <= 7);
        }
        
        if (reportChoice == 1) {
            repListing();
        } else if (reportChoice == 2) {
            repWholesale();
        } else if (reportChoice == 3) {
            repRetail();
        } else if (reportChoice == 4) {
            repQty();
        } else if (reportChoice == 5) {
            repCost();
        } else if (reportChoice == 6) {
            repAge();
        } else {
            continueReports = false;
        }
    }
}

void repListing() {
    cout << "\n       Inventory Listing Report\n\n";
    cout << left << setw(30) << "Title" << setw(15) << "ISBN" << setw(20) << "Author" 
         << setw(20) << "Publisher" << setw(12) << "Date Added" << setw(5) << "Qty" 
         << setw(10) << "Wholesale" << setw(10) << "Retail" << endl;
    cout << "---------------------------------------------------------------------------------";
    cout << "-----------------------------------------------------------------\n";
    
    int lineCounter = 0;
    int arrayIndex = 0;
    while (arrayIndex < MAX_BOOKS) {
        if (bookTitle[arrayIndex][0] != '\0') {
            cout << left << setw(30) << bookTitle[arrayIndex] << setw(15) << isbn[arrayIndex] 
                 << setw(20) << author[arrayIndex] << setw(20) << publisher[arrayIndex] 
                 << setw(12) << dateAdded[arrayIndex] << setw(5) << qtyOnHand[arrayIndex] 
                 << setw(10) << fixed << setprecision(2) << wholesale[arrayIndex] 
                 << setw(10) << fixed << setprecision(2) << retail[arrayIndex] << endl;
            lineCounter++;
            
            if (lineCounter % 20 == 0) {
                cout << "\nPress Enter to continue...";
                cin.get();
            }
        }
        arrayIndex++;
    }
    
    if (lineCounter == 0) {
        cout << "No books in inventory.\n";
    }
}

void repWholesale() {
    cout << "\n       Inventory Wholesale Value Report\n\n";
    cout << left << setw(30) << "Title" << setw(15) << "ISBN" 
         << setw(10) << "Qty" << setw(15) << "Wholesale" << setw(15) << "Total Value" << endl;
    cout << "--------------------------------------------------------------------------------\n";
    
    double totalValue = 0.0;
    int recordCount = 0;
    
    int position = 0;
    while (position < MAX_BOOKS) {
        if (bookTitle[position][0] != '\0') {
            double valueForItem = wholesale[position] * qtyOnHand[position];
            totalValue = totalValue + valueForItem;
            
            cout << left << setw(30) << bookTitle[position] << setw(15) << isbn[position] 
                 << setw(10) << qtyOnHand[position] << setw(15) << fixed << setprecision(2) 
                 << wholesale[position] << setw(15) << fixed << setprecision(2) << valueForItem << endl;
            recordCount++;
            
            if (recordCount % 20 == 0) {
                cout << "\nPress Enter to continue...";
                cin.get();
            }
        }
        position++;
    }
    
    cout << "\nTotal Wholesale Value: $" << fixed << setprecision(2) << totalValue << endl;
}

void repRetail() {
    cout << "\n       Inventory Retail Value Report\n\n";
    cout << left << setw(30) << "Title" << setw(15) << "ISBN" 
         << setw(10) << "Qty" << setw(15) << "Retail" << setw(15) << "Total Value" << endl;
    cout << "--------------------------------------------------------------------------------\n";
    
    double overallTotal = 0.0;
    int itemsPrinted = 0;
    
    int slot = 0;
    while (slot < MAX_BOOKS) {
        if (bookTitle[slot][0] != '\0') {
            double lineValue = retail[slot] * qtyOnHand[slot];
            overallTotal = overallTotal + lineValue;
            
            cout << left << setw(30) << bookTitle[slot] << setw(15) << isbn[slot] 
                 << setw(10) << qtyOnHand[slot] << setw(15) << fixed << setprecision(2) 
                 << retail[slot] << setw(15) << fixed << setprecision(2) << lineValue << endl;
            itemsPrinted++;
            
            if (itemsPrinted % 20 == 0) {
                cout << "\nPress Enter to continue...";
                cin.get();
            }
        }
        slot++;
    }
    
    cout << "\nTotal Retail Value: $" << fixed << setprecision(2) << overallTotal << endl;
}

void repQty() {
    int sortedIndices[MAX_BOOKS];
    int numberOfRecords = 0;
    
    int i = 0;
    while (i < MAX_BOOKS) {
        if (bookTitle[i][0] != '\0') {
            sortedIndices[numberOfRecords] = i;
            numberOfRecords++;
        }
        i++;
    }
    
    int outerLoop = 0;
    while (outerLoop < numberOfRecords - 1) {
        int innerLoop = 0;
        while (innerLoop < numberOfRecords - outerLoop - 1) {
            if (qtyOnHand[sortedIndices[innerLoop]] < qtyOnHand[sortedIndices[innerLoop + 1]]) {
                int tempIndex = sortedIndices[innerLoop];
                sortedIndices[innerLoop] = sortedIndices[innerLoop + 1];
                sortedIndices[innerLoop + 1] = tempIndex;
            }
            innerLoop++;
        }
        outerLoop++;
    }
    
    cout << "\n       Listing by Quantity Report\n\n";
    cout << left << setw(30) << "Title" << setw(15) << "ISBN" << setw(10) << "Qty" << endl;
    cout << "--------------------------------------------------------\n";
    
    int displayCounter = 0;
    while (displayCounter < numberOfRecords) {
        int currentIndex = sortedIndices[displayCounter];
        cout << left << setw(30) << bookTitle[currentIndex] << setw(15) << isbn[currentIndex] 
             << setw(10) << qtyOnHand[currentIndex] << endl;
        
        if ((displayCounter + 1) % 20 == 0) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
        displayCounter++;
    }
}

void repCost() {
    int orderedIndices[MAX_BOOKS];
    int totalRecords = 0;
    
    int index = 0;
    while (index < MAX_BOOKS) {
        if (bookTitle[index][0] != '\0') {
            orderedIndices[totalRecords] = index;
            totalRecords++;
        }
        index++;
    }
    
    int pass = 0;
    while (pass < totalRecords - 1) {
        int compare = 0;
        while (compare < totalRecords - pass - 1) {
            if (wholesale[orderedIndices[compare]] < wholesale[orderedIndices[compare + 1]]) {
                int swap = orderedIndices[compare];
                orderedIndices[compare] = orderedIndices[compare + 1];
                orderedIndices[compare + 1] = swap;
            }
            compare++;
        }
        pass++;
    }
    
    cout << "\n       Listing by Cost Report\n\n";
    cout << left << setw(30) << "Title" << setw(15) << "ISBN" 
         << setw(10) << "Qty" << setw(15) << "Wholesale" << endl;
    cout << "-----------------------------------------------------------------------\n";
    
    int printIndex = 0;
    while (printIndex < totalRecords) {
        int recordIndex = orderedIndices[printIndex];
        cout << left << setw(30) << bookTitle[recordIndex] << setw(15) << isbn[recordIndex] 
             << setw(10) << qtyOnHand[recordIndex] << setw(15) << fixed << setprecision(2) 
             << wholesale[recordIndex] << endl;
        
        if ((printIndex + 1) % 20 == 0) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
        printIndex++;
    }
}

void repAge() {
    int ageIndices[MAX_BOOKS];
    int bookCount = 0;
    
    int scan = 0;
    while (scan < MAX_BOOKS) {
        if (bookTitle[scan][0] != '\0') {
            ageIndices[bookCount] = scan;
            bookCount++;
        }
        scan++;
    }
    
    int outer = 0;
    while (outer < bookCount - 1) {
        int inner = 0;
        while (inner < bookCount - outer - 1) {
            if (strcmp(dateAdded[ageIndices[inner]], dateAdded[ageIndices[inner + 1]]) > 0) {
                int temporary = ageIndices[inner];
                ageIndices[inner] = ageIndices[inner + 1];
                ageIndices[inner + 1] = temporary;
            }
            inner++;
        }
        outer++;
    }
    
    cout << "\n       Listing by Age Report\n\n";
    cout << left << setw(30) << "Title" << setw(15) << "ISBN" 
         << setw(10) << "Qty" << setw(15) << "Date Added" << endl;
    cout << "-----------------------------------------------------------------------\n";
    
    int outputIndex = 0;
    while (outputIndex < bookCount) {
        int dataIndex = ageIndices[outputIndex];
        cout << left << setw(30) << bookTitle[dataIndex] << setw(15) << isbn[dataIndex] 
             << setw(10) << qtyOnHand[dataIndex] << setw(15) << dateAdded[dataIndex] << endl;
        
        if ((outputIndex + 1) % 20 == 0) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
        outputIndex++;
    }
}