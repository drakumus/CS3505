/*
* Rohan Cheeniyil
* u0914584
* TrieTestWild.cpp
* for testing of wildcard
*/

#include "Trie.h"
#include <iostream>
#include <fstream>

using namespace std;

Trie test;

bool findChar(string s, char c)
{
	for(unsigned int i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
			return true;
	}
	return false;
}

void findWord(vector<string> words)
{
	vector<string> suggestions;
	const string TAB = "   ";
	int size;

	for(unsigned int i = 0; i < words.size(); i++)
	{
		if(findChar(words[i],'?')) //calls wild prefix when '?' is present and has special behavior when this happens
		{
			cout << "The query " << words[i] << " has the following results:" << endl;
			vector<string> queryOut = test.wordsWithWildcardPrefix(words[i]);
			for(unsigned int index = 0; index < queryOut.size(); index++)
			{
				cout << TAB << queryOut[index] << endl;
			}
		}
		else if(test.isWord(words[i]))
		{
			cout << words[i]<< " is found" << endl;
		} else
		{
			cout << words[i]<< " is not found, did you mean:" << endl;
			suggestions = test.allWordsStartingWithPrefix(words[i]);
			size = suggestions.size();
			if(size == 0)
			{
				cout << TAB << "no alternatives found" << endl;
			} else 
			{ 
				for(int x = 0; x < size; x++)
				{
					cout << TAB << suggestions[x] << endl;
				}
			}
			
		}
	}
}

int main(int argc, char * argv[])
{
	if(argc == 3) //same implementation as TrieTest.cpp
	{
		ifstream f_words;
		ifstream f_queries;
		f_words.open(argv[1]);
		f_queries.open(argv[2]);

		vector<string> v_queries;

		string output;
		while (std::getline(f_words, output))
		{
			test.addWord(output);
		}

		while (std::getline(f_queries, output))
		{
			v_queries.push_back(output);
		}

		findWord(v_queries);
	}
	else
	{
		cout << "invalid num arguments." << endl;
	}

	return 0;
}