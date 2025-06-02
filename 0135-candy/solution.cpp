class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // Handle empty input

        vector<int> candies(n, 1); // Start with 1 candy for each child

        // First pass (left to right)
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Second pass (right to left)
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Sum up the candies
        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};
