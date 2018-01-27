#include <stdlib.h>
#include <stdio.h>
#include "reverse.h"

void allocateOthello(const int boradSize, int ***othello) {
  int i, j;

  (*othello) = (int **) malloc(boradSize * sizeof(int*));
  for (i = 0; i < boradSize; i++) 
    (*othello)[i] = (int *) malloc(boradSize*2 * sizeof(int));

}


void intializeOthello(const int boradSize, int **othello) {
  int i, j;
  for (i = 0; i < boradSize; i++) 
 
    for (j = 0; j < (2*boradSize-1); j++) 

      othello[i][j] = '.'; 
}


void printOthello(const int boradSize, int **othello) {
  int i, j;
  int k = i /2;
  int k_1 = k -1;

  printf("   ");
  for (i = 0; i < boradSize; i++){
  	printf("%d  ", i);
  }printf("\n");

  for (i = 0; i < boradSize; i++) {
  	printf("%d  ", i);
    for (j = 0; j < boradSize; j++) {
    	if (i == k && j == k) {
    		othello[i][j] = 'x';
    	}else if (i == k_1 && j == k_1){
    		othello[i][j] = 'x';
    	}else if (i == k_1 && j == k){
    		othello[i][j] = 'o';
    	}else if (i == k && j == k_1){
    		othello[i][j] = 'o';
    	}
      printf("%c  ", othello[i][j]);
    }
    printf("\n");
  }
}

