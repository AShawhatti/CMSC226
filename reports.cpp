/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: it gives you a report of the inventory and you can choose what part to look at
 * Due: 9/28/2025
 * I pledge that I have completed the programming assignment independently. 
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Adam Shawhatti
 */


#include <iostream>
using namespace std;
int main()
{
    //Reports input decinding  the output
    int Reportschoice;
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
    cin >> Reportschoice;
    
    //To check if input correct
    while (Reportschoice < 1 || Reportschoice > 7){
        cout << "Invalid Choice" << endl;
        cin >> Reportschoice;
    }

    switch (Reportschoice){
        case 1:
            cout << "Inventory Listing" << endl;
            break;
        case 2:
            cout << "Inventory Wholesale Value" << endl;
            break;
        case 3:
            cout << "Inventory Retail Value" << endl;
            break;
        case 4:
            cout << "Listing by Quantity" << endl;
            break;
        case 5:
            cout << "Listing by Cost" << endl;
            break;
        case 6:
            cout << "Listing by Age" << endl;
            break;
        case 7:
            cout << "Return to the Main Menu" << endl;
            break;
    }
}while (Reportschoice != 7);
    return 0;
}

