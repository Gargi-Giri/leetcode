class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int n=0;
        int count=1;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i-1]+1==nums[i]){
                count++;
            }
            if(i-n+1>k){
                if(nums[n]+1==nums[n+1]){
                    count--;
                }
                n++;
            }
            if(i-n+1==k){
                res.push_back(count==k?nums[i]:-1);
            }
        }
        return res;
    }
};
