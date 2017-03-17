CC=g++

CFLAGS= -c -Wall -std=c++11

all: MainSearch

MainSearch: MainSearch.o wordSearch.o QTWordSearch.o 
	$(CC) MainSearch.o wordSearch.o QTWordSearch.o -o MainSearch.out

MainSearch.o: QTWordSearch.cpp
	$(CC) $(CFLAGS) MainSearch.cpp
	
QTWordSearch.o:QTWordSearch.cpp 
	$(CC) $(CFLAGS) QTWordSearch.cpp
	
wordSearch.o: wordSearch.cpp
	$(CC) $(CFLAGS) wordSearch.cpp
	
clean:
	rm -rf *.o core.* MainSearch.out

