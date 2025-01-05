class Solution {
public:
    // Function to calculate LCM of two numbers
    int lcm(int a, int b) {
        return abs(a * b) / gcd(a, b);
    }

    // Function to find the longest product-equivalent subarray
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        
        // Set a large threshold to stop the product from becoming too large
        const long long MAX_PRODUCT = 1e18;  // Threshold beyond which we stop

        // Iterate over all possible starting points of subarrays
        for (int i = 0; i < n; ++i) {
            long long prod = 1;  // Use long long for product to avoid overflow
            int g = nums[i], l = nums[i];
            
            // For each subarray starting from i
            for (int j = i; j < n; ++j) {
                // Check if multiplying the product with the current number would overflow
                if (prod > MAX_PRODUCT / nums[j]) {
                    break;  // Stop further computation if the product is too large
                }
                
                prod *= nums[j];               // Product of the subarray
                g = gcd(g, nums[j]);           // GCD of the subarray
                l = lcm(l, nums[j]);           // LCM of the subarray
                
                // Check if prod(arr) == gcd(arr) * lcm(arr)
                if (prod == g * l) {
                    maxLen = max(maxLen, j - i + 1);  // Update the maximum length
                }
            }
        }
        
        return maxLen;
    }
};

