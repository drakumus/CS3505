/*
* Rohan Cheeniyil
* u0914584
* TrieTest.cpp
*/

#include "Trie.h"
#include <iostream>
#include <fstream>

using namespace std;

Trie test;

void findWord(vector<string> words)
{
	vector<string> suggestions;
	const string TAB = "   ";
	int size;

	//loop through each dictionary value and apply appropriate method to them.
	for(unsigned int i = 0; i < words.size(); i++)
	{
		if(test.isWord(words[i]))
		{
			cout << words[i]<< " is found" << endl;
		} else
		{
			cout << words[i]<< " is not found, did you mean:" << endl;
			//suggestions = test.allWordsStartingWithPrefix(words[i]);
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
	if(argc == 3) //avoid seg fault and make sure num args is accurate
	{
		ifstream f_words; //make filestreams for each file
		ifstream f_queries;
		f_words.open(argv[1]); //open files for each arg
		f_queries.open(argv[2]);

		vector<string> v_queries; //store queries

		string output; //adds each line to the trie
		while (std::getline(f_words, output))
		{
			test.addWord(output);
		}

		//adds each line to vector
		while (std::getline(f_queries, output))
		{
			v_queries.push_back(output);
		}
		//uses helper method to implement required assignment behavior.
		findWord(v_queries);
	}
	else
	{
		cout << "invalid num arguments." << endl;
	}

	return 0;
}