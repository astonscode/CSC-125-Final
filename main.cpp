#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

std::vector<std::string> cards = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
//std::vector<std::string> suits = {"♠", "♣︎", "♦︎", "♥︎"};
std::vector<std::string> suits = {"S", "C", "D","H"};
vector<string> deck;
vector<string> playerHand;
vector<string> dealerHand;

int dealerScore, playerScore;

bool loop = true;

void createDeck();
string drawCard(vector<string> cards);
int cardValue(string card, bool player);
void displayHand(vector<string> deck,bool player);
void calculateDealerHand();
void calculatePlayerHand();
void Gameplay();
void MainMenu();


/*void gameEnd()
{
   if (score == 21)
   {
      std::cout << "You have reached 21!";
   }
   else if (score > 21)
   {
      std::cout << "You exceeded 21...\nYou lost...";
   }
}*/
int main()
{
   srand(time(0));
   MainMenu();

   return 0;
}

void MainMenu()
{
   bool continueGame = true;

   while (continueGame)
   {

      //create display menu function for here
      int option;
      cout<<"Welcome to Blackjack!\n"
        "Please choose from the options below"<<endl;
      cout<<"1. Play Game\n"
            "2. Directions\n"
            "3. Hi-Scores\n"
            "4. Exit\n";

      cin>>option;

      switch(option)
      {

      case 1:
         //Play Game
         Gameplay();

         break;
      case 2:
         //Directions
         cout<<"This is how you play the game!\n\n";
         //Insert Directions display function
         break;
      case 3:
         //Hi-Scores
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
}

void createDeck()
{
   deck.clear();
   for (int suit = 0; suit < 4; suit++)
   {
      for (int card = 0; card < 13; card++)
      {
         deck.push_back(cards[card] + suits[suit]);

      }
   }

}

string drawCard()
{

   if (deck.empty())
   {cout<<"Deck is empty.\n";}

   int randomCard = rand() % deck.size();
   string card = deck[randomCard];

   deck.erase(deck.begin() + randomCard);
   return card;
}

//split into two functions for dealer and player?
int cardValue(string card, bool player)
{
   if ((card[0] == '1' && card[1]=='0')||card[0] == 'K' || card[0]== 'Q' || card[0]== 'J')//10 check
   {
      return 10;
   }
   else if (card[0] == 'A')
   {
      //Ace logic
      if (player)//doesn't need player tag unless we're implementing soft 17
      {
         if (playerScore + 11 > 21)
         {
            return 1;
         }
         else
         {
            return 11;
         }
      }
      else
      {
         //dealer
         if (dealerScore + 11 == 17 || dealerScore + 11 >21)
         {
            return 1;
         }
         return 11;
      }

   }


   return stoi(card);


}

void calculatePlayerHandValue()
{
   playerScore = 0;

   for (int card = 0; card < playerHand.size(); card++)
   {
      playerScore += cardValue(playerHand[card], true);
   }

}


void calculateDealerHandValue()
{
   dealerScore = 0;
   for (int card = 0; card < dealerHand.size(); card++)
   {
      dealerScore += cardValue(dealerHand[card], false);
   }
}

//split into two functions for player and dealer
void displayHand(vector<string> deck,bool player)
{


   for (int card = 0; card < deck.size(); card++)
   {
      cout<<"["<<deck[card]<<"],";
   }
   if (player)
   {
      cout<<"\nPLAYER: "<<playerScore;
      cout<<"\n\n";
   }
   else
   {
      cout<<"\nDEALER: "<<dealerScore;
      cout<<"\n\n";
   }
}

void resetHand()
{

   playerHand.clear();
   dealerHand.clear();

   createDeck();
   playerHand.push_back(drawCard());
   playerHand.push_back(drawCard());

   dealerHand.push_back(drawCard());


}

void dealerLogic()
{
   bool logic = true;
   //dealerHand.push_back(drawCard());
   while (logic)
   {


      calculateDealerHandValue();



      if (dealerScore > 21)
      {
         cout<<"-----------------------------------\n";
         cout<<"\nDealer busts. Player wins.\n\n";
         displayHand(dealerHand,false);
         displayHand(playerHand, true);
         cout<<"-----------------------------------\n";
         logic = false;


         //pay player
      }
      else if (dealerScore > playerScore && dealerScore >16)
      {
         cout<<"-----------------------------------\n";
         cout<<dealerScore<<". Player loses. \n\n";
         displayHand(dealerHand,false);
         displayHand(playerHand,true);
         cout<<"-----------------------------------\n";
         logic = false;

      }

      else if (dealerScore <= 16)
      {
         dealerHand.push_back(drawCard());
         calculateDealerHandValue();
         displayHand(dealerHand,false);
         displayHand(playerHand, true);
         continue;

      }
      else if (dealerScore == playerScore)
      {
         cout<<"-----------------------------------\n";
         cout<<"\nPush.\n\n";
         displayHand(dealerHand,false);
         displayHand(playerHand, true);
         cout<<"-----------------------------------\n";

         logic = false;
      }
      else if (dealerScore <21 && playerScore == 21)
      {
         cout<<"-----------------------------------\n";
         cout<<"\nBlackjack! Player Wins!\n\n";
         displayHand(dealerHand,false);
         displayHand(playerHand, true);
         cout<<"-----------------------------------\n";
         logic = false;
      }

      dealerHand.push_back(drawCard());
   }

   resetHand();

}

void Gameplay()
{
   loop = true;
   int option;

   //Player bets
   resetHand();


   while (loop)
   {
      //Show Dealer Hand
      calculateDealerHandValue();
      displayHand(dealerHand,false);

      //Show Player hand
      calculatePlayerHandValue();
      displayHand(playerHand,true);

      //blackjack on first hand check
      if (playerScore == 21)
      {
         //add dealer logic check to see if they get 21 too.
         dealerLogic();
         continue;

         //add to winnings
      }

      //Create function to display In Game User Interface
      cout<<"1. Hit\n"
         "2. Stand\n"
            "3. Quit\n";
      cin>>option;

      switch (option)
      {
         //ace check set to automatically choose best option
         case 1:
            cout<<"-----------------------------------\n";
            cout<<"\nPlayer Hit.\n";
            playerHand.push_back(drawCard());
            calculatePlayerHandValue();
            //

            if (playerScore > 21)
            {
               cout<<"-----------------------------------\n";
               displayHand(playerHand,true);
               cout<<playerScore <<" - PLAYER BUSTS!\n\n";
               cout<<"-----------------------------------\n";

               //Remove bet amount from player's funds

               resetHand();

               continue;

            }
            else if (playerScore == 21)
            {
               //Check if dealer gets 21 first. if not, blackjack player wins
               dealerLogic();

               //Add payout to total player funds

               resetHand();
               continue;
            }

            //displayHand(dealerHand,false);

            break;

         case 2:
         cout<<"-----------------------------------\n";
            cout<<"\nPlayer Stand.\n\n";
            //dealer logic
            dealerLogic();
         cout<<"-----------------------------------\n";
            break;
         case 3:
         cout<<"-----------------------------------\n";
         cout<<"Player Quit.\n";
         cout<<"-----------------------------------\n";
         loop = false;
         break;

      default:
         cout<<"-----------------------------------";
         cout<<"Invalid option.\n";
         cout<<"-----------------------------------\n";
      }
      //resetHand();
      //Player decides to hit or stay
      //if 21 or less, dealer reveals card 2
      //if dealer has 16 or less, must hit. else, stand
   }


}

