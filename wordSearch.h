#ifndef __WORDSEARCH__
#define __WORDSEARCH__
#include <string>
#include <vector>
using namespace std;

class WordSearch
{
public:
	WordSearch(const int inSizeY,const int inSizeX);
	~WordSearch();
	bool addWord(const string& inWord);
	void complete();
	void print()const;
	
private:
	struct Loc
	{
		int LocX;
		int LocY;
		int LocO;
	};
	vector<string*> unFoundWords;
	vector<string*> foundWords;
	int sizeX;
	int sizeY;
	char** charArray;
	
	int canWordGoHere(const string& inWord,const int inOrientation,const int inLocY,const int inLocX)const;
	void putWordHere(const string& inWord,const int inOrientation,const int inLocY,const int inLocX);
};

#endif
