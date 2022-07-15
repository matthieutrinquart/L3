tp1: definitions.o TP1.o
	g++ -o TP1 definitions.o TP1.o

definitions.o: definitions.cpp
	g++ -o definitions.o -c definitions.cpp -W -Wall -ansi -pedantic -std=c++11

TP1.o: TP1.cpp definitions.h
	g++ -o TP1.o -c TP1.cpp -W -Wall -ansi -pedantic -std=c++11
