class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = nums[0];  // Step 1: Find the maximum element
        int maxLength = 0;         // Variable to store the longest length
        int currentLength = 0;     // Variable to store the current subarray length

        // Find the maximum element in the array
        for (int num : nums) {
            if (num > maxElement) {
                maxElement = num;
            }
        }

        // Step 2: Traverse the array to find the longest subarray with maxElement
        for (int num : nums) {
            if (num == maxElement) {
                currentLength++;  // Increment the current subarray length
            } else {
                maxLength = max(maxLength, currentLength);  // Update maxLength
                currentLength = 0;  // Reset the current length for the next subarray
            }
        }

        // Update maxLength in case the longest subarray is at the end
        maxLength = max(maxLength, currentLength);

        return maxLength;
    }
};

