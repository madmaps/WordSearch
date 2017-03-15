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
	
private:
	int sizeX;
	int sizeY;
	char** charArray;
	
	int canWordGoHere(const string& inWord,const int inOrientation,const int inLocX,const int inLocY)const;
};

#endif
