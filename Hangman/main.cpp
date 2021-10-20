#include <iostream>
#include <vector>
#include "hangman.h"
using namespace std;
int main()
{
  greet();

  string codeword = "codingcleverly";
  string answer = "______________";
  int misses = 0;
  vector<char> incorrect;
  bool guess = false;
  char letter;


  while(answer!=codeword && misses < 7)
  {
    display_misses(misses);
    display_status(incorrect, answer);

    cout<<"\n\nPlease enter your guess: ";
    cin>>letter;

    for(int i = 0; i<codeword.length(); i++)
    {
      if(letter==codeword[i])
      {
        answer[i] = letter;
        guess = true;
      }
    }
    if(guess)
    {
      cout<<"\nCorrect!\n";
    }
    else
    {
      cout<<"\nIncorrect! Another portion of the person has been drawn.\n";
      incorrect.push_back(letter);
      misses++;
    }
    guess = false;
  }

  end_game(answer, codeword);
  return 0;
}