class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minSoFar = nums[0];
        int maxDiff = -1;
        
        for(int j = 1; j < nums.size(); ++j) {
            if(nums[j] > minSoFar) {
                maxDiff = max(maxDiff, nums[j] - minSoFar);
            } else {
                minSoFar = nums[j]; 
            }
        }
        
        return maxDiff;
    }
};

