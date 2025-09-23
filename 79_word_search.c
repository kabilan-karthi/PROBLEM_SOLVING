#include <stdbool.h>
#include <string.h>

// DFS function
bool dfs(char** board, int rows, int cols, int r, int c,
         char* word, int index, bool** visited) {

    // If we matched the whole word
    if (word[index] == '\0') return true;

    // Boundary checks
    if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
    if (visited[r][c]) return false;               // already used this cell
    if (board[r][c] != word[index]) return false;  // mismatch

    // Mark as visited
    visited[r][c] = true;

    // Explore neighbors
    bool found = dfs(board, rows, cols, r+1, c, word, index+1, visited) ||
                 dfs(board, rows, cols, r-1, c, word, index+1, visited) ||
                 dfs(board, rows, cols, r, c+1, word, index+1, visited) ||
                 dfs(board, rows, cols, r, c-1, word, index+1, visited);

    // Backtrack
    visited[r][c] = false;

    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize;
    int cols = boardColSize[0];

    // Allocate visited array dynamically
    bool** visited = (bool**)malloc(rows * sizeof(bool*));
    for (int i = 0; i < rows; i++) {
        visited[i] = (bool*)calloc(cols, sizeof(bool));
    }

    // Try starting DFS from each cell
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (dfs(board, rows, cols, i, j, word, 0, visited)) {
                // Free memory before returning
                for (int k = 0; k < rows; k++) free(visited[k]);
                free(visited);
                return true;
            }
        }
    }

    // Free memory
    for (int k = 0; k < rows; k++) free(visited[k]);
    free(visited);

    return false;
}
