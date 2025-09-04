class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // unordered_map<int,int> m,n;
        // for(auto x: arr)
        // m[x]++;
        // for(auto x : m){
        //     n[x.second]++;
        //     if(n[x.second]>1)
        //     return false;
        // }
        // return true;
        unordered_map<int,int> freq;
        for(auto i : arr){
            freq[i]++;
        }
        unordered_set<int> s;
        for(auto i : freq){
            s.insert(i.second);
        }
        return freq.size()==s.size();
    }
};
