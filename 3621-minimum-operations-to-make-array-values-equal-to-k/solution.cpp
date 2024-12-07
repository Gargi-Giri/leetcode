class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        int operations=0;
        int n=nums.size();
        while(!nums.empty()&&nums[0]>k){
            int h=nums[0];
            int idx=1;
            while(idx<nums.size()&&nums[idx]==h){
                idx++;
            }
            if(h<=k) return -1;
            nums.erase(nums.begin(),nums.begin()+idx);
            operations++;
            
        }
        for(int num : nums){
            if(num!=k) return -1;
        }
        return operations;
    }
};
