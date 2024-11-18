// Owen Chevelon 

/*
Input:
File containing the following course data:
Course Number & Description
Instructor Name
Term
For each student:
Student Name
Student Grade (0-100)
Processing:
Display menu:

Option 1: Process Grades Summary report.
Option 2: Quit.
Prompt user for choice.

Drive menu options:

Case 1 - Process Grades Summary report:

Prompt user for the file name containing the course data.
Open the file for input.
Read the course details (course number, instructor name, term).
Display course details.
While there are student records in the file:
Read the student's name and grade.
Display student name and grade.
Track the highest, lowest, and total grades.
Calculate the average grade.
Display the following:
List of students and their grades.
Highest grade in the class.
Lowest grade in the class.
Average grade in the class (formatted to 1 decimal place).
Close the file.
If the file doesn't exist or can't be opened, display an error message.
Case 2 - Quit:

Display exit message.
End the program.

*/




#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    // Constants for menu options
    const int PROCESS_GRADES = 1;
    const int QUIT = 2;

    int choice;          // User's menu choice
    string filename;     // Course file name
    fstream file;        // File stream object

    string courseDesc, instructorName, term;
    string studentName;
    int grade;
    int highestGrade = -1, lowestGrade = 101, totalGrades = 0, gradeCount = 0;
    double averageGrade = 0.0;

    // Introduction
    cout << "\nCourse Summary App\n";

    do
    {
        // Display menu and prompt user for choice
        cout << "\nChoose one of the following options:\n";
        cout << "1. Process Grades Summary report.\n";
        cout << "2. Quit.\n";
        cout << "Option: ";
        cin >> choice;

        // Process menu options
        switch (choice)
        {
        case PROCESS_GRADES:
            // Prompt user for the course file name
            cout << "\nEnter the file name storing the course information: ";
            cin >> filename;

            // Open file for reading
            file.open(filename.c_str(), ios::in);
            if (!file)
            {
                cout << "Error: File \"" << filename << "\" could not be opened.\n";
                break;
            }

            // Read the course description, instructor name, and term
            getline(file, courseDesc);
            getline(file, instructorName);
            getline(file, term);

            // Process student grades
            cout << "\nProcessing Grades Summary Report...\n";
            cout << "\nCourse: " << courseDesc << "\nInstructor: " << instructorName << "\nTerm: " << term << "\n";
            cout << "\nList of Students and their Grades:\n";
            cout << left << setw(25) << "Student Name" << "Grade\n";
            cout << "------------------------------------\n";

            while (getline(file, studentName))
            {
                file >> grade;
                file.ignore(); // Ignore the newline after the grade

                // Display student name and grade
                cout << left << setw(25) << studentName << grade << endl;

                // Calculate highest, lowest, and average grade
                if (grade > highestGrade) highestGrade = grade;
                if (grade < lowestGrade) lowestGrade = grade;

                totalGrades += grade;
                gradeCount++;
            }

            // Close the file
            file.close();

            if (gradeCount > 0)
            {
                // Calculate average grade
                averageGrade = static_cast<double>(totalGrades) / gradeCount;

                // Display summary
                cout << "\nSummary:\n";
                cout << "Highest Grade: " << highestGrade << "\n";
                cout << "Lowest Grade: " << lowestGrade << "\n";
                cout << "Average Grade: " << fixed << showpoint << setprecision(1) << averageGrade << "\n";
            }
            else
            {
                cout << "\nNo student data found in the file.\n";
            }
            break;

        case QUIT:
            cout << "\nExiting the program. Goodbye!\n";
            break;

        default:
            cout << "Error: Invalid option. Please try again.\n";
        }
    } while (choice != QUIT);

    return 0;
}
