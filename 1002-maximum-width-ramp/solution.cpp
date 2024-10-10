class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> stack;
        int width = 0;
        int n = nums.size();
        
        // Step 1: Build a monotonic decreasing stack
        for (int i = 0; i < n; ++i) {
            if (stack.empty() || nums[i] < nums[stack.back()]) {
                stack.push_back(i);
            }
        }
        
        // Step 2: Traverse from the end and calculate the maximum ramp width
        for (int j = n - 1; j >= 0; --j) {
            while (!stack.empty() && nums[j] >= nums[stack.back()]) {
                width = max(width, j - stack.back());
                stack.pop_back();
            }
        }
        
        return width;
    }
};

