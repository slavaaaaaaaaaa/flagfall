OBJS=board.o pieces.o entry.o
SRCS=entry.cpp board.cpp board.h pieces.cpp pieces.h
CC=g++
DEBUG=-g
CFLAGS_FUNCTIONAL=-Wall $(DEBUG)
CFLAGS=-Wall -c $(DEBUG)
LFLAGS=-Wall $(DEBUG)

test: $(SRCS)
	$(CC) $(CFLAGS_FUNCTIONAL) entry.cpp -o flagfall.out
	./flagfall.out

test_o: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o flagfall.out
	./flagfall.out

entry.o: entry.cpp
	$(CC) $(CFLAGS) entry.cpp

board.o: board.cpp board.h pieces.h
	$(CC) $(CFLAGS) board.cpp

pieces.o: pieces.cpp pieces.h board.h
	$(CC) $(CFLAGS) pieces.cpp

tar:
	tar cfz flagfall.tar.gz *.cpp *.h README LICENSE Makefile

clean:
	rm *.o a.out flagfall
	echo done
