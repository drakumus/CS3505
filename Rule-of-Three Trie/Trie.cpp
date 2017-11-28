/*
* Rohan Cheeniyil
* u0914584
* Trie.cpp
*/

#include "Trie.h"
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
//#include <stdio.h>

using namespace std;

Trie::Trie() : isLast(false)
{
	for (int i = 0; i < 26; i++)
	{
		children[i] = NULL; //initialize with null
	}
}

Trie::Trie(const Trie& other) : isLast(false)
{
	isLast = other.isLast; //initialize with other trie's isLast
	for (int i = 0; i < 26; i++)
	{
		if(other.children[i])
			children[i] = new Trie(*(other.children[i])); //initialize with provided children of other Trie
		else
			children[i] = NULL; //initialize with null
	}
}

//follows each child and deconstructs them.
//the deconstructor will be called on each node hence the ability to avoid 
//nested looping.
Trie::~Trie()
{
	for (int i = 0; i < 26; i++)
	{
		if(children[i] != NULL)
			delete children[i]; //initialize with null
	}
}

//uses std::swap to exchange internal variables
void Trie::swap(Trie& trie1, Trie& trie2)
{
	using std::swap;
	swap(trie1.isLast, trie2.isLast);
	swap(trie1.children, trie2.children);
}

//uses swap to provide the = operator all valid values
Trie& Trie::operator=(Trie trie)
{
	swap(*this, trie);
	return *this;
}

bool Trie::contains(char c)
{
	 //exploits underlying integer for every char to generate an index between 0-26
	return children[c - 'a'] != NULL;
}

//Helper method to get a child
Trie* Trie::getChild(char c)
{
	return children[c - 'a'];
}

//Helper method to add a child
Trie* Trie::addChild(char c)
{
	children[c - 'a'] = new Trie();
	return children[c - 'a'];
}

bool Trie::isWord(string word)
{	
	//try to catch empty param. When reading lines "" is never passed to the vector but is instead skipped over
	if(word == "") 
	{
		return false;
	}

	Trie *currentNode = this;
	int len = word.size();

	for (int i = 0; i < len; i++)
	{
		if (currentNode->contains(word[i])) //checks if i matches
		{
			currentNode = currentNode->getChild(word[i]);
			if (currentNode->isLast == true && i == len-1)
				return true; //last letter matches and can exit
		}
		else
		{
			return false; //could not find next letter as child
		}
			
	}
	return false; //out of letters to find but all previous matched
}

void Trie::addWord(string word)
{
	Trie *currentNode = this;
	int len = word.size();
	for (int i = 0; i < len; i++)
	{
		if (currentNode->contains(word[i]) == false) //if the letter is not already contained add it as a child and move to child node.
		{
			currentNode = currentNode->addChild(word[i]);
		}
		else // if it already has that child then move to that child and continue
		{
			currentNode = currentNode->getChild(word[i]);
		}
	}
	currentNode->isLast = true; //sets islast flag for last letter since current node must be last when this function reaches the end
}

vector<string> Trie::allWordsStartingWithPrefix(string pre)
{
	vector<string> list;
	Trie *currentNode = this;
	int len = pre.size();
	//moves current node to the end of pre
	for (int i = 0; i < len; i++)
	{
		if (currentNode->contains(pre[i]))
		{
			currentNode = currentNode->getChild(pre[i]);
		} else
		{
			return list;
		}
	}

	
	getWords(currentNode, list, pre); //uses getWords to make a vecotr
	sort(list.begin(), list.end()); //sorts the vector
	list.erase(unique(list.begin(), list.end()), list.end()); //deletes redundancies next to eachother (hence the sort)
	return list;
}

void Trie::getWords(Trie* currentNode, vector<string> &words, string s)
{
	if (currentNode->isLast) //"exit condition" of sorts that will push a string to the vector if a isLast flag is reached
	{
		words.push_back(s);
	}
	for(int i = 0; i < 26; i++)
	{
		if(currentNode->children[i] != NULL) //goes down the path of valid children
		{
			char c = i+'a';
			getWords(currentNode->children[i], words, s+c); //adds child index+'a' for valid character to string and continues recursive calling.
		}
	}
}

vector<string> Trie::wordsWithWildcardPrefix(string pre)
{
	//sets up for recursive getWildWords
	Trie* currentNode = this;
	vector<string> list;
	string s = "";

	getWildWords(currentNode, list, s, pre); //calls recursive method to construct vector
	std::sort(list.begin(), list.end()); //same code as before to remove redundancies.
	list.erase(std::unique(list.begin(), list.end()), list.end());
	return list;
}

void Trie::getWildWords(Trie* currentNode, vector<string> &words, string s, string pre)
{
	string nextPre;
	if(pre.size() != 0) //avoid segmentation fault and check 
		nextPre = pre.substr(1,pre.size()-1); //this pops the first character of pre.
											  //avoids keeping track of size.

	if(pre.size() == 0) // yes this is the opposite of the above statement but I couldn't have it as an else
	{					// because I didn't want the other conditionals to execute.
		getWords(currentNode, words, s); //calls getWords on the remaining letters once the pre has been navigated
	}
	else if(pre[0] >= 'a' && pre[0] <= 'z') //checks if in range of valid characters
	{
		if(currentNode->children[pre[0]-'a'] != NULL) //go to the known path dictated by the prefix
			getWildWords(currentNode->children[pre[0]-'a'], words, s+pre[0],nextPre); //"pop" the first character from pre and keep building string
	}
	else if(pre[0] == '?')
	{
		for(int i = 0; i < 26; i++) //all children that are populated with nodes are a valid path. Act like this is getWords()
		{
			if(currentNode->children[i] != NULL)
			{
				char temp = i+'a';
				getWildWords(currentNode->children[i], words, s+temp, nextPre); //go to next child with popped pre.
			}
		} //important part on next line: due to the nature of '?' being able to be a valid char or a "no character" the current node must be revisited.
		getWildWords(currentNode, words, s, nextPre); //by popping the current '?' the children can be reevaluated and more paths can be found.
													  //unfortunately pursuing paths in this manner creates redundancies thus the code for deleting them.
	}
	else
	{
		cout<<"Invalid character detected." <<endl; //else statement to handle invalid characters passed.
	}
}