class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();        // Number of rows
        int n = grid[0].size();     // Number of columns
        int totalOperations = 0;    // To accumulate the total number of operations

        for (int j = 0; j < n; ++j) {  // Iterate over each column
            for (int i = 0; i < m - 1; ++i) {  // Compare consecutive rows in the column
                if (grid[i][j] >= grid[i + 1][j]) {
                    // Calculate the operations needed to fix the violation
                    int operations = grid[i][j] - grid[i + 1][j] + 1;
                    totalOperations += operations;
                    grid[i + 1][j] += operations;  // Update the grid to maintain strictly increasing condition
                }
            }
        }

        return totalOperations;
    }
};

