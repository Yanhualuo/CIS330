/*
 * main.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: yanhualuo
 */

#include <iostream>

#include "reversi.hpp"

using namespace std;


int main(){

	int size;

	cout << "Welcome to the Othello Game." << endl;
	cout << "'o' -> color White and 'x' -> color Black" << endl;
	cout << "Please Enter the Size of Board." << endl;
	cin >> size;

	Board board;
	Runable run;
	struct board chessBoard;

	board.initialBoard(&chessBoard, size);
	board.printBoard(&chessBoard, size);

	int playerTurn = 0;

	int r,c;

	bool b,w; // Check whether black or white is avaiable to go

	bool avaiable = false; // Check whether the game can go on by one side or both sides

	while (!board.checkBoardDone(&chessBoard, size )){
		for (int i = 0 ; i < size; i++){
			for (int j = 0; j <size; j++){
				w = board.checkMoveValid(&chessBoard,size, i, j, white);
				b = board.checkMoveValid(&chessBoard,size, i, j, black);
				if (w || b){
					avaiable = true;
					break;
				}
				if (avaiable){
					break;
				}
			}
		}

		if (avaiable){
			if (playerTurn == 0){
				avaiable = false;
				for (int i = 0 ; i < size; i++){
					for (int j = 0; j <size; j++){
						w = board.checkMoveValid(&chessBoard,size, i, j, white);
						if (w){
							avaiable = true;
							break;
						}
					}
				}
				if (avaiable){
					cout <<"Player White turn, input 2 numbers for row and col: ";
					cin >> r >> c;
					while (r >= size || c >= size){
						cout << "Input number out of boundary, try again ";
						cin >> r >> c;
					}
					run.run(&chessBoard, size, r, c, white);
					playerTurn = 1;
				}else{
					cout << "Player White is out of available space,  changes.\n";
					playerTurn = 1;
				}
			}else {
				avaiable = false;
				for (int i = 0 ; i < size; i++){
					for (int j = 0; j <size; j++){
						b = board.checkMoveValid(&chessBoard,size, i, j, black);
						if (b){
							avaiable = true;
							break;
						}
					}
				}
				if (avaiable){
					cout << "Player Black turn, input 2 number for row and col: ";
					cin >> r >> c;
					while (r >= size || c >= size){
						cout << "Input number out of boundary, try again ";
						cin >> r >> c;
					}
					run.run(&chessBoard, size, r, c, black);
					playerTurn = 0;
				}else{
					cout << "Player Black has nowhere to go and playerTurn changes.\n";
					playerTurn = 0;
				}

			}
		}else {
			cout << "Game over" << endl;
			break;
		}
	}

	if (chessBoard.black > chessBoard.white){
		cout <<"Player Black win" << endl;
	}else if (chessBoard.black < chessBoard.white){
		cout << "Player White win" << endl;
	}else{
		cout << "Draw.....\n";
	}

	board.freeBoard(&chessBoard, size);
	return 1;
}


