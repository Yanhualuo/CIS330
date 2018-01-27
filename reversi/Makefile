SOURCES = reversi.cpp main.cpp
HEADERS = reversi.hpp 
OBJECTS = $(SOURCES:.cpp=.o)
LIBS = -lm
OUT = reversi

CC = g++
CFLAGS = -std=c++11 -g

%.o: %.c
	$(CC) -c $(CFLAGS) $<

main: $(OBJECTS)
	$(CC) -o $(OUT) $(OBJECTS)


reversi: reversi.o
	$(CC) -o $@ reversi.o $(LIBS)

main: main.o reversi.o
	$(CC) -o $@ main.o reversi.o $(LIBS)



clean: 
	$(RM) main $(OBJECTS) test-*