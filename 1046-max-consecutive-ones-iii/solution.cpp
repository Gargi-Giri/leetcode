class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, count = 0, ans = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                count++;  // Count the number of zeros in the window
            }
            
            // If the number of zeros exceeds k, shrink the window from the left
            while (count > k) {
                if (nums[left] == 0) {
                    count--;  // Decrease the count of zeros when moving the left pointer
                }
                left++;  // Shrink the window
            }
            
            // Update the maximum length of the window
            ans = max(ans, i - left + 1);
        }
        
        return ans;
    }
};

