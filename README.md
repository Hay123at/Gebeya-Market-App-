
# Parallel Matrix Transposition

## Overview

This project demonstrates efficient matrix transposition using different techniques to enhance performance. Matrix transposition is the operation where the rows of a matrix are swapped with columns. We compare the following approaches:

- **Sequential Implementation (Baseline)**: A straightforward, non-optimized matrix transposition.
- **Parallel Implementation using OpenMP**: Parallelized version using OpenMP for improved performance.
- **Optimized Block-Based Parallel Implementation**: A block-based approach to improve cache locality and reduce cache misses.

We evaluate these approaches by measuring execution times and calculating speedup to highlight the performance improvements.

---

## Implementation Details

### 1. Sequential Implementation (Baseline)

The sequential method iterates through each matrix element and transposes it in a single thread. This is a simple and intuitive approach, but less efficient for large matrices.

```cpp
#include <iostream>
#include <vector>

// Sequential matrix transposition
void sequentialTranspose(int n, int m, std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& transpose) {
    // Iterating through all elements of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transpose[j][i] = matrix[i][j]; // Transpose the element at [i][j] to [j][i]
        }
    }
}
```cpp
## 2. Parallel Implementation (Using OpenMP)
The OpenMP parallelization improves the execution by dividing the task of matrix transposition among multiple threads.

```cpp
#include <omp.h>
#include <vector>

// Parallel matrix transposition using OpenMP
void parallelTranspose(int n, int m, std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& transpose) {
    // Parallelizing the matrix transpose using OpenMP's parallel for directive
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transpose[j][i] = matrix[i][j]; // Transpose the element in parallel
        }
    }
}

```cpp
### Performance Results
We ran our tests on various matrix sizes to measure the performance differences between sequential and parallel implementations. Here are the execution times for different matrix sizes:

For a 512 x 512 matrix:

Sequential: 12 milliseconds
Parallel: 5 milliseconds
Speedup: 2.4x
For a 1024 x 1024 matrix:

Sequential: 50 milliseconds
Parallel: 18 milliseconds
Speedup: 2.78x
For a 2048 x 2048 matrix:

Sequential: 220 milliseconds
Parallel: 72 milliseconds
Speedup: 3.05x
As observed, the parallel implementation consistently provides a significant speedup, particularly for larger matrices.

Challenges and Adjustments
Memory Alignment Issues

Challenge: Unoptimized memory access patterns could lead to inefficient use of cache.
Solution: We optimized the memory layout to align matrices with cache lines, improving memory access performance.
False Sharing

Challenge: Multiple threads accessing adjacent memory locations could result in false sharing, hurting performance.
Solution: We implemented a block-based transposition strategy to isolate memory accesses between threads, reducing false sharing.
Load Imbalance

Challenge: Static workload distribution may cause some threads to finish earlier than others.
Solution: We utilized dynamic scheduling in OpenMP to evenly distribute the workload among threads, improving load balancing.
Cache Misses

Challenge: Inefficient access patterns can lead to a high number of cache misses, degrading performance.
Solution: The block-based method improved cache hit rates by ensuring that each block fits within the CPU cache.
Future Work and Optimizations
Block Size Tuning: Investigate optimal block sizes based on matrix size and hardware architecture to further improve cache efficiency.
GPU Acceleration: Explore GPU-based implementations (CUDA) for even faster performance on large matrices.
Advanced OpenMP Scheduling: Experiment with different OpenMP scheduling strategies (static, dynamic, guided) to find the best configuration for different matrix sizes.
How to Run the Code
## How to Run the Code

1. **Clone the repository**:
    ```bash
    git clone https://github.com/Hay123at/Parallel-Matrix-Transposition.git
    ```

2. **Navigate to the project directory**:
    ```bash
    cd Parallel-Matrix-Transposition/
    ```

3. **Compile the code with OpenMP support**:
    ```bash
    g++ -O3 -fopenmp -o matrix_transpose src/sequential_transpose.cpp src/parallel_transpose.cpp src/block_based_transpose.cpp
    ```

4. **View the results**:
    The program will execute and output the performance results, with the results saved in the `result.csv` file.

Files Included
sequential_transpose.cpp: C++ code implementing the sequential matrix transposition.
parallel_transpose.cpp: C++ code implementing the parallel matrix transposition using OpenMP.
block_based_transpose.cpp: C++ code implementing the optimized block-based parallel matrix transposition.
result.csv: Contains the execution time results for performance comparison.
README.md: This documentation file.






