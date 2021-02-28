DEBUG = -g
OPTS = -Wall -ansi -pedantic
CC = g++ $(DEBUG) $(OPTS) -c
LN = g++

OBJS = main.o BookNode.o BookTree.o Book.o

runMe: $(OBJS)
	$(LN) -o runMe $(OBJS)

main.o: Book.h BookTree.h BookNode.h main.cpp
	g++ -g -c main.cpp

Book.o: Book.h Book.cpp
	$(CC) Book.cpp

BookNode.o: BookNode.h BookNode.cpp Book.h
	$(CC) BookNode.cpp


BookTree.o: BookNode.h BookTree.h BookTree.cpp 
	$(CC) BookTree.cpp



