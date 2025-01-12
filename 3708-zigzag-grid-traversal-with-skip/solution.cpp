#include <vector>
using namespace std;

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> result;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            if (i % 2 == 0) { 
                for (int j = 0; j < cols; j++) {
                    if ((i + j) % 2 == 0) { 
                        result.push_back(grid[i][j]);
                    }
                }
            } else { 
                for (int j = cols - 1; j >= 0; j--) {
                    if ((i + j) % 2 == 0) { 
                        result.push_back(grid[i][j]);
                    }
                }
            }
        }

        return result;
    }
};

