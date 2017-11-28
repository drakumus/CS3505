/*
* Rohan Cheeniyil
* u0914584
* TrieTest.h
*/

#include <string>
#include <vector>

using namespace std;

class Trie
{
public:
	
	Trie();
	Trie(const Trie& other);
	~Trie();

	void swap(Trie& trie1, Trie& trie2);

	Trie& operator=(Trie trie);

	bool isWord(string word);
	void addWord(string word);
	vector<string> allWordsStartingWithPrefix(string pre);
	vector<string> wordsWithWildcardPrefix(string pre);

private:
	
	bool contains(char c);
	Trie* getChild(char c);
	Trie* addChild(char c);
	
	bool isLast;

	Trie* children[26];

	void getWords(Trie* currentNode, vector<string> &words, string s);
	void getWildWords(Trie* currentNode, vector<string> &words, string s, string pre);
	
};