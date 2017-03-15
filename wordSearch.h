#ifndef __WORDSEARCH__
#define __WORDSEARCH__
#include <string>
using namespace std;

class WordSearch
{
public:
	WordSearch(const int inSizeX,const int inSizeY);
	~WordSearch();
	bool addWord(const string& inWord);
	void print()const;
	
private:
	struct Loc
	{
		int LocX;
		int LocY;
		int LocO;
	};
	int sizeX;
	int sizeY;
	char** charArray;
	
	int canWordGoHere(const string& inWord,const int inOrientation,const int inLocY,const int inLocX)const;
	void putWordHere(const string& inWord,const int inOrientation,const int inLocY,const int inLocX);
};

#endif
