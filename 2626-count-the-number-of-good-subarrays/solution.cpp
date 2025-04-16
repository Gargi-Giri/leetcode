class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int curr = 0, i = 0, j = 0;
        int n = nums.size();
        long long ans = 0;
        unordered_map<int,int>mp;
        while(i < n){
            while(i < j && curr >= k){
                if(mp[nums[i]] >= 2) curr -= (mp[nums[i]]-1);
                mp[nums[i]]--;
                i++;
                ans += n-j+1;
            }
            while(j < n && curr < k){
                mp[nums[j]]++;
                if(mp[nums[j]]  >= 2) curr += mp[nums[j]]-1;
                j++;
            }
            if(j == n && curr < k) break;
        }
        return ans;
    }
};
