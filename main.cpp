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
std::vector<std::string> played;

int score;
bool loop = true;

void gameEnd()
{
   if (score == 21)
   {
      std::cout << "You have reached 21!";
   }
   else if (score > 21)
   {
      std::cout << "You exceeded 21...\nYou lost...";
   }
}

void updateScore(std::string value)
{
   if (value == "J" || value == "Q" || value == "K")
   {
      score = score + 10;
   }
   else
   {
      score = score + std::stoi(value);
   }

   std::cout << "\nYour score is now " << score << ".\n";

   if (score >= 21)
   {
      gameEnd();
   }
}

std::string checkAce(std::string suit)
{ // Asks the user to either treat their A as a 1 or an 11.
   if (score + 11 > 21)
   {
      return "1";
   }
   else
   {
      int choice;
      bool chosen = false;

      while (!chosen)
      {
         std::cout << score << " - Would you like to treat this A of " << suit << " as a 1 or an 11?\n[1] 1\n[2] 11\n> ";

         std::cin >> choice;

         if (choice == 1)
         {
            std::cout << "Your A of " << suit << " was treated as a 1.";
            chosen = true;
            return "1";
         }
         else if (choice == 2)
         {
            std::cout << "Your A of " << suit << " was treated as an 11.";
            chosen = true;
            return "11";
         }
         else
         {
            std::cout << "Invalid.\n";
            chosen = false;
         }
      }
      return "0";
   }
}

bool alreadyPlayed(const std::string card)
{
   for (const std::string c : played)
   {
      if (c == card)
      {
         return true;
      }
   }
   return false;
}

void play(int x)
{
   int totalCards = cards.size() * suits.size();
   if (x > totalCards)
      x = totalCards;

   int i = 0;
   while (i < x)
   {
      int randomInt = rand() % 13;
      int ranNum = rand() % 4;
      std::string pick = cards[randomInt] + " (" + suits[ranNum] + ")";

      if (!alreadyPlayed(pick))
      {
         if (cards[randomInt] == "A")
         {
            updateScore(checkAce(suits[ranNum]));
         }
         else
         {
            std::cout << pick << " - " << -1 * played.size() + 51 << " cards remaining.\n";
            played.push_back(pick);
            i++;
            updateScore(cards[randomInt]);
         }
      }
   }
}

void nextTurn()
{
   std::cout << "Continuing...";
   loop = false;
}

void choice()
{
   bool chosen = false;
   int decision;
   while (!chosen)
   {
      std::cout << "Your score is " << score << ". What would you like to do?\n[1] Hit (Draw) \n[2] Stand (DEALER's turn)\n> ";
      std::cin >> decision;
      if (decision == 1)
      {
         play(1);
         chosen = true;
      }
      else if (decision == 2)
      {
         nextTurn();
         chosen = true;
      }
      else
      {
         chosen = false;
      }
   }
}

//Matt Code
vector<string> deck;
vector<string> playerHand;
vector<string> dealerHand;

int dealerScore, playerScore;

void createDeck()
{

   for (int suit = 0; suit < 4; suit++)
   {
      for (int card = 0; card < 13; card++)
      {
         deck.push_back(cards[card] + " " + suits[suit]);

      }
   }

}

string drawCard(vector<string> deck)
{

   if (deck.empty())
   {cout<<"Deck is empty.\n";}

   int randomCard = rand() % deck.size();
   string card = deck[randomCard];

   deck.erase(deck.begin() + randomCard);
   return card;
}

int cardValue(char card)
{
   if (card == 'K' || card == 'Q' || card == 'J')
   {
      return 10;
   }
   else if (card == 'A')
   {
      //Ace logic
      return 11; //set to 11 for now.
   }
   else
   {
      string belowTen = "";
      belowTen +=card;
      return stoi(belowTen);
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
   playerHand.push_back(drawCard(deck));
   playerHand.push_back(drawCard(deck));

   dealerHand.push_back(drawCard(deck));

   //add function for this loop? maybe not
   while (loop)
   {
      playerScore = 0;
      dealerScore = 0;

      //add Hand Function - pass through vector to replace these loops
      for (int card = 0; card < dealerHand.size(); card++)
      {

         cout<<"["<<dealerHand[card]<<"],";
         dealerScore += cardValue(dealerHand[card][0]);
        //cout<<cardValue(dealerHand[card][0]);//use updateScore function
      }
      cout<<"\nDEALER: "<<dealerScore;
      cout<<"\n\n";

      for (int card = 0; card < playerHand.size(); card++)
      {
         cout<<"["<<playerHand[card]<<"],";
         playerScore += cardValue(playerHand[card][0]);
      }
      cout<<"\nPLAYER: "<<playerScore;
      cout<<"\n\n";
      //display value of cards showing for player and dealer

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
            playerHand.push_back(drawCard(deck));
            break;
         case 2:
         cout<<"Player Stand.\n";
         //dealer logic
         dealerHand.push_back(drawCard(deck));
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
int main()
{
   srand(time(0));
   /*while (loop)
   {
      choice();
   }*/

   MainMenu();


   // score = rand() % 10;
   // int rnd = rand() % 4;
   // checkAce(suits[rnd]);
   return 0;
}