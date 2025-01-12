#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1e9)));

        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
            dp[0][0][0] = coins[0][0];
        } else {
            dp[0][0][0] = coins[0][0];
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (i == 0 && j == 0) continue;

                    if (i > 0) {
                        int new_coins = dp[i - 1][j][k];
                        if (coins[i][j] < 0) {
                            if (k < 2) {
                                dp[i][j][k + 1] = max(dp[i][j][k + 1], new_coins);
                            }
                            dp[i][j][k] = max(dp[i][j][k], new_coins + coins[i][j]); // Corrected this line
                        } else {
                            dp[i][j][k] = max(dp[i][j][k], new_coins + coins[i][j]);
                        }
                    }

                    if (j > 0) {
                        int new_coins = dp[i][j - 1][k];
                        if (coins[i][j] < 0) {
                            if (k < 2) {
                                dp[i][j][k + 1] = max(dp[i][j][k + 1], new_coins);
                            }
                            dp[i][j][k] = max(dp[i][j][k], new_coins + coins[i][j]); // Corrected this line
                        } else {
                            dp[i][j][k] = max(dp[i][j][k], new_coins + coins[i][j]);
                        }
                    }
                }
            }
        }

        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};
