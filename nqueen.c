#include <stdio.h>
#define N 4

#define true 1
#define false 0
typedef int bool;

bool isSafe(int board[N][N], int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool solveNQueens(int board[N][N], int col) {
    int i;
    if (col >= N)
        return true;
    for (i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQueens(board, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    int i, j;
    int board[N][N] = {0};
    if (!solveNQueens(board, 0)) {
        printf("Solution does not exist\n");
        return 1;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if(board[i][j]) {
                printf("Q ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    return 0;
}
