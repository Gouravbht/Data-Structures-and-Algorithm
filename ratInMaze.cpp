#include <iostream>
#include <vector>

using namespace std;

// Constants for maze size (you can adjust these as needed)
const int N = 5; // Number of rows
const int M = 5; // Number of columns

// Function to print the solution path
void printSolution(vector<vector<int>>& sol) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a given cell is a valid move
bool isSafe(int x, int y, vector<vector<int>>& maze) {
    // Check if the cell is within the maze boundaries and is not an obstacle (1)
    return (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 0);
}

// Recursive function to solve the Rat in a Maze problem
bool solveMaze(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol) {
    // If the rat has reached the destination (bottom-right corner)
    if (x == N - 1 && y == M - 1) {
        sol[x][y] = 1; // Mark the destination cell as part of the path
        return true;
    }

    // Check if the current cell is a valid move
    if (isSafe(x, y, maze)) {
        // Mark the current cell as part of the path
        sol[x][y] = 1;

        // Move right (x, y+1)
        if (solveMaze(maze, x, y + 1, sol))
            return true;

        // Move down (x+1, y)
        if (solveMaze(maze, x + 1, y, sol))
            return true;

        // If neither right nor down is a valid move, backtrack
        sol[x][y] = 0;
        return false;
    }

    return false; // If the current cell is not a valid move
}

int main() {
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0}
    };

    vector<vector<int>> sol(N, vector<int>(M, 0)); // Initialize the solution matrix

    if (solveMaze(maze, 0, 0, sol)) {
        cout << "Solution found:" << endl;
        printSolution(sol);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
