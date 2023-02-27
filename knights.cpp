/*
Author: Ashlee Tolentino
Course: CSCI-235
Instructor: Michael Zamansky
Assignment: Project 1 - Recursive Search (Knights Tour)

This program uses a 2D array to represent the chess board. Given a starting location, this program will determine a sequence of moves that the knight can take to visit every square on the board without visiting any square more than once.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#define K 5

int solve(int x, int y, int I, int maze[K][K], int xList[], int yList[]);

int validIndex(int x, int y, int maze[K][K])
{
  return (x >= 0 && x < K && y >= 0 && y < K && maze[x][y] == -1);
}

void print_maze(int maze[K][K])
{
  for (int r = 0; r < K; r++){
    for (int c = 0; c < K; c++){
      std::cout << maze[r][c] << ":";
    }
    std::cout << std::endl;
  }
}

int solve1()
{
  int maze[K][K];

  for(int r = 0; r < K; r++){
    for(int c = 0; c < K; c++){
      maze[r][c] = -1;
    }
  }

  int xList[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
  int yList[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

  maze[0][0] = 1;

  if(solve(0, 0, 2, maze, xList, yList) == 0){
    std::cout << "No solution";
    return 0;
  }
  else {
    print_maze(maze);
  }

  return 1;
}

int solve(int x, int y, int I, int maze[K][K], int xList[8], int yList[8]) {
  int k;
  int nx;
  int ny;

  if(I > K * K){
    return 1;
  }

  for(k = 0; k < 8; k++){
    nx = x + xList[k];
    ny = y + yList[k];
    if(validIndex(nx, ny, maze)){
      maze[nx][ny] = I;
      if(solve(nx, ny, I + 1, maze, xList, yList) == 1){
	return 1;
      }
      else{
	maze[nx][ny] = -1;
      }
	 
    }
  }
  return 0;
}

int main()
{ 
  solve1();
  return 0;
}
