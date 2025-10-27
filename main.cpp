#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

std::vector<std::string> cards = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
std::vector<std::string> suits = {"♠︎", "♣︎", "♦︎", "♥︎"};
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
void Gameplay()
{
   //player gets two cards face up
   //dealer gets 1 card face up
   //player hits - gets 1 card face up. Total updates - if over 21, get 1 strike (3 strikes game over). Deal next hand
   //player stands - dealer gets 1 card face up. If card value is <= 16, dealer must hit. otherwise, stand
   //if dealer busts but player doesn't, 1 point to score
   //if player has higher card value, 1 point to score
   //if player has lower card value, 1 strike, next hand

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
         //game logic
         play(1);
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