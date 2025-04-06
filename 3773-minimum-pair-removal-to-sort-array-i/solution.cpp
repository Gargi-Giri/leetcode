class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int op = 0;
        while (true) {
            bool sorted = true;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] < nums[i - 1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) return op;
            int minSum = INT_MAX, idx = -1;
            for (int i = 1; i < nums.size(); ++i) {
                int sum = nums[i - 1] + nums[i];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i - 1;
                }
            }
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            ++op;
        }
    }
};

