/*Fernando Colon
CISC 192 - Assignment 1
02/03/2022
This program calculates user's pay.*/

#include <iostream>
using namespace std;

int main()
{
    double hours = 0.00;
    double rate = 0.00;
    double pay = 0.00;
    
    //Get number of hours worked
    cout << "How many hours did you work? ";
    cin >> hours;
    
    //Get hourly pay
    cout << "How much do you get paid per hour? ";
    cin >> rate;
    
    //Calculate pay
    pay = rate * hours;
    
    //Display pay
    cout << "You have earned $" << pay << endl;

    return 0;
}