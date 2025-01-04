#include <iostream>
#include <vector>

// Function for sequential matrix transposition
void sequentialTranspose(int n, int m, std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& transpose) {
    // Loop through each element of the matrix to transpose it
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Transpose: element at (i, j) moves to (j, i)
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int n = 512; // Number of rows
    int m = 512; // Number of columns
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m, 1)); // Initialize matrix with 1s
    std::vector<std::vector<int>> transpose(m, std::vector<int>(n, 0)); // Empty matrix for the result

    // Perform sequential transposition
    sequentialTranspose(n, m, matrix, transpose);

    // Example output (only the first few elements of the transposed matrix)
    std::cout << "Transposed Matrix (sequential) - First element: " << transpose[0][0] << std::endl;
    return 0;
}
