main:word.o bag.o itemtype.o wordsearch.o
	g++ wordsearch.o word.o itemtype.o bag.o -o main
bag.o:bag.cpp,bag.h,itemtype.h
	g++ -c bag.cpp
itemtype.o:itemtype.cpp,itemtype.h
	g++ -c itemtype.cpp
word.o:word.cpp,word.h
	g++ -c word.cpp
wordsearch.o:wordsearch.cpp,wordsearch.h,word.h
	g++ -c wordsearch.cpp
clean:
	rm main bag.o itemtype.o word.o wordsearch.o
	
