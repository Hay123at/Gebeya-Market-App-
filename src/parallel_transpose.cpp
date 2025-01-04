#include <omp.h>
#include <vector>

void parallelTranspose(int n, int m, std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& transpose) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transpose[j][i] = matrix[i][j];  // Transpose the element in parallel
        }
    }
}

int main() {
    int n = 512, m = 512;  // Matrix dimensions
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m, 1));  // Initialize matrix
    std::vector<std::vector<int>> transpose(m, std::vector<int>(n));   // Initialize transpose matrix

    parallelTranspose(n, m, matrix, transpose);  // Perform parallel transposition

    return 0;
}
