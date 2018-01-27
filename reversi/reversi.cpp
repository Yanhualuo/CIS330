//============================================================================
// Name        : reversi.cpp
// Author      : YanhuaLuo
// Version     :
// Copyright   : Your copyright notice
// Description : Reversi in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include "reversi.hpp"

using namespace std;

void Board::initialBoard(struct board *chessboard, int size){
	(*chessboard).chess_board = new int*[size];
	for (int i = 0; i < size; i++){
		(*chessboard).chess_board[i] = new int [size];
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			(*chessboard).chess_board[i][j] = blank;
		}
	}

	int middle = size/ 2 -1;
	(*chessboard).chess_board[middle][middle] = white;
	(*chessboard).chess_board[middle+1][middle+1] = white;
	(*chessboard).chess_board[middle][middle+1] = black;
	(*chessboard).chess_board[middle+1][middle] = black;
	(*chessboard).white = 2;
	(*chessboard).black = 2;
}

void Board::freeBoard(struct board *chessboard, int size){
	for (int i = 0; i < size; i++){
		delete (*chessboard).chess_board[i];
	}
	delete (*chessboard).chess_board;
}

void Board::printBoard(struct board *chessboard, int size){
	cout << "  ";
	for (int i = 0; i < size; i++){
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++){
		cout << i << " ";
		for (int j = 0; j < size; j++){
			if ((*chessboard).chess_board[i][j] == blank){
				cout << "." << " ";
			}else if ((*chessboard).chess_board[i][j] == white){
				cout << "o" << " ";
			}else if ((*chessboard).chess_board[i][j] == black){
				cout << "x" << " ";
			}
		}
		cout << endl;
	}
	cout << "Number of white chess: " << (*chessboard).white << endl;
	cout << "Number of black chess: " << (*chessboard).black << endl;
}


void Board::move(struct board *chessboard, int size, int row, int col, chessColor color){
	(*chessboard).chess_board[row][col] = color;
	if (color == black){
		(*chessboard).black++;
	}else{
		(*chessboard).white++;
	}
	chessColor current = color;
	int oppsiteColor;
	if (current == black){
		oppsiteColor = white;
	}else{
		oppsiteColor = black;
	}
	//Check North
	bool exist = false;
	int r = row;
	int c = col;
	while ((r-1) >= 0 && (*chessboard).chess_board[r-1][c] == oppsiteColor){
		r--;
		exist = true;
	}
	if (exist && (r-1) >= 0 && (*chessboard).chess_board[r-1][c] == current){
		while ((*chessboard).chess_board[r][c] != current){
			(*chessboard).chess_board[r][c] = current;
			r++;
			if (color == black){
				(*chessboard).black++;
				(*chessboard).white--;
			}else{
				(*chessboard).black--;
				(*chessboard).white++;
			}
		}
	}
	//Check East
	exist = false;
	r = row;
	c = col;
	while ((c-1) >= 0 && (*chessboard).chess_board[r][c-1] == oppsiteColor){
		c--;
		exist = true;
	}
	if (exist && (c-1) >= 0 && (*chessboard).chess_board[r][c-1] == current){
		while ((*chessboard).chess_board[r][c] != current){
			(*chessboard).chess_board[r][c] = current;
			c++;
			if (color == black){
				(*chessboard).black++;
				(*chessboard).white--;
			}else{
				(*chessboard).black--;
				(*chessboard).white++;
			}
		}
	}
	//Check West
	r = row;
	c = col;
	exist = false;
	while ((c+1) < size && (*chessboard).chess_board[r][c+1] == oppsiteColor){ // west
		c++;
		exist = true;
	}
	if (exist && (c+1) < size && (*chessboard).chess_board[r][c+1] == current){
		while ((*chessboard).chess_board[r][c] != current){
			(*chessboard).chess_board[r][c] = current;
			c--;
			if (color == black){
				(*chessboard).black++;
				(*chessboard).white--;
			}else {
				(*chessboard).white++;
				(*chessboard).black--;
			}
		}
	}
	//Check South
	r = row;
	c = col;
	exist = false ;
	while ((r+1) < size && (*chessboard).chess_board[r+1][c] == oppsiteColor){ // south
		r++;
		exist = true;
	}
	if (exist && (r+1) < size && (*chessboard).chess_board[r+1][c] == current){
		while((*chessboard).chess_board[r][c] != current){
			(*chessboard).chess_board[r][c] = current;
			r--;
			if (color == black){
				(*chessboard).black++;
				(*chessboard).white--;
			}else {
				(*chessboard).white++;
				(*chessboard).black--;
			}
		}
	}
	// EastNorth
	r = row;
	c = col;
	exist = false ;
	while ((r-1) >= 0 && (c-1) >= 0 && (*chessboard).chess_board[r-1][c-1] == oppsiteColor){ // eastnorth
		r--;
		c--;
		exist = true;
	}
	if (exist && (r-1) >= 0 && (c-1) >= 0 && (*chessboard).chess_board[r-1][c-1] == current){
		while((*chessboard).chess_board[r][c] != current){
			(*chessboard).chess_board[r][c] = current;
			r++;
			c++;
			if (color == black){
				(*chessboard).black++;
				(*chessboard).white--;
			}else {
				(*chessboard).white++;
				(*chessboard).black--;
			}
		}
	}
	//Check EastSouth
	r = row;
	c = col;
	exist = false ;
	while ((r+1) < size && (c-1) >= 0 && (*chessboard).chess_board[r+1][c-1] == oppsiteColor){ // eastsouth
		r++;
		c--;
		exist = true;
	}
	if (exist && (r+1) < size && (c-1) >= 0 && (*chessboard).chess_board[r+1][c-1] == current){
		while((*chessboard).chess_board[r][c] != current){
			(*chessboard).chess_board[r][c] = current;
			r--;
			c++;
			if (color == black){
				(*chessboard).black++;
				(*chessboard).white--;
			}else {
				(*chessboard).white++;
				(*chessboard).black--;
			}
		}
	}
	//Check WestSouth
	r = row;
	c = col;
	exist = false ;
	while ((r+1) < size && (c+1) < size && (*chessboard).chess_board[r+1][c+1] == oppsiteColor){ // westsouth
		r++;
		c++;
		exist = true;
	}
	if (exist && (r+1) < size && (c+1) < size && (*chessboard).chess_board[r+1][c+1] == current){
		while((*chessboard).chess_board[r][c] != current){
			(*chessboard).chess_board[r][c] = current;
			r--;
			c--;
			if (color == black){
				(*chessboard).black++;
				(*chessboard).white--;
			}else {
				(*chessboard).white++;
				(*chessboard).black--;
			}
		}
	}
	//WestNorth
	r = row;
	c = col;
	exist = false ;
	while ((r-1) >= 0 && (c+1) < size && (*chessboard).chess_board[r-1][c+1] == oppsiteColor){ // westnorth
		r--;
		c++;
		exist = true;
	}
	if (exist && (r-1) >= 0 && (c+1) < size && (*chessboard).chess_board[r-1][c+1] == current){
		while((*chessboard).chess_board[r][c] != current){
			(*chessboard).chess_board[r][c] = current;
			r++;
			c--;
			if (color == black){
				(*chessboard).black++;
				(*chessboard).white--;
			}else {
				(*chessboard).white++;
				(*chessboard).black--;
			}
		}
	}
}

