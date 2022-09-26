/*

Name: Nathan Zhou
Date: 9/22/22

A tic-tac-toe game played locally with 2 players on the command line. Keeps track of win totals
and restarts after the end of each game.

*/

#include <iostream>
#include <cstring>

const int X_PLAYER = 1;
const int O_PLAYER = 2;
const int DRAW = 3;

bool make_move(int (&grid)[3][3], int player, char move[3]) { //try the given move, adding it to the board if valid
  int r = (int)move[0] - 97; //letter coord
  int c = move[1] - '0' - 1; //number coord
  
  if (r >= 0 && r < 3 && c >= 0 && c < 3 && !grid[r][c]) { //legal move, empty space within board
    grid[r][c] = player; 
    return true;
  }
  else { //illegal
    return false;
  }
}

int game_res(int grid[3][3]) { //check for a draw or win, returning the result
  if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) return grid[0][0]; //rows
  if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) return grid[1][0];
  if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) return grid[2][0];
  if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]) return grid[0][2]; //columns
  if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) return grid[0][1];
  if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]) return grid[0][0];
  if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) return grid[0][0]; //diagonals
  if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) return grid[0][2];

  int count = 0;
  for (int r = 0; r < 3; ++r) { //not a draw if any empty space
    for (int c = 0; c < 3; ++c) {
      if (!grid[r][c]) return 0;
    }
  }
  return DRAW;
}

void output_grid(int grid[3][3]) { //display the board with coords
  std::cout << "\n   1  2  3";
  for (int r = 0; r < 3; ++r) {
    std::cout << '\n' << (char)(r+97); //letter coords
    for (int c = 0; c < 3; ++c) {
      std::cout << "  ";
      if (grid[r][c]) std::cout << (grid[r][c] == X_PLAYER ? 'X' : 'O'); //not empty
      else std::cout << " ";

    }
  }

}

void reset_grid(int (&grid)[3][3]) { //reset, set all spaces to zero
  for (int r = 0; r < 3; ++r) {
    for (int c = 0; c < 3; ++c) {
      grid[r][c] = 0;
    }
  }
}


int main() {
  int grid[3][3];
  char move[3];
  int o_wins = 0, x_wins = 0;

  while (true) {
    //begin new game
    reset_grid(grid);
    output_grid(grid);
    int player = X_PLAYER;
    
    while (true) {
      bool valid = false;
      std::cout << "\n" << (player == X_PLAYER ? 'X' : 'O');
      std::cout << " to play. Enter a move (ex. a1, c2):\n";
      std::cin.get(move, 3); //input
      std::cin.get(); //newline
      
      if (make_move(grid, player, move)) valid = true; //valid move
      if (!valid) {
	std::cout << "\nIllegal move!\n";
	continue;
      }
      //move made, switch players and display board
      if (player == X_PLAYER) player = O_PLAYER;
      else player = X_PLAYER;
      output_grid(grid);
      
      int state = game_res(grid); //check board for any end conditions
      if (state == DRAW) {
	std::cout << "\nThe game has ended in a draw.\n";
	break;
      }
      if (state == X_PLAYER) {
	std::cout << "\nX has won!\n";
	++x_wins;
	break;
      }
      if (state == O_PLAYER) {
	std::cout << "\nO has won!\n";
	++o_wins;
	break;
      }
    }
    std::cout << "\nScores:\nX - " << x_wins << "\nO - " << o_wins << "\n";
  }
}
