/*
    Initialize Variables

Set credits to 0 (for tracking player's progress).
Seed random number generator.
Display Main Menu

Show options: 1) Game Rules & Instructions, 2) Start Game, 3) Quit.
Read user choice.
Process User's Menu Choice

If choice is 1:
Display game rules.
If choice is 2:
Start the game loop.

Reset credits to 0.

Define arrays for cards (messages) and cardValues (credit effects).

Initialize cardUsed array to keep track of used cards.

While credits < 30:

Roll the dice and add the result to credits.

Draw a random unused card:

Display card message.
Apply cardValue to credits.
Mark card as used.
Display updated credits.

If credits >= 30:

Display winning message and break the loop.
Ask user if they want to roll again:

If "no," exit the game loop.
If choice is 3:
Display exit message and end the program.
If choice is invalid:
Prompt user to enter a valid option. Repeat menu display.
End Program

*/



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function prototypes
void displayRules();
int rollDice();
void drawCard(int &credits, bool cardUsed[], const char* cards[], int cardValues[], int numOfCards);

int main() 
{
    int credits = 0;       // Player's progress in credits
    int choice;            // Menu choice

    // Seed for random number generation
    srand(static_cast<unsigned int>(time(0)));

    // Main menu loop
    while (true) 
    {
        cout << "\nWelcome to the Graduation Game!\n";
        cout << "1) Game Rules & Instructions\n";
        cout << "2) Start Game\n";
        cout << "3) Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) 
        {
            displayRules();
        } else if (choice == 2) 
        {
            // Reset credits and card usage for a new game
            credits = 0;
            const char* cards[] = 
            {
                "Failed a big exam, lost progress. (-3 credits)",
                "Skipped too many classes, setback! (-2 credits)",
                "Completed a big project, moved ahead. (+3 credits)",
                "Helped classmates, gained a boost. (+2 credits)",
                "Late submission, slight penalty. (-1 credit)"
            };

            int cardValues[] = { -3, -2, 3, 2, -1 };
            const int numOfCards = sizeof(cards) / sizeof(cards[0]);
            bool cardUsed[numOfCards] = { false };  // Track used cards

            // Game loop
            while (credits < 30) 
            {
                // Roll the dice and update credits with both dice roll and card effect
                int diceRoll = rollDice();
                credits += diceRoll;  // Add dice roll to credits first

                // Draw a card after moving forward
                drawCard(credits, cardUsed, cards, cardValues, numOfCards);

                // Display updated credits
                cout << "Total credits after dice roll and card effect: " << credits << endl;

                // Check if they reached the goal
                if (credits >= 30) 
                {
                    cout << "Congratulations! You've earned enough credits to graduate!\n";
                    break;
                }

                // Ask if they want to roll again
                char rollAgain;
                cout << "Roll again? (y/n): ";
                cin >> rollAgain;
                if (rollAgain != 'y' && rollAgain != 'Y') 
                {
                    cout << "Thanks for playing!\n";
                    break;
                }
            }
        } else if (choice == 3) 
        {
            cout << "Exiting the game. Goodbye!\n";
            break;  // Exit the main menu loop
        } else 
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

// Function to display game rules
void displayRules() 
{
    cout << "\nGame Rules:\n";
    cout << "In this game, you're trying to earn enough credits to graduate.\n";
    cout << "Each dice roll moves you forward, and each card either helps or hinders your progress.\n";
    cout << "Reach 30 credits to graduate!\n";
}

// Function to roll the dice and return the roll value
int rollDice() 
{
    int diceRoll = (rand() % 6) + 1;  // Random number between 1 and 6
    cout << "You rolled a " << diceRoll << "!\n";
    return diceRoll;
}

// Function to draw a random card, apply its effect, and show the card’s effect and total credits
void drawCard(int &credits, bool cardUsed[], const char* cards[], int cardValues[], int numOfCards) 
{
    int cardIndex;
    do 
    {
        cardIndex = rand() % numOfCards;
    } while (cardUsed[cardIndex]);  // Pick an unused card

    cout << "\nCard drawn: " << cards[cardIndex] << endl;
    cout << "Effect on credits: " << (cardValues[cardIndex] > 0 ? "+" : "") << cardValues[cardIndex] << " credits" << endl;

    credits += cardValues[cardIndex];  // Apply the card's value to credits

    cardUsed[cardIndex] = true;  // Mark the card as used
}

