class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        // Start DFS from numbers 1 through 9
        for (int i = 1; i <= 9; ++i) {
            dfs(i, n, result);
        }
        return result;
    }
    
    // Helper function to perform DFS
    void dfs(int current, int n, vector<int>& result) {
        if (current > n) return;
        
        result.push_back(current);  // Add current number to result
        
        // Explore further by appending digits 0 through 9 to the current number
        for (int i = 0; i <= 9; ++i) {
            int next = current * 10 + i;  // Generate the next number
            if (next > n) break;  // Stop if the number exceeds n
            dfs(next, n, result);  // Recursively call DFS for the next number
        }
    }
};

