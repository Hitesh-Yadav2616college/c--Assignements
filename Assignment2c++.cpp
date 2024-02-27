#include<iostream>
#include<ctime>

using namespace std;
class GuessTheGame {
private:
 int computerGeneratedNumber;
 int userGussedNumber;
 int static attempts;
  public:
  void genrateRandomNumber() {
    srand(static_cast<unsigned int>(time(nullptr)));

    computerGeneratedNumber = (rand()%100)+1;
  }
  void startGame() {
     cout << endl << "..........Welcome to the GUESS THE NUMBER game.........." << endl;
     cout << "Enter '-1' whenever you want to take exit" << endl;

     genrateRandomNumber();
     while(true) {
         cout << "Guess the  number: ";
     cin >> userGussedNumber;
     if(userGussedNumber==-1) exit(0);
     cout << "Attempt: " << ++attempts;
     if(userGussedNumber==computerGeneratedNumber)  {
     cout << endl << "Congratulations you won the game in " << attempts << " attempts :)";
     exit(0);
     }
     if(userGussedNumber>computerGeneratedNumber) cout << endl << "Message: Guessed number is greater than computer generated number!" << endl;
     else cout << endl << "Message: Guessed number is smaller than computer generated number!" << endl;
  }
     }
};
int GuessTheGame::attempts=0;
int main() {
    GuessTheGame g;
    g.startGame();
}