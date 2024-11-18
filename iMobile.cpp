// Name: Owen Chevelon
// 09/23/24
//Program Name: iMobile.cpp
/*
Short description: This program calculates a customer’s monthly bill. 
It should prompt the user for the customer’s plan and the number of gigabytes of data used. 
It should then calculate and display the total amount due.
*/


#include <iostream>
#include <string> 
#include <iomanip>
#include <limits>

using namespace std;

int main () {
    // Variables and Constants 
    const double PLAN_A_PRICE = 39.99, PLAN_B_PRICE = 59.99, PLAN_C_PRICE = 69.99;
    double number, price, gigabytes, package, packageA, packageB, packageC, planAData = 4, planBData = 8, planCData = numeric_limits<double>::infinity();

    // Intro 
    cout << "iMobile Bill Calculator ... " << endl;

    // Prompt user to select a number for package 
    cout << "Select a subscription package: " << endl; 
    cout << "Package: " << endl;
    cin >> number;

    // Determine which package user gets based off of number selected
    if (number == 1) {
        cout << "Package A";
    }
    else if (number == 2) {
        cout << "Package B";
    }
    else if (number == 3) {
        cout << "Package C";
    }
    else 
    cout << "Invalid number please try again";

    // Display amount due 
    cout << fixed << showpoint << setprecision(2); 
    cout << "How many gigabytes of data were used? " << endl;
    cin >> gigabytes; 
    cout << "The total amount due is $";
    cin >> price;

    return 0;




}