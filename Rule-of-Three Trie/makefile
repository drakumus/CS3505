compileFlags = -std=c++11 -Wall -g

program: TrieTest.o Trie.o
	g++ $(compileFlags) -o trie TrieTest.o Trie.o

programWild: TrieTestWild.o Trie.o
	g++ $(compileFlags) -g -o trie TrieTestWild.o Trie.o

MainWild.o: TrieTestWild.cpp
	g++ $(compileFlags) -g -c TrieTestWild.cpp

Main.o: TrieTest.cpp
	g++ $(compileFlags) -g -c TrieTest.cpp

Trie.o: Trie.cpp Trie.h
	g++ $(compileFlags) -g -c Trie.cpp

clean:
	rm *.o trie

test: program
	./trie dictionary queries

testWild: programWild
	./trie dictionary queriesWild
	