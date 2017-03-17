#ifndef __QTWORDSEARCH__
#define __QTWORDSEARCH__
#include "wordSearch.h"

class QTWordSearch : public WordSearch
{
	public:
	QTWordSearch(const int inSizeY,const int inSizeX,const int inSeed);
	virtual void draw();
	
};


#endif
