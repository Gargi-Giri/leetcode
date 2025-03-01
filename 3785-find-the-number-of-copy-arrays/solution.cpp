#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        const int MOD = 1e9 + 7;

        // Valid range for copy[0]
        int low = bounds[0][0], high = bounds[0][1];

        for (int i = 1; i < n; ++i) {
            int diff = original[i] - original[i - 1];

            // New range must satisfy: newLow ≤ copy[i] ≤ newHigh
            int newLow = max(bounds[i][0], low + diff);
            int newHigh = min(bounds[i][1], high + diff);

            if (newLow > newHigh) return 0; // No valid values exist

            low = newLow;
            high = newHigh;
        }

        // Final number of valid arrays is the count of values in [low, high]
        return (high - low + 1) % MOD;
    }
};

