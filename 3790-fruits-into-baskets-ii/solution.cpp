class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> basketUsed(n, false);  
        int unplacedCount = 0;
        
        for (int i = 0; i < n; i++) {
            bool placed = false;
            
           
            for (int j = 0; j < n; j++) {
                if (!basketUsed[j] && baskets[j] >= fruits[i]) {
                   
                    basketUsed[j] = true;
                    placed = true;
                    break;
                }
            }
            
            
            if (!placed) {
                unplacedCount++;
            }
        }
        
        return unplacedCount;
    }
};
