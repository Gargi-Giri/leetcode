class Solution {
public:
    // Find last event ending before events[index].start
    int bSearch(vector<vector<int>>& events, int index) {
        int low = 0, high = index;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][1] < events[index][0]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }

    // Sort by end time
    static bool sortByEnd(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), sortByEnd);

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                int lastNonOverlap = bSearch(events, j - 1) + 1;
                dp[i][j] = max(
                    dp[i][j - 1],
                    events[j - 1][2] + dp[i - 1][lastNonOverlap]
                );
            }
        }

        return dp[k][n];
    }
};
