/******************************************************************************
Fernando Colon
CISC 192 Chapter 4
02/17/2022
Race Menu Program 
*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
   int choice;       // To hold a menu choice
   double cost, totalCost;   // i usually declare variables wherever i need them to prevent unecessary memory allocations
   // Constants for race prices
   const double FIRST = 300.0,
                SECOND = 250.0,
                THIRD = 750.0,
                TSHIRT = 12.0;
   // Constants for menu choices
   const int ROCKS_CHOICE = 1,
             BUOY_CHOICE = 2,
             SINGLE_CHOICE = 3,
             QUIT_CHOICE = 4;
   // Display the menu and get a choice.
   cout << "\t\tRace Menu\n\n"
        << "1. Around the Rocks, San Francisco\n"
        << "2. Tuesday Night Buoy Races, Marina Del Rey\n"
        << "3. Single-handed Transpac, SF to Hawaii\n"
        << "4. Exit Menu\n\n"
        << "Enter your choice: ";
   cin >> choice;
   cin.ignore();
   
   string raceName;
   // Set the numeric ouput formatting.
   cout << fixed << showpoint << setprecision(2);
   
   // Respond to the user's menu selection.
   switch (choice)
   {
      case ROCKS_CHOICE:
         cout << "Welcome to Around the Rocks, San Francisco!\n";
         raceName = "Around the Rocks, San Francisco";
         cost = FIRST;
         cout << "The cost to participate is $" << cost << endl;
         break;
         
      case BUOY_CHOICE:
         cout << "Welcome to Tuesday Night Buoy Races, Marina Del Rey!\n";
         raceName = "Tuesday Night Buoy Races, Marina Del Rey";
         cost = SECOND;
         cout << "The cost to participate is $" << cost << endl;
         break;
         
      case SINGLE_CHOICE:
         cout << "Welcome to Single-handed Transpac, SF to Hawaii!\n";
         raceName = "Single-handed Transpac, SF to Hawaii";
         cost = THIRD;
         cout << "The cost to participate is $" << cost << endl;
         break;
        
      case QUIT_CHOICE:
         cout << "Program ending.\n";
         return 0;//ends program
         
      default:
         cout << "The valid choices are 1 through 4. Run the\n"
              << "program again and select one of those.\n";
         return 0;//this line needs to be here since the directions say to run the program again and we can't use loops
   }

   /*
   since asking for the users name and boat name happens each and every time the program is run regardless
   of their choice (1-3), i find it very redundant typing in these prompts in each and every switch case.
   although you state in the directions that you want the tshirt question in each of the switch cases,
   i cant seem to figure out how that is good programming practice even if we couldn't use loops.
   so i've decided to code it this way since its the logical next step of the program each time
   it is run
   */
   string playerName, boatName;
   char answer;
   cout << "\nPlease input your name: " << setw(4);
   getline(cin, playerName);
   cout << "Please input your boat name: " << setw(2);
   getline(cin, boatName);
   cout << "Do you wish to purchase this cool green and blue tshirt for only $12? (y/n) ";
   cin.get(answer);

   //final calculations 
   if(answer == 'y')
   {
       totalCost = cost + TSHIRT;
   }
   else if(answer == 'n')
   {
       totalCost = cost;
   }
   else
   {
      cout << "\nI'll assume that means 'no'.\n";
      totalCost = cost;
      answer = 'n';//this is for the final output
   }

   //final output
   cout << "\n\nRace Selected: \t\t" << raceName << endl;
   cout << "Participant Name: \t" << playerName << endl;
   cout << "Boat Name: \t\t" << boatName << endl;
   cout << "TShirt (y/n) \t\t" << answer << endl;
   cout << "Your balance: \t\t$" << totalCost << endl;

   return 0;
}