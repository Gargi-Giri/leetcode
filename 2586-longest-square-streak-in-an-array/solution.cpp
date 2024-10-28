class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        // Remove duplicates and sort the input
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        std::vector<int> uniqueNums(numSet.begin(), numSet.end());
        std::sort(uniqueNums.begin(), uniqueNums.end());

        int maxStreakLength = -1;

        for (int num : uniqueNums) {
            int currentLength = 1; // Start a new streak
            long long currentNum = num; // Use long long to avoid overflow

            while (true) {
                long long nextNum = currentNum * currentNum;

                // Check for overflow and if the next square exists in the set
                if (nextNum > std::numeric_limits<int>::max() || !numSet.count(nextNum)) {
                    break; // Exit the loop if overflow or square not found
                }

                currentNum = nextNum; // Move to the next square
                currentLength++; // Increase the streak length
            }

            if (currentLength >= 2) {
                maxStreakLength = std::max(maxStreakLength, currentLength);
            }
        }

        return maxStreakLength >= 2 ? maxStreakLength : -1;
    }
};

