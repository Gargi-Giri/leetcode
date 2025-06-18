class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        //1,3,4,8,7,9,3,5,1
        //1,1,3,3,4,5,7,8,9
        //0,1,2,3,4,5,6,7,8
        sort(nums.begin(),nums.end());//TC : O(NlogN)
        vector<vector<int>> result;//SC: O(N)
        for(int i=0;i<n;i+=3){//TC: O(N)
            if(nums[i+2]-nums[i]>k){
                return {};
            }
            else{
                result.push_back({nums[i],nums[i+1],nums[i+2]});
            }
        }
        return result;
    }
};
