/*
 *CSC 175 W2 - Final Project
 */

#include <iostream>

using namespace std;

int main()
{

    int gameLoop = 0;

    while (gameLoop != -1)
    {

        switch(gameLoop)
        {
        case 0:
            //create display menu function for here
            cout<<"Welcome to Blackjack!\n"
              "Please choose from the options below"<<endl;
            cout<<"1. Play Game\n"
                  "2. Directions\n"
                  "3. Hi-Scores\n"
                  "4. Exit\n";
            cin>>gameLoop;
            break;
        case 1:
            //game logic
            cout<<"Playing game...\n"
                  "...Now we're done.\n\n";
            gameLoop = 0;
            break;
        case 2:
            //Directions
            cout<<"This is how you play the game!\n\n";
            gameLoop = 0;
            break;
        case 3:
            //show hi-scores
            cout<<"Hi Scores!\n\n";
            gameLoop = 0;
            break;
        case 4:
            gameLoop = -1;
            break;
        default:
            cout<<"Invalid choice.\n";
            gameLoop = 0;
            break;


        }
    }
    cout<<"Thank you for playing. Goodbye!";

    return 0;
}