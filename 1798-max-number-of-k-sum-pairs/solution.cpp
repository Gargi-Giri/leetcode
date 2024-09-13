class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
    
    int left = 0, right = nums.size() - 1;
    int count = 0; // To store the number of valid pairs
    
    // Use two-pointer technique
    while (left < right) {
        int sum = nums[left] + nums[right];
        
        if (sum == k) {
            count++;
            left++;
            right--;
        } else if (sum < k) {
            left++; // Increase the left pointer to increase the sum
        } else {
            right--; // Decrease the right pointer to decrease the sum
        }
    }
    
    return count;
    }
};
