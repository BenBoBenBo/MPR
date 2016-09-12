//main.cpp

#include <iostream>
#include <string>
#include "hangman.h"

using namespace std;

string initMagicWord();
void display(int count, bool win, string guesses);

int main(int argc, const char * argv[])
{
	string magicWord = initMagicWord(); //Need to clear the console in order to hide the magicWord.
	int wordLength = magicWord.length();     //I'd like to initialize the hiddenWord by magicWord's length. need const or workaround though...
	string hiddenWord[30];
	
	//initial display 
	for (int i = 0; i < wordLength; i++)
	{
		hiddenWord[i] = '?';
		cout << hiddenWord[i];
	}
	cout << endl;
	
	int count = 0; //test
	int a = 0; //test
	bool b = true; //test
	char c[26] = "ninjaChicken2000"; //test
	
	while (count < 8)
	{
		display(count, b, c);
		count++;
	}
	cin.ignore();
	return 0;
}


string initMagicWord()
{
	string userInput; // I'd like to figure this out with a character array... 
	cout << "Enter the secret word: ";
	getline(cin, userInput); //scanf_s and scanf was casuing many errors... I probably was misussing. could not troubleshoot well.
	cout << userInput << endl;                // test line
	return userInput;
}

void display(int count, bool win, string guesses)
{
		cout << "    ____" << endl;
		cout << "   |    \\" << endl;

	if (count == 0) //beginning of game.
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   | " << endl;
	}
	else if (count == 1)
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   |    ()" << endl;
		cout << "   | " << endl;
		cout << "   | " << endl;
	}
	else if (count == 2)
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   |    ()" << endl;
		cout << "   |    ||" << endl;
		cout << "   | " << endl;
	}
	else if (count == 3)
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   |    ()" << endl;
		cout << "   |   /||" << endl;
		cout << "   | " << endl;
	}
	else if (count == 4)
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   |    ()" << endl;
		cout << "   |   /||\\" << endl;
		cout << "   | " << endl;
	}
	else if (count == 5)
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   |    ()" << endl;
		cout << "   |   /||\\" << endl;
		cout << "   |    /" << endl;
	}
	else if (count == 6)
	{
		cout << "   | " << endl;
		cout << "   | " << endl;
		cout << "   |    ()" << endl;
		cout << "   |   /||\\" << endl;
		cout << "   |    /\\" << endl;
	}
	else if (count == 7)
	{
		cout << "   |    |" << endl; 
		cout << "   |    ()" << endl;
		cout << "   |   /||\\" << endl;
		cout << "   |    /\\" << endl;
		cout << "   |" << endl;
	}
		cout << "[][][][][][][][]" << endl;
}

	//cout << "-----------------------------------" << endl;
	//cout << "GUESSES: ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
	//cout << "-----------------------------------" << endl;

//adding new line below...

