#include <iostream>
#include "wordSearch.h"
using namespace std;

WordSearch::WordSearch(const int inSizeX,const int inSizeY)
{
	sizeX=inSizeX;
	sizeY=inSizeY;
	charArray = new char*[inSizeX];
	for(int i = 0;i < sizeX-1;i++)
	{
		charArray[i]=new char[sizeY];
	}
}

WordSearch::~WordSearch()
{
	for(int i=0;i < sizeX;i++)
	{
		delete[] charArray[i];
	}
}

bool WordSearch::addWord(const string& inWord)
{
	cout << canWordGoHere(inWord,0,0,0);
	
	
	return true;
}

int WordSearch::canWordGoHere(const string& inWord,const int inOrientation,const int inLocX,const int inLocY)const
{
	int x1 = 0, x2 = 0;
	int y1 = 0, y2 = 0;
	x1 = (inOrientation + 2) % 8;
	x2 = (inOrientation + 6) % 8;
	y1 = (inOrientation + 0) % 8;
	y2 = (inOrientation + 4) % 8;
	x1 = !!(x1%4)*(x1/4);
	x2 = !!(x2%4)*(x2/4);
	y1 = !!(y1%4)*(y1/4);
	y2 = !!(y2%4)*(y2/4);
	
	int startX = inWord.length()*x1 + inLocX;
	int startY = inWord.length()*y1 + inLocY;
	int endX = inWord.length()*x2 + inLocX;
	int endY = inWord.length()*y2 + inLocY;
	cout << startX << "  " << startY << "  " << endX << "  " << endY << endl;
	//int xCounter = (startX-endX)/fabs(startX-endX);
	//int yCounter = (startY-endY)/abs(startY-endY);
	int score = 0;
	/*cout << "xCounter: " << xCounter << "  yCounter: " << yCounter << endl;
	for(unsigned int i = 0;i < inWord.length(); i++)
	{
		cout << "X: " << startX << "  Y: " << startY << endl;

		if(score !=-1 && charArray[startX][startY] == inWord[i])
		{
			score++;
		}
		else if(charArray[startX][startY] != inWord[i])
		{
			score = -1;
		}
		startX += xCounter;
		startY += yCounter;
	}
	
	return score;*/return 0;
}
