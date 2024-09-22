class Solution {
public:
    int findKthNumber(int n, int k) {
        int current = 1;  // Start from the smallest number in range
        k--;  // Decrement k since we are starting from 1
        
        while (k > 0) {
            int count = 0;
            long long first = current;  // Current prefix
            long long last = current + 1;  // Next prefix
            
            // Count how many numbers are in the range [first, last) in lexicographical order
            while (first <= n) {
                count += min(last, (long long)n + 1) - first;
                first *= 10;
                last *= 10;
            }
            
            // Decide whether to go deeper or to the next sibling
            if (k < count) {
                current *= 10;  // Go deeper in the tree
                k--;  // One step deeper taken
            } else {
                current++;  // Move to the next sibling
                k -= count;  // Reduce k by the count of numbers traversed
            }
        }
        
        return current;
    }
};

