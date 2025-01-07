class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n; // If the array has 2 or fewer elements, no changes are
                      // needed.

        int k = 2; // Index for placing the next valid element.
        for (int i = 2; i < n; i++) {
            // Only copy the current element if it is different from the element
            // two positions before.
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
