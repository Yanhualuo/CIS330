#ifndef REVERSI_H_
#define REVERSI_H_


typedef enum {
	Empty,
	MarkBlack,
	MarkWhite
} Action;

typedef enum { 
	black =1, 
	white = 2,
	blank = 0,
} playerColor;


void printOthello(const int height, int **othello);

void allocateOthello(const int height, int ***othello);

void intializeOthello(const int height, int **othello);

void deallocateOthello(const int height, int ***othello);

#endif 