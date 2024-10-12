class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int num: nums){
            bool found=false;
            for(int i=0;i<=num;i++){
                if((i|(i+1))==num){
                    ans.push_back(i);
                    found = true;
                    break;
                }
            }
            if(!found){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
