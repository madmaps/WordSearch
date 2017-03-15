#include <iostream>
#include "wordSearch.h"
#include <math.h>
#include <vector>
#include <random>
using namespace std;

WordSearch::WordSearch(const int inSizeY,const int inSizeX)
{
	sizeX=inSizeX;
	sizeY=inSizeY;
	charArray = new char*[inSizeY];
	for(int i = 0;i < sizeY-1;i++)
	{
		charArray[i]=new char[sizeX];
		for(int j = 0;j < sizeX-1;j++)
		{
			charArray[i][j] = ' ';
		}
	}
	
}

WordSearch::~WordSearch()
{
	for(int i=0;i < sizeX-1;i++)
	{
		delete[] charArray[i];
	}
	for(unsigned int i = 0;i < unFoundWords.size() - 1;i++)
	{
		delete unFoundWords[i];
	}
}

bool WordSearch::addWord(const string& inWord)
{
	int tempScore = 0;
	int returnScore = -1;
	Loc values;
	vector<Loc>* bestResults = new vector<Loc>;
	for(int y = 0;y < sizeY;y++)
	{
		for(int x = 0;x < sizeX;x++)
		{
			for(int orientation = 0;orientation < 8;orientation++)
			{
				tempScore = canWordGoHere(inWord,orientation,y,x);
				if(tempScore >= returnScore)
				{
					if(tempScore > returnScore)
					{
						bestResults->clear();
						returnScore = tempScore;
					}
					values.LocX = x;
					values.LocY = y;
					values.LocO = orientation;
					bestResults->push_back(values);
				}
			}
		}
	}
	if(returnScore >= 0)
	{
		random_device rd;
		default_random_engine generator(rd());
		uniform_int_distribution<int> distribution(0,bestResults->size()-1);
		int randomValue = distribution(generator);
		putWordHere(inWord,bestResults->at(randomValue).LocO,bestResults->at(randomValue).LocY,bestResults->at(randomValue).LocX);
		string* temp = new string();
		temp->assign(inWord);
		unFoundWords.push_back(temp);
		delete bestResults;
		return true;
	}
	cout << inWord << " didn't make it" << endl;
	return false;
}

int WordSearch::canWordGoHere(const string& inWord,const int inOrientation,const int inLocY,const int inLocX)const
{
	int xCounter = 0, yCounter = 0;

	xCounter = (inOrientation + 6) % 8;
	yCounter = (inOrientation + 4) % 8;
	xCounter = !!(xCounter%4)*(floor(xCounter/4)*2-1);
	yCounter = !!(yCounter%4)*(floor(yCounter/4)*2-1);
	
	int xCurrent = inLocX;
	int yCurrent = inLocY;
	int score = 0;
	for(unsigned int i = 0;i < inWord.length();i++)
	{
		if(xCurrent >= 0 && xCurrent < sizeX-1 && yCurrent >=0 && yCurrent < sizeY-1 && score !=-1)
		{
			if(inWord[i] == charArray[yCurrent][xCurrent] && score !=-1)
			{
				score++;
			}
			else
			{
				if(charArray[yCurrent][xCurrent] != ' ')
				{
					score = -1;
				}
			}
		}
		else
		{
			score = -1;
		}
		xCurrent += xCounter;
		yCurrent += yCounter;
	}

	
	return score;
}

void WordSearch::putWordHere(const string& inWord,const int inOrientation,const int inLocY,const int inLocX)
{
	int xCounter = 0, yCounter = 0;

	xCounter = (inOrientation + 6) % 8;
	yCounter = (inOrientation + 4) % 8;
	xCounter = !!(xCounter%4)*(floor(xCounter/4)*2-1);
	yCounter = !!(yCounter%4)*(floor(yCounter/4)*2-1);
	
	int xCurrent = inLocX;
	int yCurrent = inLocY;
	for(unsigned int i = 0;i < inWord.length();i++)
	{
		charArray[yCurrent][xCurrent] = inWord[i];
		xCurrent += xCounter;
		yCurrent += yCounter;
	}
}

void WordSearch::print()const
{
	for(int y = 0;y < sizeY-1;y++)
	{
		for(int x = 0;x < sizeX-1;x++)
		{
			cout << charArray[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	
	for(string* words : unFoundWords)
	{
		cout << *words << endl;
	}
	
}

void WordSearch::complete()
{
	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> distribution(0,25);
	
	for(int y = 0;y < sizeY-1;y++)
	{
		for(int x = 0;x < sizeX-1;x++)
		{
			
			if(charArray[y][x] == ' ')
			{
				charArray[y][x] = distribution(generator)+65;
			}
		}
	}
}
