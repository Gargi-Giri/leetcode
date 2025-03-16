class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool hasPositive = false;
        int maxNegative = INT_MIN;
        unordered_set<int> uniqueNumbers;
        int maxSum = 0;

        for (int num : nums) {
            if (num > 0) {
                hasPositive = true;
                uniqueNumbers.insert(num); // Only store unique positives
            }
            maxNegative = max(maxNegative, num);
        }

        // If no positive numbers exist, return the max negative number
        if (!hasPositive) return maxNegative;

        // Sum up all unique positive numbers
        for (int num : uniqueNumbers) {
            maxSum += num;
        }

        return maxSum;
    }
};

