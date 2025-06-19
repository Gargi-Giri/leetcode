class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());//TC: O(NlogN)
        int count=0;//SC: O(1)
        int i=0,n=nums.size();
        while(i<n){
            int start=nums[i];
            count++;
            while(i<n && nums[i]-start<=k){
                i++;
            }
        }
        return count;
    }
};

