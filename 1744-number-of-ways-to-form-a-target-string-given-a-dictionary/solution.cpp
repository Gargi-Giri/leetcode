class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1000000007;
        int m = words[0].size(); // Number of columns in words
        int n = target.size();  // Length of the target

        // Step 1: Precompute character frequencies in each column
        vector<vector<int>> freq(m, vector<int>(26, 0));
        for (const string& word : words) {
            for (int i = 0; i < m; ++i) {
                freq[i][word[i] - 'a']++;
            }
        }

        // Step 2: Dynamic Programming
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1; // Base case: 1 way to form an empty target

        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                // Case 1: Skip the current column
                dp[i][j] = dp[i - 1][j];

                // Case 2: Use the current column (only if j > 0)
                if (j > 0) {
                    int charIndex = target[j - 1] - 'a';
                    dp[i][j] = (dp[i][j] + (long long)dp[i - 1][j - 1] * freq[i - 1][charIndex]) % MOD;
                }
            }
        }

        return dp[m][n];
    }
};
