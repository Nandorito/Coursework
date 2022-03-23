/******************************************************************************
Fernando Colon
CISC 192 Chapter 12
03/20/2022
Random Rainfall Generator with Structures and Output File
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

//you mentioned no hard coding individual elements but that doesnt apply to total months
//since we are using an array vs a vector, we dont have the .size function
//to find the total amount in a list. this constant allows us to iterate through the array
const int TOTAL_MONTHS = 12;

using namespace std;

struct Month
{
    string name;
    int rain;
};


void generateRainMonths(Month[]);
void display(Month[]);
void writeToFile(Month[]);
void addRecord(fstream& outFile, const Month[], int index);
bool checkMonthDuplicate(const string& monthLong, const string& monthName);//passing a constant reference to save memory is always good practice

//always nice to see a clean main function
int main()
{
    Month months[TOTAL_MONTHS];
    generateRainMonths(months);
    display(months);
    writeToFile(months);    
    return 0;
}

//populates the structure. passing an array is automatically passed by reference
void generateRainMonths(Month months[])
{
    srand(static_cast<unsigned int>(time(0)));
    string names[TOTAL_MONTHS] = 
    {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };

    for(int i = 0; i < TOTAL_MONTHS; i++)
    {
        months[i].rain = rand() % 5;//having mod 5 allows for random numbers 4 and below
        months[i].name = names[i];
    }
}

void display(Month months[])
{
    cout << endl;
    //since the number is first to be displayed, its only one digit, so formatting will be clean regardless
    for(int i = 0; i < TOTAL_MONTHS; i++)
    {
        cout << months[i].rain << " inches in " << months[i].name << endl;
    }
}

void writeToFile(Month months[])
{
    fstream outFile("randomMonths.txt", ios::out); // this rewrites over an existing file if it exists. for simplicities sake, this assignment will just rewrite so we dont have an overflow of files
    string monthLongString = ""; //static string variable here
    bool allMonthsWritten = false;
    int counter = 0;

    //a while loop is preferable in this situation since we wont know how many times it will check the if statement, vs the usual for loop which requires a set number of iterations
    while(!allMonthsWritten)
    {
        int random = rand() % TOTAL_MONTHS;//choose a random month 0-11
        //if this returns true, skip it
        if(!checkMonthDuplicate(monthLongString, months[random].name))
        {
            monthLongString += months[random].name;
            addRecord(outFile, months, random);
            counter++;
        }
        if(counter > TOTAL_MONTHS - 1) 
        {
            allMonthsWritten = true;//once twelve months have been written, set this boolean to true to end the loop
            outFile.close();
        }
    }
}

//self explanatory
void addRecord(fstream& outFile, const Month months[], int index)
{
    outFile << months[index].name << " had " << months[index].rain << " inches\n";
}

bool checkMonthDuplicate(const string& monthLong, const string& monthName)
{
    //if "found" has reached the end of the string, no matches, returns false. npos == -1. 
    //I couldve used if(found < 0) as well. either works the same. This is less "hardcoded"
    //when false here, the if statement in writeToFile succeeds and completes its scope of code
    int found = monthLong.find(monthName);
    if(found != string::npos) return true;//this means the string was found
    else return false;
}