/******************************************************************************
Fernando Colon
CISC 192 Chapter 11
03/12/2022
Random Rainfall Generator with Structures
*******************************************************************************/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

struct Weather
{
    int rain;
    string month;
};

void populateStructure(vector<Weather>&, int&, int&);
// constant reference makes sure we dont make any changes but also not make another copy of the object
void display(const vector<Weather>&, const int&, const int&); 
bool compareRain(const Weather& a, const Weather& b);
string minMonth(const vector<Weather>& vWeather, const int&);
string maxMonth(const vector<Weather>& vWeather, const int&);

//nice three lines of main
int main()
{
    vector<Weather> vWeather;
    int min = 0, max = 0;
    populateStructure(vWeather, min, max);
    display(vWeather, min, max);
}

void populateStructure(vector<Weather>& vWeather, int& min, int& max)
{
    srand(static_cast<unsigned int>(time(0)));
    vector<string> allMonths
    {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    for(int i = 0; i < allMonths.size(); i++)
    {
        //each node of this vector is of Weather type
        //so we have to insert a Weather struct before we add rain and month
        vWeather.push_back(Weather());
        vWeather[i].rain = rand() % 5;
        vWeather[i].month = allMonths[i];
        if(vWeather[i].rain < min) min = vWeather[i].rain;
        if(vWeather[i].rain > max) max = vWeather[i].rain;
    }

    //this function was a little tricky to write using a vector
    //however, after a little research, I have to pass a Weather struct by reference
    //instead of a vector of the struct (which is what I was doing) to the bool compare 
    //function I wrote
    sort(vWeather.begin(), vWeather.end(), compareRain);
}

//pretty self explanatory. I like to pass constant references so the variables
//cannot be changed and are not duplicated in memory
void display(const vector<Weather>& vWeather, const int& min, const int& max)
{
    cout << "\nMonths sorted by rainfall\n\n";
    for(int i = 0; i < vWeather.size(); i++)
    {
        cout << vWeather[i].rain << " inches in " << vWeather[i].month << endl;
    }

    cout << "\nMinimum rain in " << minMonth(vWeather, min) << endl;
    cout << "Maximum rain in " << maxMonth(vWeather, max) << endl;
}

//for the sorting function
bool compareRain(const Weather& a, const Weather& b)
{
    return (a.rain < b.rain);
}

string minMonth(const vector<Weather>& vWeather, const int& min)
{
    string text = "";
    //create a string of min months
    for(int i = 0; i < vWeather.size(); i++)
    {
        if(vWeather[i].rain == min)
        {
            if(text == "") text = vWeather[i].month; //this is only used for the first month
            else text += ", " + vWeather[i].month; //each preceding month
        }
    }
    return text;
}

string maxMonth(const vector<Weather>& vWeather, const int& max)
{
    string text = "";
    //create a string of max months
    for(int i = 0; i < vWeather.size(); i++)
    {
        if(vWeather[i].rain == max)
        {
            if(text == "") text = vWeather[i].month; //this is only used for the first month
            else text += ", " + vWeather[i].month; //each preceding month
        }
    }
    return text;
}