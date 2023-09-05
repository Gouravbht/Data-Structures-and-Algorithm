#include <iostream>
#include <vector>

using namespace std;

// Function to print the chessboard with queens placed
void printBoard(const vector<int>& queens) {
    int n = queens.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (queens[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if placing a queen at row 'row' and column 'col' is safe
bool isSafe(const vector<int>& queens, int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check if there is a queen in the same column or diagonal
        if (queens[i] == col || queens[i] - i == col - row || queens[i] + i == col + row)
            return false;
    }
    return true;
}

// Recursive function to solve the N-Queens problem
void solveNQueens(vector<int>& queens, int row, vector<vector<int>>& solutions) {
    int n = queens.size();

    if (row == n) {
        // All queens have been successfully placed, add the solution
        solutions.push_back(queens);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solveNQueens(queens, row + 1, solutions);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    vector<int> queens(n, -1); // Initialize the chessboard with no queens

    vector<vector<int>> solutions;
    solveNQueens(queens, 0, solutions);

    int numSolutions = solutions.size();

    if (numSolutions == 0) {
        cout << "No solutions found for N = " << n << endl;
    } else {
        cout << "Solutions for N = " << n << ":\n\n";
        for (int i = 0; i < numSolutions; i++) {
            cout << "Solution " << i + 1 << ":\n";
            printBoard(solutions[i]);
        }
    }

    return 0;
}
