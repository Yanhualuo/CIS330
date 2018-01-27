#ifndef REVERSI_H_
#define REVERSI_H_


typedef enum {
	Empty,
	Black,
	White,
} Board;

typedef struct name
{ 
	Board turn;
	Board** Info;
} BoardInfo;


void printOthello(const int height, int **othello);

void allocateOthello(const int height, int ***othello);

void intializeOthello(const int height, int **othello);

void deallocateOthello(const int height, int ***othello);

//int ChecktheValidInput(BoardInfo b, int row, int col,int size,int reverse);

//void setTheStep(BoardInfo* b, int row, int col, int size);

//int CheckALL(BoardInfo* b, int size);

#endif 