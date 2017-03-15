#include <iostream>
#include "wordSearch.h"

using namespace std;

int main()
{
	WordSearch* myWordSearch = new WordSearch(20,20);
	string* test = new string("Hello");
	myWordSearch->addWord(*test);
	return 0;
}
