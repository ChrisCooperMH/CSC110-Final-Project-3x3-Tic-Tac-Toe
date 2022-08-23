#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 3, COLS = 3;
int showMenu();
void showBoard(string[][3]);
void updateBoard(int,int,string[][3],bool[][3],int);
void computerMove(string[][3],bool[][3]);
bool checkWinner(string[][3]);
void resetBoard(string[][3], bool[][3]);
void switchPlayer(int&);

int main() {
  srand ( time(NULL) );
  string board[ROWS][COLS] = { {"1","2","3"},{"4","5","6"},{"7","8","9"} };
  bool switches[ROWS][COLS] = { {false, false, false}, {false, false, false}, {false, false, false} };
  int menu;
  int row;
  int col;
  int player=1;
  showBoard(board);
  cout << "Welcome to Tic-Tac-Toe. Please enter your choice of gamemode." << endl;
  menu = showMenu();
  if (menu == 3) {
    return 0;
  }
  else if (menu == 1) {
    cout << "You've selected Player v. Player." << endl;
    do {
      cout << "Player " << player << ", please select your row. (1-3)" << endl;
      cin >> row;
      cout << "Player " << player << ", please select your column. (1-3)" << endl;
      cin >> col;
      updateBoard(row,col,board,switches,player);
      switchPlayer(player);
    } while (checkWinner(board) == false);
    if (checkWinner(board)) {
      switchPlayer(player);
      cout << "Player " << player << " has won!" << endl;
    }
  }
  else if (menu == 2) {
    cout << "You've selected Player v. Computer." << endl;
    do {
      cout << "Player 1, please select your row. (1-3)" << endl;
      cin >> row;
      cout << "Player 1, please select your column. (1-3)" << endl;
      cin >> col;
      updateBoard(row,col,board,switches,1);
      switchPlayer(player);
      cout << "Player 2's turn." << endl;
      computerMove(board,switches);
    } while (checkWinner(board) == false);
    if (checkWinner(board)) {
      switchPlayer(player);
      cout << "Player " << player << " has won!" << endl;
    }
  }
  else {
    return 0;
  }
  resetBoard(board,switches);
} 

int showMenu() {
  string choice;
  do {
    cout << "a. vs Player" << endl << "b. vs Computer" << endl <<"c. Quit" << endl;
    cin >> choice;
  } while (choice != "a" && choice != "A" && choice != "b" && choice != "B" && choice != "c" && choice != "C");
  if (choice == "a" || choice == "A") {
    return 1;
  }
   if (choice == "b" || choice == "B") {
    return 2;
  }
   if (choice == "c" || choice == "C") {
    return 3;
  }
  return 0;
}

void showBoard(string board[][3]) {
  //first row
  cout << "---------------" << endl;
  cout << "| " << board[0][0] << " |" << "| " << board[0][1] << " |" << "| " << board[0][2] << " |" << endl;
  cout << "---------------" << endl;
  //second row
  cout << "| " << board[1][0] << " |" << "| " << board[1][1] << " |" << "| " << board[1][2] << " |" << endl;
  cout << "---------------" << endl;
  //third row
  cout << "| " << board[2][0] << " |" << "| " << board[2][1] << " |" << "| " << board[2][2] << " |" << endl;
  cout << "---------------" << endl;
}

void updateBoard(int row, int col, string board[][3], bool switches[][3], int player) {
  row = row-1;
  col = col-1;
  if (switches[row][col] != true) {
    switches[row][col] = true;
    if (player == 1) {
      board[row][col] = "X";
      showBoard(board);
    }
    if (player == 2) {
      board[row][col] = "O";
      showBoard(board);
    }
  }
  else {
    cout << "Position already taken. Try again." << endl;
    cout << "Enter your row." << endl;
    cin >> row;
    cout << "Enter your column." << endl;
    cin >> col;
    updateBoard(row,col,board,switches,player);
  }
}

void switchPlayer(int &player) {
  if (player == 1) {
    player = 2;
  }
  else if (player == 2) {
    player = 1;
  }
}

bool checkWinner(string board[][3]) {
  //ROWS
  if (board[0][0] == "X" && board[0][1] == "X" && board[0][2] == "X") {
    return true;
  }
  if (board[1][0] == "X" && board[1][1] == "X" && board[1][2] == "X") {
    return true;
  }
  if (board[2][0] == "X" && board[2][1] == "X" && board[2][2] == "X") {
    return true;
  }
  if (board[0][0] == "O" && board[0][1] == "O" && board[0][2] == "O") {
    return true;
  }
  if (board[1][0] == "O" && board[1][1] == "O" && board[1][2] == "O") {
    return true;
  }
  if (board[2][0] == "O" && board[2][1] == "O" && board[2][2] == "O") {
    return true;
  }
  //COLUMNS
  if (board[0][0] == "X" && board[1][0] == "X" && board[2][0] == "X") {
    return true;
  }
  if (board[0][1] == "X" && board[1][1] == "X" && board[2][1] == "X") {
    return true;
  }
  if (board[0][2] == "X" && board[1][2] == "X" && board[2][2] == "X") {
    return true;
  }
  if (board[0][0] == "O" && board[1][0] == "O" && board[2][0] == "O") {
    return true;
  }
  if (board[0][1] == "O" && board[1][1] == "O" && board[2][1] == "O") {
    return true;
  }
  if (board[0][2] == "O" && board[1][2] == "O" && board[2][2] == "O") {
    return true;
  }
  //DIAGONALS
  if (board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X") {
    return true;
  }
  if (board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "X") {
    return true;
  }
  if (board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O") {
    return true;
  }
  if (board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "O") {
    return true;
  }
  return false;
}

void computerMove(string board[][3], bool switches[][3]) {
  int row = rand()%3;
  int col = rand()%3;
  if (switches[row][col] == false) {
    board[row][col] = "O";
    switches[row][col] = true;
    showBoard(board);
  } 
  else if (switches[row][col] == true) {
    computerMove(board,switches);
  }
}

void resetBoard(string board[][3], bool switches[][3]) {
  board[0][0] = "1";
  board[0][1] = "2";
  board[0][2] = "3";
  board[1][0] = "4";
  board[1][1] = "5";
  board[1][2] = "6";
  board[2][0] = "7";
  board[2][1] = "8";
  board[2][2] = "9";
  for (int i = 0; i < 3; i++) {
    for (int x = 0; x < 3; x++) {
      switches[i][x] = false;
    }
  }
  showBoard(board);
}