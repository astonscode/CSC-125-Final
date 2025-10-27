/*/*
 *CSC 175 W2 - Final Project
 #1#

#include <iostream>

using namespace std;

int main()
{

    bool continueGame = true;

    while (continueGame)
    {
        //create display menu function for here
        int choice;
        cout<<"Welcome to Blackjack!\n"
          "Please choose from the options below"<<endl;
        cout<<"1. Play Game\n"
              "2. Directions\n"
              "3. Hi-Scores\n"
              "4. Exit\n";

        cin>>choice;

        switch(choice)
        {
        case 0:

            break;
        case 1:
            //game logic
            cout<<"Playing game...\n"
                  "...Now we're done.\n\n";
            //Insert Gameplay function
            break;
        case 2:
            //Directions
            cout<<"This is how you play the game!\n\n";
            //Insert Directions display function
            break;
        case 3:
            //show hi-scores
            cout<<"Hi Scores!\n\n";
            //Insert Hi-scores display function
            break;
        case 4:
            continueGame = false;
            break;
        default:
            cout<<"Invalid choice.\n";
            break;


        }
    }
    cout<<"Thank you for playing. Goodbye!";

    return 0;
}*/