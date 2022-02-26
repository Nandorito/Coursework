/******************************************************************************
Fernando Colon
CISC 192 Chapter 6
02/20/2022
Photography Business Program 
*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//function prototypes
int inputCustomerNumber();
int inputCategory();
float inputHoursWorked();
int inputPrints();
int inputEnlargements();
//I find adding variable names here can cause more confusion in the long run, so simple data type calls will suffice for now
void calcPrices(float, int, int, float&, float&);
void display(int, int, float , int, int, float, float);
//string constants for future display, set as GLOBAL so it can be referenced in multiple functions. not always necessary but nice to have access anywhere. 
string const WEDDING = "Wedding", PORTRAIT = "Portrait", ACTION = "Action";

int main()
{
    //nice and clean main function now
    int customerNum = inputCustomerNumber();
    int category = inputCategory();
    float hoursWorked = inputHoursWorked();
    int prints = inputPrints();
    int enlargements = inputEnlargements();
    float wholesale, retail;
    //had a compile error that took me an hour to figure out here. something so simple I thought I should mention it
    //I typed void in front of these function calls -_-
    calcPrices(hoursWorked, prints, enlargements, wholesale, retail);
    display(customerNum, category, hoursWorked, prints, enlargements, wholesale, retail);//the values of wholesale and retail will be different for this function call because we passed by reference the previous one
    return 0;
}

//simple function to validate input from the user
int inputCustomerNumber()
{
    cout << "Please enter customer number: ";
    int num;
    cin >> num;
    while(num <= 0)
    {
        cout << "\nCustomer number must be greater than zero. Try again.\n";
        cout << "Please enter customer number: ";
        cin >> num;
    }
    cout << endl;
    return num;
}

//simple function to validate input from the user
int inputCategory()
{
    int category;
    //used do/while loop for this function because the amount of text cout is greater than the other functions
    //since returning an int variable, I elect to use the switch statement at the display function
    do
    {
        cout << "Possible Categories:\n";
        cout << "1. Wedding\n";
        cout << "2. Portrait\n";
        cout << "3. Action\n\n";
        cout << "Enter your category choice here: ";
        cin >>  category;

        //since im working with a do/while, 
        if(category <= 0 || category > 3)
        {
            cout << "\nMake sure you enter a listed value (1-3).\n\n";
        }
    }while(category <= 0 || category > 3);
    cout << endl;
    return category;
}
//simple function to validate input from the user
float inputHoursWorked()
{
    cout << "Please enter hours worked: ";
    float hours;
    cin >>  hours;
    while(hours <= 0)
    {
        cout << "\nHours must be greater than zero. Try again.\n";
        cout << "Please enter hours worked: ";
        cin >> hours;
    }
    cout << endl;
    return hours;
}
//simple function to validate input from the user
int inputPrints()
{
    cout << "Please enter number of 8x10 prints: ";
    int prints;
    cin >> prints;
    while(prints <= 0)
    {
        cout << "\nPrints must be greater than zero. Try again.\n";
        cout << "Please enter number of 8x10 prints: ";
        cin >> prints;
    }
    cout << endl;
    return prints;
}
//simple function to validate input from the user
int inputEnlargements()
{
    cout << "Please enter number of 14x20 prints: ";
    int enlargements;
    cin >> enlargements;
    while(enlargements <= 0)
    {
        cout << "\nPrints must be greater than zero. Try again.\n";
        cout << "Please enter number of 14x20 prints: ";
        cin >> enlargements;
    }
    cout << endl;
    return enlargements;
}
//slight change to variable names to not get confused with main function variables
void calcPrices(float hoursCalc, int printsCalc, int enlargementsCalc, float& wholesaleCalc, float& retailCalc)
{
    //these two variables will change the originals back in main since it is passed by reference
    //reference is especially nice when passing very large objects to save memory
    wholesaleCalc = (hoursCalc * 50) + (printsCalc * 15) + (enlargementsCalc * 35);
    retailCalc = wholesaleCalc * 5;
}

void display(int customerDisplay, int categoryDisplay, float hoursDisplay, int printsDisplay, int enlargementsDisplay, float wholesaleDisplay, float retailDisplay)
{
    cout << endl;
    cout << "\tPRINT OUT REPORT\n";
    cout << "--------------------------------\n";
    cout << "Customer Number\t\t\t:" << customerDisplay << endl;
    cout << "Category\t\t\t:";//careful formatting here as to not get confused which line I'm printing on. choosing not to use endl like the rest of the lines in favor of the following switch statement

    //using the string constants and endl here instead
    switch(categoryDisplay)
    {
        case 1:
        cout << WEDDING << endl;
        break;

        case 2:
        cout << PORTRAIT << endl;
        break;

        case 3:
        cout << ACTION << endl;
        break;
        //no default necessary since input validation was already taken care of
    };
    //fix number formatting
    cout << fixed << showpoint << setprecision(2);
    cout << "Hours worked\t\t\t:" << hoursDisplay << endl;
    cout << "Number of 8x10 prints requested\t:" << printsDisplay << endl;
    cout << "Number of enlargements requested:" << enlargementsDisplay << endl;
    cout << "Wholesale price\t\t\t:$" << wholesaleDisplay << endl;
    cout << "Retail price\t\t\t:$" << retailDisplay << endl;
}