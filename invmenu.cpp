/*
 * Class: CMSC226
 * Instructor: Farnaz Eivazi
 * Description: When you are in the inventory database it shows you the actions you can do and you have to choose one of the vaild options
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
    //output inventory database
    int Invdatabasechoice;
    
    do{
     cout << "Serendipity Booksellers" << endl;
     cout << "       Inventory Database" << endl;
     cout << "1. LookUp a Book" << endl;
     cout << "2. Edit a Book's Record" << endl;
     cout << "3. Delete a Book" << endl;
     cout << "4. Return to the Main Menu" << endl;
     cout << endl;
     cout << "Enter your Choice: \n";
     cin >> Invdatabasechoice;
     
     while (Invdatabasechoice < 1 || Invdatabasechoice > 4){
         cout << "Invalid Choice" << endl;
         cin >> Invdatabasechoice;
     }
     switch (Invdatabasechoice){
        case 1:
            cout << "LookUp a Book" << endl;
            break;
        case 2:
            cout << "Edit a Book's Record" << endl;
            break;
        case 3:
            cout << "Delete a Book" << endl;
            break;
        case 4:
            cout << "Return to the Main Menu" << endl;
            break;
     }
    }while (Invdatabasechoice != 4);

     return 0;
}
