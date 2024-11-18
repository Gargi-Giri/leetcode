class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);  // Initialize the result vector with zeros
        
        if (k == 0) {
            return res; // If k is 0, all elements in the result should be 0
        }
        
        // Compute the result for k > 0 or k < 0
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            if (k > 0) {
                // Add the next k elements (wrap around using modulo)
                for (int j = 1; j <= k; ++j) {
                    sum += code[(i + j) % n];
                }
            } else if (k < 0) {
                // Add the previous |k| elements (wrap around using modulo)
                for (int j = 1; j <= -k; ++j) {
                    sum += code[(i - j + n) % n];
                }
            }
            res[i] = sum;
        }
        
        return res;
    }
};

