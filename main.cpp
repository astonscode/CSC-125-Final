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

void createDeck()
{

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

void displayHand(vector<string> deck,bool player)
{
   for (int card = 0; card < deck.size(); card++)
   {

      cout<<"["<<deck[card]<<"],";
      if (player)
      {

         playerScore += cardValue(playerHand[card],true);
      }
      else
      {
         dealerScore += cardValue(dealerHand[card],false);

      }

   }
}
void Gameplay()
{
   playerHand.clear();
   dealerHand.clear();
   loop = true;
   int option;

   createDeck();
   //Player bets
   //Cards are dealt
   playerHand.push_back(drawCard());
   playerHand.push_back(drawCard());

   dealerHand.push_back(drawCard());

   //add function for this loop? maybe not
   while (loop)
   {
      playerScore = 0;
      dealerScore = 0;

      //Show Dealer Hand
      displayHand(dealerHand,false);
      cout<<"\nDEALER: "<<dealerScore;
      cout<<"\n\n";

      //Show Player hand
      displayHand(playerHand,true);
      cout<<"\nPLAYER: "<<playerScore;
      cout<<"\n\n";


      //Create function to display In Game User Interface
      cout<<"1. Hit\n"
         "2. Stand\n"
            "3. Quit\n";

      cin>>option;
      switch (option)
      {
         //ace check set to automatically choose best option?
         case 1:
            cout<<"Player Hit.\n";
            playerHand.push_back(drawCard());
            break;
         case 2:
         cout<<"Player Stand.\n";
         //dealer logic
         dealerHand.push_back(drawCard());
         //display dealer card total
         //loop until dealer is over 16
         break;
         case 3:
         cout<<"Player Quit.\n";
         loop = false;
         break;

      default:
         cout<<"Invalid option.\n";
      }

      //Player decides to hit or stay
      //if 21 or less, dealer reveals card 2
      //if dealer has 16 or less, must hit. else, stand
   }


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