#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int EMPTY{0}, X{1}, O{2};
int main(int argc, char* argv[]) {

  vector<vector<int>> board(3, vector<int>(3, EMPTY));

  int empty_count{9};
  int whose_turn{X};
  bool playing{true};
  while (playing) {
    cout << "Board:" << endl;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
      if (board[i][j] == EMPTY) {
        cout << "." ;
      }
      else if (board[i][j] == X) {
        cout << "x";
      }
      else {
        cout << "o";
      }
    }
    cout << endl;
  }

  if (whose_turn == X) {
    cout << "It is X's turn." << endl;
  }
  else {
    cout << "It is O's turn." << endl;
  }

  int row;
  do {
    cout << "Row (0-2): ";
    cin >> row;
  } while ((row < 0) || (row > 2));

  int column;
  do {
    cout << "Column (0-2): ";
    cin >> column;
  } while ((column < 0) || (column > 2));

  int square = board[row][column];
  if ((square == X) || (square == O)) {
    cout << "That cell is already taken, you lose your turn." << endl;
  }
  else {
    board[row][column] = whose_turn;
    empty_count--;
  }

  if ((whose_turn == board[0][0]) && (whose_turn == board[1][1]) &&
      (whose_turn == board[2][2])) {
    cout << "Diagonal WIN!" << endl;
    playing = false;
      }

  if ((whose_turn == board[0][2]) && (whose_turn == board[1][1]) &&
      (whose_turn == board[2][0])) {
    cout << "Diagonal WIN!" << endl;
    playing = false;
      }

  for (int i = 0; i < 3; i++) {
    if ((whose_turn == board[i][0]) && (whose_turn == board[i][1]) &&
        (whose_turn == board[i][2])) {
      cout << "Horizontal WIN!" << endl;
      playing = false;
  }

  for (int j = 0; j < 3; j++) {
    if ((whose_turn == board[0][j]) && (whose_turn == board[1][j]) &&
        (whose_turn == board[2][j])) {
      cout << "Vertical WIN!" << endl;
      playing = false;
  }
}

  if (empty_count == 0) {
    cout << "DRAW!" << endl;
    playing = false;
  }

  if (whose_turn == X) {
    whose_turn = O;
  }
  else {
    whose_turn = X;
    }
  }
}
  return 0;
}
