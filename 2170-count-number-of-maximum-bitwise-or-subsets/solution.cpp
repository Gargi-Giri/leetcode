class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
         int n = nums.size();
    int maxOr = 0;       // To store the maximum OR value
    int count = 0;       // To count subsets that achieve the max OR value
    
    // Calculate the maximum OR of the entire set by ORing all elements together
    for (int num : nums) {
        maxOr |= num;
    }

    // Iterate through all possible subsets using bit manipulation
    int totalSubsets = 1 << n; // 2^n possible subsets
    for (int mask = 0; mask < totalSubsets; ++mask) {
        int currentOr = 0;
        
        // For each subset, calculate the OR of the selected elements
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                currentOr |= nums[i];
            }
        }
        
        // If the OR of this subset is equal to the maximum OR, count it
        if (currentOr == maxOr) {
            ++count;
        }
    }

    return count;
    }
};
