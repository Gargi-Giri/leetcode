class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0, count = 0;
        
        for (int i = 0; i < n - 1; i++) {
            leftSum += nums[i];
            // Check if (2 * leftSum - totalSum) is even
            if ((2 * leftSum) % 2 == totalSum % 2) {
                count++;
            }
        }
        
        return count;
    }
};
