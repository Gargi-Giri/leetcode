class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> coverage(n + 1, 0);  // difference array

        // Apply range increment using difference array
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            coverage[l]++;
            if (r + 1 < n) coverage[r + 1]--;
        }

        // Build prefix sum to get actual coverage
        int cover = 0;
        for (int i = 0; i < n; ++i) {
            cover += coverage[i];
            if (nums[i] > cover) return false; // Not enough queries to reduce nums[i] to 0
        }

        return true;
    }
};

