DBG = -g
OPTS = $(DBG) -Wall -ansi -pedantic
CC = g++ -c $(OPTS)
LN = g++ -Wall
OBJS = DLNode.o  StringSet.o main.o

runMe: $(OBJS)
	$(LN) -o runMe $(OBJS)

DLNode.o: DLNode.cpp DLNode.h
	$(CC) DLNode.cpp

DList.o: StringSet.cpp DLNode.h StringSet.h
	$(CC) StringSet.cpp

main.o: main.cpp DLNode.h
	$(CC) main.cpp

clean:
	/bin/rm ./runMe $(OBJS)

