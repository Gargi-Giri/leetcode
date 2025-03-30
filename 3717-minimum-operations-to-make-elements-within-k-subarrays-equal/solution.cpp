#include <vector>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;
 
// Sliding window median structure using two multisets.
struct SlidingMedian {
    multiset<int> left;  // lower half (max side)
    multiset<int> right; // upper half (min side)
    long long sumLeft = 0, sumRight = 0;
 
    // Rebalance so that left has (total+1)/2 elements.
    void rebalance() {
        while (left.size() > (left.size() + right.size() + 1) / 2) {
            // Move largest element from left to right.
            auto it = prev(left.end());
            int val = *it;
            left.erase(it);
            sumLeft -= val;
            right.insert(val);
            sumRight += val;
        }
        while (left.size() < (left.size() + right.size() + 1) / 2) {
            // Move smallest element from right to left.
            auto it = right.begin();
            int val = *it;
            right.erase(it);
            sumRight -= val;
            left.insert(val);
            sumLeft += val;
        }
    }
 
    // Add a number.
    void add(int num) {
        if (left.empty() || num <= *prev(left.end())) {
            left.insert(num);
            sumLeft += num;
        } else {
            right.insert(num);
            sumRight += num;
        }
        rebalance();
    }
 
    // Remove a number (one occurrence).
    void remove(int num) {
        if (!left.empty() && num <= *prev(left.end())) {
            auto it = left.find(num);
            if(it != left.end()){
                left.erase(it);
                sumLeft -= num;
            }
        } else {
            auto it = right.find(num);
            if(it != right.end()){
                right.erase(it);
                sumRight -= num;
            }
        }
        rebalance();
    }
 
    // Get median: largest element in left.
    int getMedian() {
        return *prev(left.end());
    }
 
    // Compute cost: sum of |a - median| over all a in window.
    long long getCost() {
        int med = getMedian();
        long long costLeft = (long long)med * left.size() - sumLeft;
        long long costRight = sumRight - (long long)med * right.size();
        return costLeft + costRight;
    }
};
 
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        if (k * x > n) return -1;
        int m = n - x + 1; // number of windows
 
        // Precompute cost for every window of length x using SlidingMedian.
        vector<long long> cost(m, 0);
        SlidingMedian sm;
        // Initialize first window.
        for (int i = 0; i < x; i++) {
            sm.add(nums[i]);
        }
        cost[0] = sm.getCost();
        for (int i = 1; i < m; i++) {
            sm.remove(nums[i - 1]);
            sm.add(nums[i + x - 1]);
            cost[i] = sm.getCost();
        }
 
        // DP: dp[i][t] = minimal cost to choose exactly t intervals from windows i...m-1.
        const long long INF = numeric_limits<long long>::max() / 2;
        vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, INF));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 0;
        }
 
        // Fill dp table from i = m-1 downto 0.
        for (int i = m - 1; i >= 0; i--) {
            for (int t = 1; t <= k; t++) {
                long long skip = dp[i + 1][t];
                long long take = INF;
                int next = i + x;
                if (next <= m) {
                    take = cost[i] + dp[next][t - 1];
                } else if (t == 1) {  // if this is the last interval and no next window exists.
                    take = cost[i];
                }
                dp[i][t] = min(skip, take);
            }
        }
 
        long long ans = dp[0][k];
        return (ans >= INF ? -1 : ans);
    }
};

