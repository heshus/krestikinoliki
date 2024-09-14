#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;     // длина поля
vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));          // игровое поле

void printBoard() 
{
    cout << "  0 1 2\n";     //колонка чисел
    for (int i = 0; i < SIZE; ++i) 
    {
        cout << i << ' ';       // Row numbers
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << '|'; // расзделитель клеток
        }
        cout << '\n';
        if (i < SIZE - 1) {
            cout << "  -----\n"; // разделитель строк
        }
    }
}

bool checkWin(char player) 
{
    // прорверить клетки и колонки
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || (board[0][i] == player && board[1][i] == player && board[2][i] == player)) 
            {
            return true;
        }
    }
    // проверить диагонали 
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player)  || (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
        {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char currentPlayer = 'X';
    int row, col;

    while (true) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter row and column ( 1 2): ";
        cin >> row >> col;

        // ошибочный ввод
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            cout << "Invalid move. Please try again.\n";
            continue;
        }

        board[row][col] = currentPlayer; // Размещение символа текущего игрока

        if (checkWin(currentPlayer)) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isBoardFull()) {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }
    //переключение игрока
       if (currentPlayer == 'X') 
       {
    currentPlayer = 'O';} 
        else {
    currentPlayer = 'X';
}

    }

    return 0;
}
