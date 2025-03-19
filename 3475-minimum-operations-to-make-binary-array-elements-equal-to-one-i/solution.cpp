#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        // If array is too small, check if transformation is possible
        if (nums.size() < 3) {
            return (std::find(nums.begin(), nums.end(), 0) != nums.end()) ? -1 : 0;
        }

        int count = 0;
        for (int i = 0; i <= nums.size() - 3; i++) {
            if (nums[i] == 0) {
                // Flip current element and next two
                nums[i] = 1;
                nums[i + 1] ^= 1; // Toggle 0 ↔ 1
                nums[i + 2] ^= 1;
                count++;
            }
        }

        // Check if the last two elements are both 1s
        return (nums[nums.size() - 2] == 1 && nums[nums.size() - 1] == 1) ? count : -1;
    }
};
