#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

string scramble(const string word)
{
	string new_word = "";
	int num;

	// Start with random time seed
	srand(time(0));

	for(int i=0; i<word.length(); i++)
	{
		num = rand() % 2;

		if (num)
			new_word = new_word + word[i];
		else
			new_word = new_word + '-';
	}

	return new_word;
}

bool complete(const string word)
{
	for (int i=0; i<word.length(); i++)
	{
		if (word[i] == '-')
			return false;
	}
	return true;
}

int main()
{
	string data[] = {
		"hello",
		"world"
	};
	const int n = 2;

	for (int k=0; k < n; k++)
	{
		const string org_word = data[k];
		string word = scramble(org_word);
		cout<<"\nHere's next word: "<<word<<endl;

		int chances = 5;
		char user;

		bool done = false;

		cout<<"\nChances left: "<<chances<<endl;
		while(chances > 0)
		{
			cout<<"\nWord is "<<word<<endl;
			cout<<"Enter next guess: ";
			cin>>user;

			bool changed = false;

			for (int i=0; i<word.length(); i++)
			{
				if (user == org_word[i] && word[i] == '-')
				{
					changed = true;
					word[i] = user;
				}
			}
			if (!changed)
			{
				cout<<"Incorrect Guess!"<<endl;
				chances--;
				cout<<"Chances left: "<<chances<<endl;
			}
			else
			{
				cout<<"Correct Guess."<<endl;
			}

			if (complete(word))
			{
				cout<<"\nHurray! You have completed this word!"<<endl;
				done = true;
				break;
			}
		}
		if (!done)
		{
			cout<<"\nAlas! The correct word was "<<org_word<<endl;
		}

		char ch;
		cout<<"\nWould you like to continue to next word (y/n) ? ";
		cin>>ch;
		if (ch == 'Y' || ch == 'y')
		{
			continue;
		}
		else
		{
			break;
		}
	}
	cout<<"\nThank you for playing this game."<<endl;
	return 0;
}
