/******************************************************************************
Fernando Colon
CISC 192 Chapter 7
02/28/2022
Random Rainfall Generator 
*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;
//global variables are usually looked down upon, but since the number on months will literally
//never change, I indulged myself
const int NUM_MONTHS = 12;

void populateArrays(string [NUM_MONTHS], int [NUM_MONTHS]);
void calcMaths(int [NUM_MONTHS], int&, int&, int&);
string minMonths(string [NUM_MONTHS], int [NUM_MONTHS], int);
string maxMonths(string [NUM_MONTHS], int [NUM_MONTHS], int);
void display(string, string, string [NUM_MONTHS], int [NUM_MONTHS], int);


int main()
{
    int rain[NUM_MONTHS];
    string month[NUM_MONTHS];
    //passing an entire array is automatically passed by reference, very handy 
    populateArrays(month, rain);
    //initialized with 5 and -1 because they are outside the bounds of our min and max
    //doing so will guarantee they change when comparing the values. total to zero, 
    //otherwise will be random memory generated number
    int min = 5, max = -1, total = 0;
    calcMaths(rain, min, max, total);
    //since only 5 variables were allowed, inserted the function calls into the display call 
    display(minMonths(month, rain, min), maxMonths(month, rain, max), month, rain, total);


    return 0;
}
//variable names as to not be confused with main functions names
void populateArrays(string monthSetup[NUM_MONTHS], int rainSetup[NUM_MONTHS])
{
    //this does what Chapter 3-25 does in one line instead of 2
    srand(static_cast<unsigned int>(time(0)));
    //local string is required to be able to move to the main string array
    string localMonths[NUM_MONTHS] = 
    {
        {"January"},
        {"February"},
        {"March"},
        {"April"},
        {"May"},
        {"June"},
        {"July"},
        {"August"},
        {"September"},
        {"October"},
        {"November"},
        {"December"}
    };
    for(int i = 0; i < NUM_MONTHS; i++)
    {
        monthSetup[i] = localMonths[i];
        rainSetup[i] = rand() % 5; //uses the mod operator to make sure the random number is within 4
    }
}

//simple maths calculations
void calcMaths(int rainC[NUM_MONTHS], int& minC, int& maxC, int& totalC)
{
    for(int i = 0; i < NUM_MONTHS; i++)
    {
        if(rainC[i] < minC)
            minC = rainC[i];

        if(rainC[i] > maxC)
            maxC = rainC[i];

        totalC += rainC[i];
    }
}

//function to find the months with minimum rain
string minMonths(string m[NUM_MONTHS], int r[NUM_MONTHS], int minActual)
{
    string finalMin;
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        if(finalMin.empty())//starting condition
        {
            if(r[i] == minActual)
            {
                finalMin = m[i];
            }
        }
        else//each iteration after the first will add a ", " and then the next month
        {
            if(r[i] == minActual)
            {
                finalMin += ", " + m[i];
            }
        }
    }
    return finalMin;//returns string of all months separated by a common
}
//exact implementation as the previous function but with max instead
string maxMonths(string m[NUM_MONTHS], int r[NUM_MONTHS], int maxActual)
{
    string finalMax;
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        if(finalMax.empty())
        {
            if(r[i] == maxActual)
            {
                finalMax = m[i];
            }
        }
        else
        {
            if(r[i] == maxActual)
            {
                finalMax += ", " + m[i];
            }
        }
    }
    return finalMax;//returns string of all months separated by a comma
}

void display(string minMon, string maxMon, string mon[NUM_MONTHS], int rain[NUM_MONTHS], int total)
{
    const int monthWidthCol1 = 10, textWidthCol2 = 10;//variables for setw with the months and rain
    const int stringWidthCol1 = monthWidthCol1 + textWidthCol2 - 1;//variable to match the second column. has to be -1 so that the start of the next column matches the last spot in the previous rows
    cout << "Rainfall per Month (in inches)\n\n";
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        cout << setw(monthWidthCol1) << left << mon[i] + ":" << setw(textWidthCol2) << right << rain[i] << endl;
    }

    cout << setw(stringWidthCol1) << left << "Total Rainfall:\t" << left << total << endl;

    float average = (float)total / NUM_MONTHS;
    cout << setw(stringWidthCol1) << left << "Average Rainfall:" << left << fixed << setprecision(4) << average << endl;

    cout << setw(stringWidthCol1) << left << "Least Rainfall in:" << left << minMon << endl;
    cout << setw(stringWidthCol1) << left << "Most Rainfall in:" << left << maxMon << endl;
}