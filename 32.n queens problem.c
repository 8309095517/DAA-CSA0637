#include <stdio.h>
#include <stdbool.h>

#define N 8

// Function prototypes
void printSolution(int board[N][N]);
bool isSafe(int board[N][N], int row, int col);
bool solveNQueensUtil(int board[N][N], int row);
bool solveNQueens();

// Function to print the solution
void printSolution(int board[N][N]) 
{
        
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;
  
    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
  
    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
  
    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
  
    return true;
}

// Recursive function to solve N-Queens problem
bool solveNQueensUtil(int board[N][N], int col) {
    // If all queens are placed then return true
    if (col >= N)
        return true;
  
    // Try placing queen in all rows in this column
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;
  
            // Recur to place rest of the queens
            if (solveNQueensUtil(board, col + 1))
                return true;
  
            // If placing queen in board[i][col] doesn't lead to a solution, then remove the queen from board[i][col]
            board[i][col] = 0; 
        }
    }
  
    // If the queen can't be placed in any row in this column, then return false
    return false;
}

// Main function to solve N-Queens problem
bool solveNQueens() {
    int board[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0} };
  
    if (solveNQueensUtil(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }
  
    printSolution(board);
    return true;
}

// Driver program
int main() {
    solveNQueens();
    return 0;
}
