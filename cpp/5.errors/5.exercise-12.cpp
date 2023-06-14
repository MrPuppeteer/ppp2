#include "std_lib_facilities.h"

bool guess_check(string guess, int len);
vector<int> parse_guess(string guess);
int get_bulls(vector<int> guess, vector<int> answer);
int get_cows(vector<int> guess, vector<int> answer);

int main()
try
{
  vector<int> answer = {1, 2, 3, 4};
  int bulls = 0;
  int cows = 0;
  string guess = "0000";
  cout << "Welcome to Bulls and Cows!\n"
       << "Guess a xenodrome 4 digits number\n"
       << "with 'bulls' being correct digits\n"
       << "and 'cows' being correct digits but in the wrong position\n"
       << "Your guess?\n";
  while (bulls != 4)
  {
    cin >> guess;

    if (!guess_check(guess, answer.size()))
    {
      cout << "Another guess?\n";
      continue;
    }

    vector<int> parsed_guess = parse_guess(guess);
    bulls = get_bulls(parsed_guess, answer);
    cows = get_cows(parsed_guess, answer);

    cout << "You've got " << bulls << " bulls\n"
         << "and " << cows << " cows\n";
    if (bulls != 4)
    {
      cout << "Another guess?\n";
    }
  }

  bulls == 4
      ? cout << "Congratulations! You guessed it right!\n"
      : cout << "Better luck next time!\n";

  return 0;
}
catch (exception &e)
{
  cerr << "error: " << e.what() << '\n';
  return 1;
}
catch (...)
{
  cerr << "Oops: unknown exception!\n";
  return 2;
}

bool guess_check(string guess, int len)
{
  if (guess.length() != len)
  {
    cerr << "guess must be " << len << " digits length!\n";
    return false;
  }

  for (char c : guess)
  {
    if (c < '0' || c > '9')
    {
      cerr << "guess must be numbers!\n";
      return false;
    }
  }

  for (int i = 0; i < len - 1; ++i)
    for (int j = i + 1; j < len; ++j)
      if (guess[i] == guess[j])
      {
        cerr << "guess must be a non-repeated numbers\n";
        return false;
      }
  return true;
}

vector<int> parse_guess(string guess)
{
  vector<int> res;
  for (char c : guess)
    res.push_back(c - '0');
  return res;
}

int get_bulls(vector<int> guess, vector<int> answer)
{
  int len = answer.size();
  int bulls = 0;

  if (guess.size() != len)
    error("guess and answer doesn't have same length!\n");

  for (int i = 0; i < len; ++i)
    if (guess[i] == answer[i])
      ++bulls;

  return bulls;
}

int get_cows(vector<int> guess, vector<int> answer)
{
  int len = answer.size();
  int cows = 0;

  if (guess.size() != len)
    error("guess and answer doesn't have same length!\n");

  for (int i = 0; i < len; ++i)
    for (int j = 0; j < len; ++j)
      if (i != j && guess[i] == answer[j])
        ++cows;

  return cows;
}
