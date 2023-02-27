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

int current_pos = 1;
int final_pos = 25;
int path = 0;

int load_maze(std::string filename, std::string *maze) {
  std::ifstream infile(filename);
  int i = 0;
  while(std::getline(infile, maze[i])){
    i++;
  }
  return i;
}

void print_maze(std::string maze[], int lines){
  std::cout << "[0;0H\n";

  for (int i = 0; i < lines; i++){
    std::cout << maze[i] << "\n";
  }
  
}




void solve(std::string maze[], int lines, int row, int col, bool &solved) {
  if (maze[row][col] == final_pos){
    solved = true;
    return;
  }
  if (maze[row][col] == current_pos{
    return; 
  }

  maze[row][col] = current_pos;
  usleep(80000);
  print_maze(maze,lines);

  if (!solved) solve(maze,lines,row-1,col+2, solved);
  if (!solved) solve(maze,lines,row-1,col-2, solved);
  if (!solved) solve(maze,lines,row-2,col+1, solved);
  if (!solved) solve(maze,lines,row-2,col-1, solved);
  if (!solved) solve(maze,lines,row+1,col+2, solved);
  if (!solved) solve(maze,lines,row+1,col-2, solved);
  if (!solved) solve(maze,lines,row+2,col+1, solved);
  if (!solved) solve(maze,lines,row+2,col-1, solved);

}



int main()
{
  std::string maze[27];
  int lines;
  bool solved = false;
  
  lines = load_maze("knights.dat", maze);
  print_maze(maze,lines);
  solve(maze,lines,0,0,solved);
  return 0;
}
