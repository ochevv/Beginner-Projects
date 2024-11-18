/*
   
1. Initialize and input validation: 
   
   Initialize a 3x3 array square.
   Prompt the user to enter 9 unique numbers between 1 and 9.
   For each input number:
   Validate it is between 1 and 9 and hasn’t been entered before.
   If valid, store it in the array square, filling row by row, left to right.
   If invalid, prompt the user again for a valid input.

2. Display the Square:

   Print the 3x3 array square in a grid format.

3. Check Row, Column, and Diagonal Sums:

   Define a function isMagicSquare that:
   Checks if each row sums to 15.
   Checks if each column sums to 15.
   Checks if the two diagonals each sum to 15.
   If all checks pass, return true; otherwise, return false.

4. Main Execution:
   
   Call isMagicSquare on the user-input square.
   If true, print “This is a Lo Shu Magic Square.”
   If false, print “This is not a Lo Shu Magic Square.”

*/

#include <iostream>
#include <iomanip>
#include <set>

using namespace std;

const int SIZE = 3; // 


// Function Prototypes
void enterUserNumbers(int squares[][SIZE]);
void displaySquare(const int squares[][SIZE]);
bool isMagicSquare(const int sqaures[][SIZE]);

int main() 
{
   int squares[SIZE][SIZE]; // 3x3 grid for magic square
   
   cout << "Creating Lo Shu Square ... \n";
   enterUserNumbers(squares); // Call the function to fill the square
   displaySquare(squares); // Call the function to display the 3x3 array 

   if(isMagicSquare(squares)) // Check if it is a magic square
   {
      cout << "This is a Lo Shu Magic Square !!!!";
   }
   else 
   {
      cout << "Sorry ... this is not Lo Shu Magic Square. \n\n";
   }

   return 0;

}


void enterUserNumbers(int squares[][SIZE]) // Pass array by reference for modification
{
   set<int> enteredNumbers; // Store unique numbers
   int number; // to hold each entered number

    cout << "Enter Nine Numbers (1-9) \n";

   // Loop through to get user input for each element
   for (int rows = 0; rows < SIZE; ++rows) 
   {
      for (int cols = 0; cols < SIZE; ++cols) 
      {
         do
         {
            cout << "Enter a Number for Row " << rows + 1 << " Column " << cols + 1 << ": ";
            cin >> number;
            
            // Set Number range
            if(number < 1 || number > 9)
             {
               cout << "Invalid number. Must be a number 1 - 9!\n";
               continue;
             }
               // Make sure there are no duplicates
             if(enteredNumbers.find(number) != enteredNumbers.end())
             {
               cout << "This number has already been entered \n";
               continue; 
             }
               break; // break meaning Input is valid
         }

         while(true);
         
         // Store only the valid numbers in the sqaure & add it to enteredNumbers set 
         squares[rows][cols] = number;
         enteredNumbers.insert(number);
      }
   }
}

void displaySquare(const int squares[][SIZE])
{
   // Top border
   cout << "-------------\n";
   for(int rows = 0; rows < SIZE; ++rows)
   {
      cout << "| "; // Side Borders for each columns 
      for(int cols = 0; cols < SIZE; ++cols)
      {
         cout << squares[rows][cols] << " | "; // Display Number & side bar
      }
       cout << "\n-------------\n"; // Bottom Border 
   } 
}


bool isMagicSquare(const int squares[][SIZE])
{
   int magicSquareSum = 15; // the sum each row and column and diagnols should have

   // Check Rows
   for(int rows = 0; rows < SIZE; ++rows)
   {
         int rowSum = 0; 
         for(int cols = 0; cols < SIZE; ++cols)
         {
            rowSum += squares[rows][cols];
         }
         if(rowSum != magicSquareSum)
         return false; 
   }

   // Check Columns 
   for(int cols = 0; cols < SIZE; ++cols)
   {
      int colSum = 0; 
      for(int rows = 0; rows < SIZE; ++rows)
      {
         colSum += squares[rows][cols];
      }
      if(colSum != magicSquareSum)
      return false;
   }

   // Check diagnols
   int diagnolSum1 = squares[0][0] + squares[1][1] + squares[2][2];
   int diagnolSum2 = squares[0][2] + squares[1][1] + squares[2][0];
   if(diagnolSum1 != magicSquareSum || diagnolSum2 != magicSquareSum) return false;

   return true; // It's a magic square 

}



