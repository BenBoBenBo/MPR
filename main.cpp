//main.cpp

#include <iostream>
#include <string>
#include "hangman.h"

using namespace std;

string initMagicWord();
string initHiddenWord(string);
bool processGuess(int, string &, int &, string, string &);
void display(int, string, string);


int main(int argc, const char * argv[])
{
	string magicWord = initMagicWord();
	string hiddenWord = initHiddenWord(magicWord);
	
	int lives = 7;
	int guessCount = 0;
	string guessLetters = "                         ";
	char guess;

	
	while (lives > 0)
	{
		cout << "Enter a single letter guess: ";
		cin >> guess;
		
		if(processGuess(guess, guessLetters, guessCount, magicWord, hiddenWord) == false)
		{
			lives--;
		}
		display(lives, guessLetters, hiddenWord);
		if (lives == 0)
		{
			cout << "lose! :(" << endl;
			cin.ignore();
		}
		if (hiddenWord == magicWord)
		{
			cout << "win! :)" << endl;
			cin.ignore();
		}
	}
	//play again????????
	cin.ignore();
	return 0;
}

// Get and create magic word from user.
string initMagicWord()
{
	string userInput; // I'd like to figure this out with a character array... 
	cout << "Enter the secret word: ";
	getline(cin, userInput);
	return userInput;
}

// Create a displayable "hidden" word which will be used to show length of word and 
// positions/letters already guessed correctly.
string initHiddenWord(string word)
{
	int wordLength = word.length();
	for (int i = 0; i < wordLength; i++)
	{
		if (i < wordLength)
		{
			word[i] = '?';
		}
	}
	return word;
}

// Checks guess against each position of magicWord then changes the position of hiddenWord to
// display correct guesses. returns true if a good guess, returns false otherwise.
bool processGuess(int guess, string &guessLetters, int &guessCount, string magicWord, string &hiddenWord)
{
	guessLetters[guessCount] = guess;
	guessCount++;

	unsigned int pos = 0;
	int count = 0;
	while (pos < magicWord.length())
	{
		if (magicWord[pos] == guess)
		{
			hiddenWord[pos] = guess;
			count++;
		}
		pos++;
	}
	if (count > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Comment here... (description)
void display(int lives, string guesses, string hiddenWord)
{
	//refresh view
	system("cls");
	
	// ------- display visual below -------
		cout << "    ____" << endl;
		cout << "   |    \\" << endl;

	if (lives == 7)
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   | " << endl;
	}
	else if (lives == 6)
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   |    ()" << endl;
		cout << "   | " << endl;
		cout << "   | " << endl;
	}
	else if (lives == 5)
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   |    ()" << endl;
		cout << "   |    ||" << endl;
		cout << "   | " << endl;
	}
	else if (lives == 4)
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   |    ()" << endl;
		cout << "   |   /||" << endl;
		cout << "   | " << endl;
	}
	else if (lives == 3)
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   |    ()" << endl;
		cout << "   |   /||\\" << endl;
		cout << "   | " << endl;
	}
	else if (lives == 2)
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   |    ()" << endl;
		cout << "   |   /||\\" << endl;
		cout << "   |    /" << endl;
	}
	else if (lives == 1)
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   |    ()" << endl;
		cout << "   |   /||\\" << endl;
		cout << "   |    /\\" << endl;
	}
	else
	{
		cout << "   |    |" << endl; 
		cout << "   |    ()" << endl;
		cout << "   |   /||\\" << endl;
		cout << "   |    /\\" << endl;
		cout << "   |" << endl;
	}
		cout << "[][][][][][][][]" << endl;
		// ------- display visual above -------

		cout << "-----------------------------------" << endl;
		cout << "GUESSES: " << guesses << endl;
		cout << "HIDDEN WORD: " << hiddenWord << endl;
		cout << "-----------------------------------" << endl;
}



//adding new line below...

