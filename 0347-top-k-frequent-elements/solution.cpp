class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> m;
        for(int i=0; i<n ;i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),[](auto &x, auto &y){
            return x.second>y.second;
        });
        vector<int> v2;
        for(int i=0;i<k;i++){
            v2.push_back(v[i].first);
        }
        return v2;
    }
};
