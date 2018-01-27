/*
 * reversi.hpp
 *
 *  Created on: Feb 7, 2017
 *      Author: yanhualuo
 */

#ifndef REVERSI_HPP_
#define REVERSI_HPP_


typedef int boolean;
//#define true 1;
//#define false 0;

struct board{
	int size;
	int grid;
	int **chess_board;
	int white, black;
};

typedef enum{
	white  =1,
	black  = 2,
	blank = 0,
}chessColor;

class Board{
public:
	void initialBoard(struct board *chessboard,int size);
	void freeBoard(struct board *chessboard, int size);
	void printBoard(struct board *chessboard, int size);
	bool checkBoardDone(struct board *chessboard, int size);
	bool checkMoveValid(struct board *chessboard, int size, int row, int col, chessColor cl);
	void move(struct board *chessboard, int size, int row, int col, chessColor cl);
};

class Runable{
public:
	void run(struct board *chessboard, int size, int row, int col, chessColor cl);
};


#endif /* REVERSI_HPP_ */
