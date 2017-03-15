#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <random>
#include "wordSearch.h"

using namespace std;

bool addWordFile(WordSearch& inWordSearch,const string inFile,const int maxWords = 50);

int main()
{
	WordSearch* myWordSearch = new WordSearch(30,40);
	addWordFile(*myWordSearch,"words.txt",200);
	myWordSearch->complete();
	myWordSearch->print();
	
	return 0;
}




bool addWordFile(WordSearch& inWordSearch,const string inFile,const int maxWords)
{
	list<string> wordList;
	list<string>::iterator iter;
	random_device rd;
	int randomValue = 0;
	default_random_engine generator(rd());
	
	string line;
	ifstream myFile(inFile);
	if(myFile.is_open())
	{
		while(getline(myFile,line))
		{
			transform(line.begin(), line.end(), line.begin(), ::toupper);
			wordList.push_back(line);
		}
		int wordListSize = wordList.size();
		for(int j = 0;j < maxWords && j < wordListSize;j++)
		{
			uniform_int_distribution<int> distribution(0,wordList.size()-1);
			randomValue = distribution(generator);
			iter = wordList.begin();
			for(int i = 0;i < randomValue;i++)
			{
				iter++;
			}
			inWordSearch.addWord(*iter);
			wordList.erase(iter);
		}
		
	}
	return true;
}
