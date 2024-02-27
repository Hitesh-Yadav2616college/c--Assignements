#include <iostream>
#include <cstdlib>

using namespace std;

class TickTackToe {
    private:
    char board[3][3];
    char currentPlayer = 'X';

    public:
    void initialize() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void drawBoard() {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}


bool Valid(int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}


bool checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return true;
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return true;
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return true;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return true;

    return false;
}


void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void start() {
    initialize();
    bool gameOver = false;

    while (!gameOver) {
        drawBoard();

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (!Valid(row, col)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWinner()) {
            drawBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (isBoardFull()) {
            drawBoard();
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            switchPlayer();
        }
    }
}
};

int main() {
    TickTackToe obj;
    obj.start();

    return 0;
}