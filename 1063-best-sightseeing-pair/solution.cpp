class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxSoFar = values[0]; // Keep track of the best `values[i] + i` seen so far
        int maxScore = 0;
        int n = values.size();

        for (int j = 1; j < n; ++j) {
            // Calculate the score for the current pair (i, j) where `i` is implicit
            maxScore = max(maxScore, maxSoFar + values[j] - j);
            // Update `maxSoFar` for the next iteration
            maxSoFar = max(maxSoFar, values[j] + j);
        }

        return maxScore;
    }
};

