/*
1. Start

2. Ask for user input:
    Get the price per gallon of paint (if less than 0, display error and stop).
    Get the number of rooms to paint (if less than 1, display error and stop).
    For each room, get the square feet of wall space (if less than 25, display error and stop).

3. Calculate total square feet (add wall space for all rooms).

4. Calculate gallons of paint required:
    Divide total square feet by 115 (round up if needed).

5. Calculate cost of the paint:
    Multiply the number of gallons by price per gallon.

6. Calculate hours of labor required:
    Multiply total square feet by 8 / 115.

7. Calculate labor charges:
    Multiply hours of labor by $25 per hour.

8. Calculate total cost of the paint job:
    Add the cost of the paint and labor charges.

9. Display the results:
    Gallons of paint required
    Cost of paint
    Hours of labor required
    Labor charges
    Total cost of the paint job

10. End

*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std; 

// Function Prototypes
double getPricePerGallon();
int getRooms();
int calcWallSpace(int rooms);
void calcPaint(int sqFeet, double pricePaint, int& gallons, double& cost);
void calcLabor(int sqFeet, double& hours, double& cost);


int main()
{
    cout << "Paint job Estimator ... \n\n";

    double pricePerGallon = getPricePerGallon(); // Call the function to get the price per Gallon
    int rooms = getRooms(); // Call the function to get the Number of Rooms
    int totalSquareFeet = calcWallSpace(rooms); // Call the function to get the total wall space

    cout << " \n\n";
    cout << "\t Paint Job Estimate \n\n"; 

    int gallons; 
    double paintCost;
    calcPaint(totalSquareFeet, pricePerGallon, gallons, paintCost); // Call the function to get the Total data for the Paint job
    
    double laborHours, laborCost;
    calcLabor(totalSquareFeet, laborHours, laborCost); // Call the function to get the total labor charges for the paint job

    // Display Total Cost 
    double totalCost;
    totalCost = paintCost + laborCost;
    cout << "Total Cost: " << fixed << setprecision(2) << totalCost << endl;

    return 0;
}




double getPricePerGallon()
{
    double pricePerGallon; // Input Variable 
    cout << "Price per gallon of paint (>=0): ";
    cin >> pricePerGallon;

    // Do not accept a value less than 0 for the price of paint per gallon.
    while(pricePerGallon < 0) 
    {
        cout << "Error ... Invalid price per gallon of paint. Try again.\n";
        cout << "Price per gallon of paint (>=0): ";
        cin >> pricePerGallon;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return pricePerGallon;
}

int getRooms()
{
   int rooms; // Input Variable
    cout << "Number of rooms to be painted (>=1): ";
    cin >> rooms;

    // Do not accept a value less than 1 for the number of rooms.
    while(rooms < 1)
    {
        cout << "Error ... Invalid number of rooms. Try again.\n";
        cout << "Number of rooms to be painted (>=1): ";
        cin >> rooms;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return rooms;
}

int calcWallSpace(int rooms)
{
    // Collect square feet of wall space for each room
    int totalSquareFeet = 0;
    for(int i = 1; i <= rooms; ++i) // To get data from the getRooms() room number
    {
        int sqFeet; 
        cout << "Square feet of wall space (>=25): \n";
        cout << "\tRoom " << i << ": ";
        cin >> sqFeet; 

        // Do not accept a value less than 25 for the square feet of wall space in a room.
        while(sqFeet < 25)
        {
            cout << "Error ... Incorrect wall space for the room. Try again.\n";
            cout << "Square feet of wall space (>=25): ";
            cin >> sqFeet;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } 
         // Collect all the data for the Total Square Feet
    totalSquareFeet += sqFeet;
    } 
    return totalSquareFeet; 
}

void calcPaint(int sqFeet, double pricePaint, int& gallons, double& cost)
{
    gallons = (sqFeet + 114)/ 115; // Get the Number of Gallons
    cost = gallons * pricePaint; // Get the Cost of the Paint
    
    // Display Result 
    cout << "Paint ...\n";
    cout << "Gallons of Paint: " << setw(5) << gallons << endl;
    cout << "Cost of Paint: " << fixed << setprecision(2) << cost << endl; 
}

void calcLabor(int sqFeet, double& hours, double& cost)
{
    hours = (sqFeet * 8.0) / 115; // Calculate the total hours of labor
    cost = hours * 25.0; // Calculate labor charges 
    
    // Display Result 
    cout << "Labor ... \n";
    cout << "Hours of Labor: " << setw(5) << hours << endl;
    cout << "Cost of Labor: " << fixed << setprecision(2) << cost << endl;
}