bool Board::checkMoveValid(struct board *chessboard, int size, int row, int col, chessColor color){
	if ((*chessboard).chess_board[row][col] != blank){
			return false;
		}

	chessColor current = color;
	int oppsiteColor;
	if (current == black){
		oppsiteColor = white;
	}else {
		oppsiteColor = black;
	}
	//Check North
	bool exist = false ;
	int r = row;
	int c = col;
	while ((r-1)>=0 && (*chessboard).chess_board[r-1][c] == oppsiteColor){
		r--;
		exist = true;
	}
	if (exist && (r-1) >=0 && (*chessboard).chess_board[r-1][c] == current){
		return true;
	}
	//Check East
	r = row;
	c = col;
	exist = false ;
	while ((c-1)>=0 && (*chessboard).chess_board[r][c-1] == oppsiteColor){
		c--;
		exist = true;
	}
	if (exist && (c-1) >=0 && (*chessboard).chess_board[r][c-1] == current){
		return true;
	}
	//Check West
	r = row;
	c = col;
	exist = false ;
	while ((c+1) < size && (*chessboard).chess_board[r][c+1] == oppsiteColor){
		c++;
		exist = true;
	}
	if (exist && (c+1) < size && (*chessboard).chess_board[r][c+1] == current){
		return true;
	}
	//Check South
	r = row;
	c = col;
	exist = false;
	while ((r+1) < size && (*chessboard).chess_board[r+1][c] == oppsiteColor){
		r++;
		exist = true;
	}
	if (exist && (r+1) < size && (*chessboard).chess_board[r+1][c] == current){
		return true;
	}
	//Check EastNorth
	r = row;
	c = col;
	exist = false ;
	while ((r-1) >= 0 && (c-1) >= 0 && (*chessboard).chess_board[r-1][c-1] == oppsiteColor){
		r--;
		c--;
		exist = true;
	}
	if (exist && (r-1) >= 0 && (c-1) >= 0 && (*chessboard).chess_board[r-1][c-1] == current){
		return true;
	}
	//Check EastSouth
	r = row;
	c = col;
	exist = false ;
	while ((r+1) < size && (c-1) >= 0 && (*chessboard).chess_board[r+1][c-1] == oppsiteColor){
		r++;
		c--;
		exist = true;
	}
	if (exist && (r+1) < size && (c-1) >= 0 && (*chessboard).chess_board[r+1][c-1] == current){
		return true;
	}
	//Check WestSouth
	r = row;
	c = col;
	exist = false ;
	while ((r+1) < size && (c+1) < size && (*chessboard).chess_board[r+1][c+1] == oppsiteColor){
		r++;
		c++;
		exist = true;
	}
	if (exist && (r+1) < size && (c+1) < size && (*chessboard).chess_board[r+1][c+1] == current){
		return true;
	}
	//Check WestNorth
	r = row;
	c = col;
	exist = false ;
	while ((r-1) >= 0 && (c+1) < size && (*chessboard).chess_board[r-1][c+1] == oppsiteColor){
		r--;
		c++;
		exist = true;
	}
	if (exist && (r-1) >= 0 && (c+1) < size && (*chessboard).chess_board[r-1][c+1] == current){
		return true;
	}

	return false;
}



bool Board::checkBoardDone(struct board *chessboard, int size){
	if ((*chessboard).black == 0 || (*chessboard).white == 0){
		return true;
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if ((*chessboard).chess_board[i][j] == blank){
				return false;
			}
		}
	}
	return true;
}

void Runable::run(struct board *chessboard, int size, int row, int col, chessColor color)
{
	Board bd;

	bool avi = bd.checkMoveValid(chessboard, size, row, col, color);

	while (!avi){
		cout << "Wrong input, try it again: ";
		cin >> row >> col;
		avi = bd.checkMoveValid(chessboard, size, row, col, color);
	}

	bd.move(chessboard, size, row, col, color);
	bd.printBoard(chessboard, size);
	bd.checkBoardDone(chessboard, size);

}

