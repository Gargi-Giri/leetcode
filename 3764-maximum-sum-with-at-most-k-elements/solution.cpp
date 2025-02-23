#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int> pq; // Max-heap to store the largest elements

        int n = grid.size();
        for (int i = 0; i < n; i++) {
            // Sort each row in descending order to pick the largest elements first
            sort(grid[i].rbegin(), grid[i].rend());
            for (int j = 0; j < min(limits[i], (int)grid[i].size()); j++) {
                pq.push(grid[i][j]); // Push allowed elements into max heap
            }
        }

        long long max_sum = 0;
        while (k-- > 0 && !pq.empty()) {
            max_sum += pq.top();
            pq.pop();
        }

        return max_sum;
    }
};

