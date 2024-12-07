class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int n = strength.size();
        int minTime = INT_MAX;
        function<void(int, int, int, vector<bool>&)> backtrack = [&](int currentX, int elapsedTime, int locksBroken, vector<bool>& visited) {
            if (locksBroken == n) {
                minTime = min(minTime, elapsedTime);
                return;
            }
            if (elapsedTime >= minTime) return;
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    visited[i] = true;
                    int requiredTime = (strength[i] + currentX - 1) / currentX;
                    backtrack(currentX + K, elapsedTime + requiredTime, locksBroken + 1, visited);

                    visited[i] = false;
                }
            }
        };
        vector<bool> visited(n, false);
        backtrack(1, 0, 0, visited);

        return minTime;
    }
};

