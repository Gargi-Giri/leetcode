#include <vector>
#include <bitset>
#include <cstdlib>
using namespace std;

const int MAX_LIMIT = 5000; 

struct Cell {
    bitset<MAX_LIMIT + 1> poss;
    bool rescued;
    bool overflow;
};

class Solution {
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        vector<int> inp = nums;
        int n = inp.size();
        
        int maxAlt = 12 * ((n + 1) / 2);
        if(abs(k) > maxAlt) return -1; 
        
        int OFFSET = maxAlt;
        int SIZE = 2 * maxAlt + 1;  
        
        vector<vector<Cell>> dp(2, vector<Cell>(SIZE, {bitset<MAX_LIMIT+1>(), false, false}));
              
        for (int x : inp) {
            
            vector<vector<Cell>> newdp(2, vector<Cell>(SIZE, {bitset<MAX_LIMIT+1>(), false, false}));
                       
            for (int par = 0; par < 2; ++par) {
                for (int d = 0; d < SIZE; ++d) {
                    newdp[par][d].poss |= dp[par][d].poss;
                    newdp[par][d].rescued = newdp[par][d].rescued || dp[par][d].rescued;
                    newdp[par][d].overflow = newdp[par][d].overflow || dp[par][d].overflow;
                }
            }
                       
            {
                int d;
                if (x == 0) {
                    
                    d = 0;
                    newdp[1][d + OFFSET].rescued = true;
                } else {
                    if (x <= limit) { 
                        d = x; 
                        newdp[1][d + OFFSET].poss.set(x, true);
                    }
                }
            }
                      
            for (int par = 0; par < 2; ++par) {
                for (int d = 0; d < SIZE; ++d) {
                    
                    if (dp[par][d].poss.none() && !dp[par][d].rescued && !dp[par][d].overflow)
                        continue;
                    int curAlt = d - OFFSET;
                    
                    int newAlt = (par == 0 ? curAlt + x : curAlt - x);
                    if(newAlt < -OFFSET || newAlt > OFFSET)
                        continue;
                    int newPar = 1 - par;
                    int newIdx = newAlt + OFFSET;
                                       
                    if(x == 0) {
                        newdp[newPar][newIdx].rescued = true;
                    } else {
                        
                        for (int p = 1; p <= limit; ++p) {
                            if(dp[par][d].poss.test(p)) {
                                long long np = 1LL * p * x;
                                if(np <= limit)
                                    newdp[newPar][newIdx].poss.set((int)np, true);
                                else
                                    newdp[newPar][newIdx].overflow = true;
                            }
                        }
                        
                        if(dp[par][d].rescued)
                            newdp[newPar][newIdx].rescued = true;
                        
                        if(dp[par][d].overflow)
                            newdp[newPar][newIdx].overflow = true;
                    }
                }
            }
            
            dp = move(newdp);
        }
        
        int target = k + OFFSET;
        int ans = -1;
        
        for (int par = 0; par < 2; ++par) {
            
            for (int p = 1; p <= limit; ++p) {
                if(dp[par][target].poss.test(p)) {
                    if(p > ans)
                        ans = p;
                }
            }
            if(dp[par][target].rescued && ans < 0)
                ans = 0;
        }
        return ans;
    }
};

