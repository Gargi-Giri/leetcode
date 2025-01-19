#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        const long long INF = 1e18;

        // DP array: dp[i][j][k]
        // i: index of the house
        // j: color of the current house
        // k: color of the equidistant house (n-i-1)
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(3, vector<long long>(3, INF)));

        // Base case: Initialize the first house
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j != k) {
                    dp[0][j][k] = cost[0][j] + cost[n - 1][k];
                }
            }
        }

        // Fill DP table
        for (int i = 1; i < n / 2; ++i) {
            for (int j = 0; j < 3; ++j) {         // Current house color
                for (int prev = 0; prev < 3; ++prev) { // Previous house color
                    if (j == prev) continue;      // Adjacent constraint
                    for (int k = 0; k < 3; ++k) {     // Equidistant house color
                        for (int eqPrev = 0; eqPrev < 3; ++eqPrev) { // Previous equidistant color
                            if (k == eqPrev || j == k) continue; // Equidistant constraint
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][prev][eqPrev] + cost[i][j] + cost[n - i - 1][k]);
                        }
                    }
                }
            }
        }

        // Final calculation: Extract minimum cost
        long long result = INF;
        for (int j = 0; j < 3; ++j) {     // Last house color
            for (int k = 0; k < 3; ++k) { // Equidistant house color
                if (j != k) {
                    result = min(result, dp[n / 2 - 1][j][k]);
                }
            }
        }

        return result;
    }
};

