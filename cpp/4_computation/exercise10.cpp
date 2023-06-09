#include "std_lib_facilities.h"

const vector<string> hands = {"rock", "paper", "scissors"};

bool isHand(string hand)
{
  for (string h : hands)
  {
    if (h == hand)
      return true;
  }
  return false;
}

int main()
{
  string hand = "";
  string cphand = "";
  string randomizer;
  int rand = 0;
  int score = 0;
  int cpscore = 0;
  cout << "Enter some random values!\n";
  cin >> randomizer;
  cout << "Rock, Paper, Scissors!\n";
  while (cin >> hand)
  {
    if (hand == "|")
      break;
    if (!isHand(hand))
    {
      cout << "Wrong input! Try again!\n"
           << "Rock, Paper, Scissors!\n";
      continue;
    }
    rand = (rand + 1) % randomizer.size();
    cphand = hands[randomizer[rand] % hands.size()];

    cout << "You choose " << hand << " and Computer choose "
         << cphand << '\n';

    if (hand[0] == cphand[0])
      cout << "DRAW!\n";
    switch (hand[0])
    {
    case 'r':
      switch (cphand[0])
      {
      case 's':
        cout << "You win!\n";
        score++;
        break;
      case 'p':
        cout << "Computer win!\n";
        cpscore++;
        break;
      }
      break;
    case 'p':
      switch (cphand[0])
      {
      case 'r':
        cout << "You win!\n";
        score++;
        break;
      case 's':
        cout << "Computer win!\n";
        cpscore++;
        break;
      }
      break;
    case 's':
      switch (cphand[0])
      {
      case 'p':
        cout << "You win!\n";
        score++;
        break;
      case 'r':
        cout << "You lose!\n";
        cpscore++;
        break;
      }
      break;
    }
    cout << "Score so far: " << score << ":" << cpscore << '\n';
  }
  cout << "Final score: " << score << ":" << cpscore << '\n';
  if (score > cpscore)
    cout << "You win!\n";
  else if (score < cpscore)
    cout << "Computer win!\n";
  else
    cout << "Draw!\n";
}
