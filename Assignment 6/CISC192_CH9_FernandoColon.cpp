/******************************************************************************
Fernando Colon
CISC 192 Chapter 9
03/04/2022
Random Rainfall Generator with Pointers
*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include <iomanip>

using namespace std;
//global variables are usually looked down upon, but since the number on months will literally
//never change, I indulged myself
const int SIZE = 12;

void pointPointer(string*, double*);
void display(string*, double*);
double getMinRain(double* lRain);
double getMaxRain(double* lRain);


int main()
{
    double* ptrRain = new double[SIZE];
    string* ptrMonth = new string[SIZE];
    //passing an entire array is automatically passed by reference, very handy 
    pointPointer(ptrMonth, ptrRain);
    //since only 5 variables were allowed, inserted the function calls into the display call 
    display(ptrMonth, ptrRain);

    delete[] ptrMonth;
    delete[] ptrRain;

    return 0;
}
//variable names as to not be confused with main functions names
void pointPointer(string* pMonth, double* pRain)
{
    //this does what Chapter 3-25 does in one line instead of 2
    srand(static_cast<double>(time(0)));

    //only a months one since the rain can be done in the loop
    vector<string> localMonths{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    vector<double> localRain;
    
    for(int i = 0; i < SIZE; i++)
    {
        pMonth[i] = localMonths[i];
        //uses the mod operator to make sure the random number is within 401. For loop adds 12 random doubles corresponding to each month
        //after dividing by 100, the value should be a number <= 4 inches. which was the maximum for last weeks assignment
        localRain.push_back((static_cast<double>(rand() % 401))/100);
        pRain[i] = localRain[i];
    }

    //this method from the vector example seems to have a pointer to each individual vector node. I wouldve just populated a vector by reference, but I understand its for the assignment
}

void display(string* pMonth, double* pRain)
{
    string* a;
    cout << "\nMonth has type: " << typeid(pMonth).name() << endl;
    cout << "Rain has type: " << typeid(pRain).name() << endl;
    cout << "\n\tMonthly Rainfall (inches)\n\n";
    
    //just a simple way to make the code cleaner. making a variable that stores a line of code
    #define FORMATTING (cout << fixed << setprecision(2) << setw(20) << left)

    for(int i = 0; i < SIZE; i++)
    {        
        FORMATTING;
        cout << pMonth[i] + ":";
        cout << pRain[i] << endl;
    }

    cout << "------------------------\n";
    FORMATTING;
    cout << "Min Rainfall:" << getMinRain(pRain) << endl;
    FORMATTING;
    cout << "Max Rainfall:" << getMaxRain(pRain) << endl;
}

double getMinRain(double* lRain)
{
    double min = 5;//the max rain will never exceed 5
    for(int i = 0; i < SIZE; i++)
    {
        if((lRain[i]) < min)
        {
            min = lRain[i];
        }
    }
    return min;
}

double getMaxRain(double* lRain)
{
    double max = 0;//the max rain will never be below 0
    for(int i = 0; i < SIZE; i++)
    {
        if((lRain[i]) > max)
        {
            max = lRain[i];
        }
    }
    return max;
}