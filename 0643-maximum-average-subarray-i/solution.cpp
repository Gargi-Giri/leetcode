class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum=0,currSum=0;
        //int n=nums.size();
        for(int i=0;i<k;i++){
            currSum+=nums[i];
        }
        maxSum=currSum;
        for(int i=k;i<nums.size();i++){
            currSum+=nums[i]-nums[i-k];
            maxSum=max(currSum,maxSum);
        }
        return maxSum/k;
    }
};
