class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int , int> m;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                m[nums[i]]++;
            }
        }
        int ans=-1;
        int maxFreq=0;
        for(auto &x : m){
            if(x.second>maxFreq||(x.second==maxFreq&&(ans==-1||x.first<ans))){
                maxFreq=x.second;
                ans=x.first;
            }
        }
        return ans;
    }
};
