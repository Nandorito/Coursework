/******************************************************************************
Fernando Colon
CISC 192 Assignment 2
02/03/2022
Calculating the cost of moving 
*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    //declare all variables for this program to include totalExpenses and totalPerPerson. these will be initialized later
    int motorhome = 5000, insurance = 900, tires = 500, foodCostPer = 150, bedding = 250;
    float salesTaxRate = .0775, registration = 45.55, taxes = motorhome * salesTaxRate, totalExpenses, totalPerPerson;
    
    //display all the info to the user
    cout << "Total Trip Expenses\n\n";
    cout << "Motorhome: \t\t" << motorhome << endl;
    cout << "Sales Tax: \t\t" << taxes << endl;
    cout << "Registration: \t\t" << registration << endl;
    cout << "Insurance: \t\t" << insurance << endl;
    cout << "Tires: \t\t\t" << tires << endl;
    cout << "Food Cost Each: \t" << foodCostPer << endl;
    cout << "Bedding: \t\t" << bedding << endl;
    
    //float variables can take in int variables as well
    //adds the total amount of expenses and multiples the food cost for 4 people
    totalExpenses = motorhome + taxes + registration + insurance + tires + (foodCostPer*4) + bedding;
    
    //display the total expenses
    cout << "Total Expenses: \t" << totalExpenses << endl << endl;
    
    //calculate total per person then display it
    totalPerPerson = totalExpenses/4;
    cout << "Total Cost Each: \t" << totalPerPerson;

    //end main function
    return 0;
}