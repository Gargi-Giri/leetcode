class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end()); // Sort potions for binary search
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n);
        
        for(int i = 0; i < n; i++) {
            long long target = (success + spells[i] - 1) / spells[i]; // Minimum potion strength required
            int idx = lower_bound(potions.begin(), potions.end(), target) - potions.begin(); // Binary search
            pairs[i] = m - idx; // Count valid potions
        }
        
        return pairs;
    }
};
/*
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        int count=0;
        vector<int> pairs;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(spells[i]*potions[j]>=success){
                    count++;
                }
                
                
            }
            pairs.push_back(count);
        }
        return pairs;
    }
};*/
