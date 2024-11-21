class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //vector<int> ans;
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[j]=nums[i];
                j++;
                //ans.push_back(nums[i]);
            }
        }
        return j;
    }
};