/*
int ChecktheValidInput(BoardInfo b, int row, int col,int size,int reverse){
    row = row - 1;
    col = col - 1;
    size = size - 1;
    Board current = b.turn;
    
    if (b.Info[row][col] == Empty){
        
        //Check North
        int upcount = 0;
        int up = row-1;
        if (up < 0){upcount = 0;}
        else{
        while (b.Info[up][col] != current){
            if (b.Info[up][col] == Empty){upcount=0;break;}
            upcount++;
            up--;
            if (up < 0){
                upcount = 0;
                break;
            }
        }
        }
        //Check south
        int downcount = 0;

        int down = row+1;
        if (down > size){downcount = 0;}
        else{
        
        while (b.Info[down][col] != current){
            if (b.Info[down][col] == Empty){downcount=0;break;}
            downcount++;
            down++;
            if (down > size){
                downcount = 0;
                break;
            }
        }
        }
        //Check west
        int leftcount = 0;
        int left = col-1;
        if (left < 0){leftcount = 0;}
        else{
        while (b.Info[row][left] != current ){
            if (b.Info[row][left] == Empty){leftcount=0;break;}
            leftcount++;
            left--;
            if (left < 0){
                leftcount = 0;
                break;
            }
        }
        }
        //Check East
        int rightcount = 0;
        int right = col+1;
        if(right > size){rightcount = 0;}
        else{
        
        while (b.Info[row][right] != current){
            if (b.Info[row][right] == Empty){rightcount=0;break;}
            rightcount++;
            right++;
            if (right > size){
                rightcount = 0;
                break;
            }
        }
        }
        //Check southWest
        int southWestcount = 0;
        int southWestrow = row+1;
        int southWestcol = col-1;
        if (southWestrow > size || southWestcol < 0){southWestcount = 0;}
        else{
        
        while (b.Info[southWestrow][southWestcol] != current){
            if(b.Info[southWestrow][southWestcol] == Empty){southWestcount=0; break;}
            southWestcount++;
            southWestrow++;
            southWestcol--;
            if (southWestrow > size ||southWestcol <0){
                southWestcount = 0;
                break;
            }
        }
        }
        //Check westNorth
        int westNorthcount = 0;
        int westNorthrow = row-1;
        
        int westNorthcol = col-1;
        if (westNorthrow < 0 || westNorthcol < 0){westNorthcount = 0;}
        else{
        
        
        while (b.Info[westNorthrow][westNorthcol] != current){
            if (b.Info[westNorthrow][westNorthcol] == Empty){LUcount=0;break;}
            westNorthcount++;
            westNorthrow--;
            westNorthcol--;
            if (westNorthrow <0 ||westNorthcol <0){
                westNorthcount = 0;
                break;
            }
        }
        }
        //Check Eastsouth
        int Eastsouthcount = 0;
        int Eastsouthrow = row+1;
        int Eastsouthcol = col+1;
        if(Eastsouthcol > size||Eastsouthrow > size){Eastsouthcount = 0;}
        else{
        
        while (b.Info[Eastsouthrow][Eastsouthcol] != current){
            if (b.Info[Eastsouthrow][Eastsouthcol] == Empty){Eastsouthcount=0;break;}
            Eastsouthcount++;
            Eastsouthrow++;
            Eastsouthcol++;
            if (Eastsouthrow > size ||Eastsouthcol >size){
                Eastsouthcount = 0;
                break;
            }
        }
        }
        //Check Eastnorth
        int eastNorthcount = 0;
        int eastNorthrow = row-1;
        int eastNorthcol = col+1;
        if(eastNorthcol > size||eastNorthrow < 0){eastNorthcount = 0;}
        else{
        while (b.Info[eastNorthrow][eastNorthcol] != current ){
            if (b.Info[eastNorthrow][eastNorthcol] ==Empty){RUcount=0;break;}
            eastNorthcount++;
            eastNorthrow--;
            eastNorthcol++;
            if (eastNorthrow < 0 || eastNorthcol >size){
                eastNorthcount = 0;
                break;
            }
        }
        }
        
        if(reverse == 1){
            if (upcount + downcount + leftcount + rightcount + southWestcount + westNorthcount + eastSouthcount + eastNorthcount > 0 ){
            
            //north reverse
            up = row;
            for (int i = 0; i < upcount; i++) {
                up--;
                b.Info[up][col] = current;
            }
            //south reverse
            down = row;
            for (int i = 0; i < downcount; i++) {
                down++;
                b.Info[down][col] = current;
            }
            //west reverse
            left = col;
            for (int i = 0; i < leftcount; i++) {
                left--;
                b.Info[row][left] = current;
            }
            //east reverse
            right = col;
            for (int i = 0; i < rightcount; i++) {
                right++;
                b.Info[row][right] = current;
            }
            //southWest reverse
            southWestrow = row;
            southWestcol = col;
            for (int i = 0; i < southWestcount; i++) {
                southWestrow++;
                southWestcol--;
                b.Info[southWestrow][southWestcol] = current;
            }
            //westNorth reverse
            westNorthrow = row;
            westNorthcol = col;
            for (int i = 0; i < westNorthcount; i++) {
                westNorthrow--;
                westNorthcol--;
                b.Info[westNorthrow][westNorthcol] = current;
            }
            //eastSouth reverse
            eastSouth row = row;
            eastSouth col = col;
            for (int i = 0; i < eastSouth count; i++) {
                eastSouth row++;
                eastSouth col++;
                b.Info[eastSouthrow][eastSouthcol] = current;
            }
            //eastNorth reverse
            eastNorthrow = row;
            eastNorthcol = col;
            for (int i = 0; i < eastNorthcount; i++){
                eastNorthrow--;
                eastNorthcol++;
                b.Info[eastNorthrow][eastNorthcol] = current;
            }
            return 1;
        }
            return 2;
        }
        if(reverse == 0){
            if (upcount + downcount + leftcount + rightcount + southWestcount + westNorthcount + eastSouthcount + eastNorthcount > 0 ){
                return 3;
            }
            return 4;
        }
        return 0;
    }
    return 0;
}

*/


void deallocateOthello(const int boradSize, int ***othello) {
  int i;
  for (i = 0; i < boradSize; i++) {
  	 free((*othello)[i]);
  	}
 
  free(*othello);
}

int main() {

	int **othello;	
	int boradSize;
	int playerOneI, playerOneY;
	int playerTwo;
	int totalChess;
	int playerOneChess = 2;
	int playerTwoChess = 2; 

	do{
	printf("Please enter the size of the borad: ");
	scanf("%d", &boradSize);
	}while ((boradSize % 2));
	
	allocateOthello(boradSize, &othello);

	intializeOthello((const int) boradSize, othello);
	printOthello((const int) boradSize, othello);

	totalChess  = boradSize * boradSize;


	do {
	printf("The total chess is %d，You have %d chess\n", totalChess, playerOneChess );
	printf("Player One, place your chess: ");
	scanf("%d%d", &playerOneI, &playerOneY);
	}while(playerOneI < 0 && playerOneY < 0);

	//ChecktheValidInput()
	
	deallocateOthello(boradSize, &othello);
	

	return 0;
}