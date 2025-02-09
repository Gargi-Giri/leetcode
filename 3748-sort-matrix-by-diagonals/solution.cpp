#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diagonals;

        // Collect all diagonals
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diagonals[i - j].push_back(grid[i][j]);
            }
        }

        // Sort diagonals based on the given rules
        for (auto& [key, values] : diagonals) {
            if (key >= 0) {
                sort(values.rbegin(), values.rend()); // Descending order
            } else {
                sort(values.begin(), values.end()); // Ascending order
            }
        }

        // Put sorted values back into the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = diagonals[i - j].front();
                diagonals[i - j].erase(diagonals[i - j].begin());
            }
        }

        return grid;
    }
};

