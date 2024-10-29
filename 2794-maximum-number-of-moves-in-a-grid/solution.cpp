class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));

        // Helper function for DFS
        function<int(int, int)> dfs = [&](int row, int col) {
            if (memo[row][col] != -1) {
                return memo[row][col];
            }

            int maxMove = 0;
            // Possible moves: up-right, straight-right, down-right
            for (int newRow = row - 1; newRow <= row + 1; ++newRow) {
                if (newRow >= 0 && newRow < m && col + 1 < n) {
                    if (grid[newRow][col + 1] > grid[row][col]) {
                        maxMove = max(maxMove, 1 + dfs(newRow, col + 1));
                    }
                }
            }

            memo[row][col] = maxMove;
            return maxMove;
        };

        int maxMoves = 0;
        for (int i = 0; i < m; ++i) {
            maxMoves = max(maxMoves, dfs(i, 0));
        }

        return maxMoves;
    }
};

