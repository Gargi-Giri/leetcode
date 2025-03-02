#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> memo;

    int dfs(string &s, int i, int j, int k) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (memo[i][j][k] != -1) return memo[i][j][k];

        if (s[i] == s[j]) {
            return memo[i][j][k] = 2 + dfs(s, i + 1, j - 1, k);
        }

        int res = max(dfs(s, i + 1, j, k), dfs(s, i, j - 1, k));

        int shift_cost = min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]));

        if (k >= shift_cost) {
            res = max(res, 2 + dfs(s, i + 1, j - 1, k - shift_cost));
        }

        return memo[i][j][k] = res;
    }

    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        memo = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return dfs(s, 0, n - 1, k);
    }
};

