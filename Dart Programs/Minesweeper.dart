import 'dart:io';
import 'dart:math';

class Minesweeper {
  List<List<String>> board;
  List<List<bool>> revealed;
  int rows;
  int cols;
  int numMines;

  Minesweeper(this.rows, this.cols, this.numMines)
      : board = List.generate(rows, (_) => List.filled(cols, ' ')),
        revealed = List.generate(rows, (_) => List.filled(cols, false)) {
    placeMines();
  }

  void placeMines() {
    int placedMines = 0;
    Random random = Random();

    while (placedMines < numMines) {
      int row = random.nextInt(rows);
      int col = random.nextInt(cols);

      if (board[row][col] != 'X') {
        board[row][col] = 'X';
        placedMines++;
      }
    }
  }

  int countAdjacentMines(int row, int col) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        int newRow = row + i;
        int newCol = col + j;

        if (newRow >= 0 &&
            newRow < rows &&
            newCol >= 0 &&
            newCol < cols &&
            board[newRow][newCol] == 'X') {
          count++;
        }
      }
    }

    return count;
  }

  void revealCell(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols || revealed[row][col]) {
      return;
    }

    revealed[row][col] = true;

    if (board[row][col] == ' ') {
      int adjacentMines = countAdjacentMines(row, col);
      board[row][col] = adjacentMines.toString();

      if (adjacentMines == 0) {
        for (int i = -1; i <= 1; i++) {
          for (int j = -1; j <= 1; j++) {
            revealCell(row + i, col + j);
          }
        }
      }
    }
  }

  void revealAllMines() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (board[i][j] == 'X') {
          revealed[i][j] = true;
        }
      }
    }
  }

  bool checkWin() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (board[i][j] != 'X' && !revealed[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  void printBoard() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (revealed[i][j]) {
          stdout.write('${board[i][j]} ');
        } else {
          stdout.write('# ');
        }
      }
      stdout.write('\n');
    }
  }

  void play() {
    while (true) {
      printBoard();

      stdout.write('Enter row: ');
      int row = int.parse(stdin.readLineSync()!);

      stdout.write('Enter column: ');
      int col = int.parse(stdin.readLineSync()!);

      if (row < 0 || row >= rows || col < 0 || col >= cols) {
        print('Invalid input. Try again.');
        continue;
      }

      if (board[row][col] == 'X') {
        print('Game over! You clicked on a mine.');
        revealAllMines();
        printBoard();
        break;
      } else {
        revealCell(row, col);

        if (checkWin()) {
          print('Congratulations! You won the game!');
          printBoard();
          break;
        }
      }
    }
  }
}

void main() {
  Minesweeper minesweeper = Minesweeper(10, 10, 10);
  minesweeper.play();
}
