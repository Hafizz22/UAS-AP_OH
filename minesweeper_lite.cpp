
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 5;
const int BOMBS = 5;

struct Cell {
    bool isBomb = false;
    bool isRevealed = false;
    int adjacentBombs = 0;
};

vector<vector<Cell>> board(SIZE, vector<Cell>(SIZE));

void placeBombs() {
    int bombsPlaced = 0;
    while (bombsPlaced < BOMBS) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;
        if (!board[r][c].isBomb) {
            board[r][c].isBomb = true;
            bombsPlaced++;
        }
    }
}

void calculateAdjacents() {
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (board[r][c].isBomb) continue;
            int count = 0;
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE && board[nr][nc].isBomb)
                    count++;
            }
            board[r][c].adjacentBombs = count;
        }
    }
}

void printBoard(bool revealAll = false) {
    cout << "\n   ";
    for (int c = 0; c < SIZE; c++) cout << c << " ";
    cout << endl;

    for (int r = 0; r < SIZE; r++) {
        cout << r << "  ";
        for (int c = 0; c < SIZE; c++) {
            if (revealAll || board[r][c].isRevealed) {
                if (board[r][c].isBomb)
                    cout << "* ";
                else
                    cout << board[r][c].adjacentBombs << " ";
            } else {
                cout << "# ";
            }
        }
        cout << endl;
    }
}

bool reveal(int r, int c) {
    if (r < 0 || r >= SIZE || c < 0 || c >= SIZE || board[r][c].isRevealed)
        return true;
    board[r][c].isRevealed = true;
    if (board[r][c].isBomb)
        return false;
    if (board[r][c].adjacentBombs == 0) {
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr != 0 || dc != 0)
                    reveal(r + dr, c + dc);
            }
        }
    }
    return true;
}

bool isWin() {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (!board[r][c].isBomb && !board[r][c].isRevealed)
                return false;
        }
    }
    return true;
}

int main() {
    srand(time(0));
    placeBombs();
    calculateAdjacents();

    bool alive = true;
    while (alive) {
        printBoard();
        int r, c;
        cout << "\nMasukkan baris dan kolom (misal: 1 2): ";
        cin >> r >> c;

        if (!reveal(r, c)) {
            cout << "\n\U0001F4A5 Kamu kena bom! Game Over.\n";
            alive = false;
            printBoard(true);
            break;
        }

        if (isWin()) {
            cout << "\n\U0001F389 Selamat! Kamu menang!\n";
            printBoard(true);
            break;
        }
    }

    return 0;
}
