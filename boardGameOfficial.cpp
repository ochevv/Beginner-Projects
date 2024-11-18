#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    // Variables For log in screen 
    int number;

    // Log in Screen 
    cout << "Welcome To The ....\n";
    cout << "𐌕𐋅𐌄 𐌂𐋅Ꝋ𐌔𐌄𐌍 𐌃𐌉𐌔𐌂𐌉𐌐𐌋𐌄" << endl; 
    cout << "Please Choose a Menu Option to Proceed.\n";
    cout << " " << endl; 
    cout << "1) Game Rules & Instructions\n";
    cout << "2) Start Game!\n";
    cout << "3) Quit \n";
    cin >> number; 

    // Regardless of User Input Rules Will Display
    if (number == 1) {
        cout << "WELCOME BROTHERS & SISTERS \n"; 
        cout << "Please Read Game Rules Down Below Carefully...\n";
        cout << "You have been handpicked from Jesus Christ himself to complete this mission.\n";
        cout << "Your Goal is to get to the New Testament by going through the Old Testament.\n";
        cout << "Each space on the board represents an old testament book, there will be a total of 39 spaces to get through.\n";
        cout << "You will have to get through all 39 board spaces before you run out of cards.\n";
        cout << "It will be difficult at first but, you have been chosen for a reason! \n";
        cout << "You will begin in The Garden of Eden aka The book of Genesis (the first space on the board) \n";
        cout << "To begin moving you must first roll a dice. Depending on what number the dice lands on is how much spaces you get to move before picking up a card. \n";
        cout << "There are 11 cards. 6 Spiritual Disturbances & 5 Blessings. Each card will determine your next move before you roll the dice again.\n";
        cout << "NOW IT IS TIME TO START YOUR JOURNEY, GOOD LUCK MAY THE LORD BE WITH YOU!\n";
    }

    // Variables for game play 
    int boardSpace = 0, diceRoll, rollDice;

    // Game loop
    while (true) {
        cout << "\n1) Start Game!\n";
        cout << "2) Quit \n";
        cin >> number;

        if (number == 2) {
            cout << "Thanks for playing!\n";
            break; // Exit the game loop
        }

        // Start Game
        if (number == 1) {
            cout << "GAME ON!" << endl;
            cout << "Start off by rolling the dice (Press the number 6 key)" << endl;
            rollDice = 6;
            cin >> rollDice;

            if (rollDice == 6) {
                // To roll dice
                srand(static_cast<unsigned int>(time(0))); // random seed 
                diceRoll = (rand() % 6) + 1;
                cout << "You rolled a: " << diceRoll << " You may move " << diceRoll << " spaces forward!\n";

                // Define the set of cards with an array
                const char* cards[] = {
                    // Spiritual Disturbance Cards
        "SPIRITUAL DISTURBANCE\n\n"
        "You were walking sand and you accidentally stepped on a thorn. You then Yell OH MY GOD! THAT STUPID THORN. "
        "You did not mean to pray or address God directly, but rather you vent your anger in the moment.\n\n"
        "You Have used the Lord's name in vain\n\n"
        "Exodus 20:7 - You shall not take the name of the Lord your God in vain, for the Lord will not hold him guiltless "
        "who takes his name in vain\n\n( - 3 spaces )",

        "SPIRITUAL DISTURBANCE\n\n"
        "You are continuing your journey and you come across a prostitute. She stops you and starts seducing you and would like to have sex. "
        "You allow her to successfully seduce you and get distracted.\n\n"
        "You fell into lust, and Committed Adultery\n\n"
        "Exodus 20:14  - Thou shall not commit adultery\n\n( - 4 spaces )",

        "SPIRITUAL DISTURBANCE\n\n"
        "You are continuing your journey walking your path. You are exhausted, hungry, and very thirsty. You see a little shop ran by a small family. "
        "Out of sheer desperation, you grab a couple of things and leave without paying.\n\n"
        "You Stole!\n\n"
        "Exodus 20:15 - Thou shall not steal\n\n( - 4 spaces )",

        "SPIRITUAL DISTURBANCE\n\n"
        "You run into a crowd charging at you asking what you are doing here by yourself. You do not wish to tell them, so you lie.\n\n"
        "You have Lied!\n\n"
        "Leviticus 19:11 - Do not steal. Do not lie. Do not deceive one another.\n\n( - 4 spaces )",

        "SPIRITUAL DISTURBANCE\n\n"
        "You see a crazy man and he starts charging at you. Out of pure instinct, you pull out your pocket knife and stab him multiple times in panic.\n\n"
        "YOU HAVE COMMITTED MURDER!\n\n"
        "Exodus 20:13 - You must not murder\n\n( - 6 spaces )",

        "SPIRITUAL DISTURBANCE\n\n"
        "You come across people racing and they ask if you want to join. You get cocky and say you have won already. You lose after not being humble.\n\n"
        "You were too prideful\n\n( - 3 spaces )",

        // Blessing Cards
        "BLESSING\n\n"
        "You were walking and you come across an old man with a wound on his leg. You wrapped the wound and prayed for him to heal.\n\n"
        "This was a great act of kindness!\n\n( + 3 spaces )",

        "BLESSING\n\n"
        "You have been granted 2 free spaces!\n\n( + 2 spaces )",

        "BLESSING\n\n"
        "You start to get discouraged, but then you remember that God is good. You pray for strength.\n\n"
        "Good Job keeping your faith strong!\n\n( + 2 spaces )",

        "BLESSING\n\n"
        "You have been granted 1 free space!\n\n( + 1 space )",

        "BLESSING\n\n"
        "Devoting oneself to doing good: Titus 3:8 says to devote oneself to doing what is good.\n\n( + 2 spaces )"
                };

                // Corresponding values for the cards
                int cardValues[] = {-3, -4, -4, -4, -6,-3, 3, 2, 2, 1, 2};
                const int numOfCards = sizeof(cards) / sizeof(cards[0]);
                bool cardUsed[numOfCards] = {false}; // Track used cards

                // Game loop for card picking
                while (true) {
                    // Check if all cards are used
                    bool allUsed = true;
                    for (int i = 0; i < numOfCards; i++) {
                        if (!cardUsed[i]) {
                            allUsed = false;
                            break;
                        }
                    }

                    if (allUsed) {
                        cout << "No more cards left! Game over!\n";
                        break; // Exit the card picking loop
                    }

                    // Randomly pick a card that hasn't been used
                    int randomIndex;
                    do {
                        randomIndex = rand() % numOfCards;
                    } while (cardUsed[randomIndex]);

                    cout << "Your card has been selected:\n\n" << cards[randomIndex] << endl;


                    // Board Space Calculation 
                    boardSpace += diceRoll + cardValues[randomIndex];

                    // Display Dice Roll and Current Board Space
                    cout << "Dice roll: " << diceRoll << endl;
                    cout << "Your Current Board Space: " << boardSpace << endl;

                    // Mark the card as used
                    cardUsed[randomIndex] = true;

                    if(boardSpace >= 39) {
                        cout << "YOU HAVE made it to the New Testament! CONGRATULATIONS !!!\n";
                        break; // Exit the card picking loop and end the game
                    }

                    // Ask to roll again or end the game
                    char choice;
                    cout << "Would you like to roll again? (y/n): ";
                    cin >> choice;

                    if (choice != 'y' && choice != 'Y') {
                        break; // Exit the card picking loop
                    }

                    // Roll dice again
                    diceRoll = (rand() % 6) + 1;
                }
            }
        } // Exit the main game loop if boardSpace >= 39
        if (boardSpace >= 39) {
            break;
        }
    } 

    return 0;
}
