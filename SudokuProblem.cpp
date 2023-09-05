#include <iostream>
#include <vector>

using namespace std;

const int N = 9; // Size of the Sudoku grid

// Function to print the Sudoku grid
void printGrid(const vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a number in the given cell
bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
    // Check if 'num' is not present in the current row or column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if 'num' is not present in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Recursive function to solve the Sudoku puzzle
bool solveSudoku(vector<vector<int>>& grid) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            // Find an empty cell
            if (grid[row][col] == 0) {
                // Try placing digits 1 through 9
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        // Place the number if it's safe
                        grid[row][col] = num;

                        // Recursively attempt to solve the rest of the puzzle
                        if (solveSudoku(grid)) {
                            return true;
                        }

                        // If the current placement doesn't lead to a solution, backtrack
                        grid[row][col] = 0;
                    }
                }

                // If no number can be placed in this cell, the puzzle is unsolvable
                return false;
            }
        }
    }

    // If all cells are filled, the puzzle is solved
    return true;
}

int main() {
    vector<vector<int>> grid(N, vector<int>(N, 0)); // Initialize the Sudoku grid

    // Input the Sudoku grid (0 represents empty cells)
    cout << "Enter the Sudoku grid (use 0 for empty cells):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    if (solveSudoku(grid)) {
        cout << "Solved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku.\n";
    }

    return 0;
}
