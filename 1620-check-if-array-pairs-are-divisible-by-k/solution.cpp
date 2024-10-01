class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;

        // Count frequencies of remainders
        for (int num : arr) {
            int remainder = ((num % k) + k) % k; // Ensure remainder is positive
            remainderCount[remainder]++;
        }

        // Check for pairs of remainders
        for (int i = 1; i < k; ++i) {
            if (remainderCount[i] != remainderCount[k - i]) {
                return false; // Mismatched pairs
            }
        }

        // Check for pairs of zeros
        return remainderCount[0] % 2 == 0;
    }
};
