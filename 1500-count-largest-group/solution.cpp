class Solution {
public:
    int countLargestGroup(int n) {
        // Map to keep track of count of numbers for each digit sum
        unordered_map<int, int> groupCounts;

        // Helper lambda to compute digit sum
        auto digitSum = [](int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };

        // Count numbers in each group
        for (int i = 1; i <= n; ++i) {
            int sum = digitSum(i);
            groupCounts[sum]++;
        }

        // Find the maximum size
        int maxSize = 0;
        for (const auto& [key, count] : groupCounts) {
            maxSize = max(maxSize, count);
        }

        // Count how many groups have that max size
        int result = 0;
        for (const auto& [key, count] : groupCounts) {
            if (count == maxSize) result++;
        }

        return result;
    }
};

