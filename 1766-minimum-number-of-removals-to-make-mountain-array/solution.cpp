class Solution {
public:
    int minimumMountainRemovals(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        // Create arrays for left and right longest subsequences
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        // Fill the left array (Longest Increasing Subsequence)
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    left[i] = max(left[i], left[j] + 1);
                }
            }
        }

        // Fill the right array (Longest Decreasing Subsequence)
        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] < nums[i]) {
                    right[i] = max(right[i], right[j] + 1);
                }
            }
        }

        // Calculate minimum removals
        int minRemovals = INT_MAX;
        for (int i = 1; i < n - 1; ++i) {
            if (left[i] > 1 && right[i] > 1) {  // Valid peak
                int totalLength = left[i] + right[i] - 1; // Peak counted twice
                minRemovals = min(minRemovals, n - totalLength);
            }
        }

        return minRemovals;
    }
};

