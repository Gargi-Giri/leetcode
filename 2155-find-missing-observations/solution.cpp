class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        
        // Calculate the total sum required for n + m rolls
        int totalSum = (n + m) * mean;
        
        // Calculate the current sum of the m rolls
        int currentSum = accumulate(rolls.begin(), rolls.end(), 0);
        
        // Calculate the missing sum needed for the n rolls
        int missingSum = totalSum - currentSum;
        
        // Check if the missing sum is achievable (n <= missingSum <= 6 * n)
        if (missingSum < n || missingSum > 6 * n) {
            return {};
        }
        
        // Initialize the result vector with the minimum possible values
        vector<int> result(n, 1);
        missingSum -= n; // We already assigned 1 to each roll
        
        // Distribute the remaining missingSum across the n rolls
        for (int i = 0; i < n && missingSum > 0; ++i) {
            int increment = min(5, missingSum); // Each roll can be increased by at most 5 (to reach 6)
            result[i] += increment;
            missingSum -= increment;
        }
        
        return result;
    }
};

