class Solution {
public:
    const int MOD = 1e9 + 7;

    int numSubseq(vector<int>& nums, int tg) {
        // Sort the array to use the two pointers approach
        sort(nums.begin(), nums.end());

        int cnt = 0; // To store the final count of valid subsequences
        int n = nums.size();

        // Precompute powers of 2 up to n, modulo MOD
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2LL) % MOD;
        }

        int l = 0, r = n - 1;

        // Use two pointers to find valid subsequences
        while (l <= r) {
            // Minimum + maximum element of the subsequence
            int sum = nums[l] + nums[r];
            
            if (sum <= tg) {
                // If sum of min (nums[l]) and max (nums[r]) <= target
                // All subsequences formed by fixing nums[l] as the min element
                // and picking any subset of elements between l+1 and r are valid.
                cnt = (cnt + pow2[r - l]) % MOD;
                l++;
            } else {
                // If the sum is too large, decrease the max element
                r--;
            }
        }

        return cnt;
    }
};
