#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();

        // If k == 0, rearranging is free, so sort and compute the optimal transformation cost
        if (k == 0) {
            sort(arr.begin(), arr.end());
            sort(brr.begin(), brr.end());
            long long cost = 0;
            for (int i = 0; i < n; i++) {
                cost += abs(arr[i] - brr[i]);
            }
            return cost;
        }

        // If k > 0, compute both direct transformation and splitting costs
        long long directCost = 0;
        for (int i = 0; i < n; i++) {
            directCost += abs(arr[i] - brr[i]);
        }

        // Sorting for rearrangement after splitting
        vector<int> sortedArr = arr;
        vector<int> sortedBrr = brr;
        sort(sortedArr.begin(), sortedArr.end());
        sort(sortedBrr.begin(), sortedBrr.end());

        long long rearrangedCost = 0;
        for (int i = 0; i < n; i++) {
            rearrangedCost += abs(sortedArr[i] - sortedBrr[i]);
        }

        long long splittingCost = rearrangedCost + k;

        // Return the minimum cost
        return min(directCost, splittingCost);
    }
};


// #include <vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// class Solution {
// public:
//     long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
//         int n = arr.size();
//         long long transformationCost = 0;

//         // Calculate direct transformation cost without splitting
//         for (int i = 0; i < n; i++) {
//             transformationCost += abs(arr[i] - brr[i]);
//         }

//         // If k == 0, no splitting is allowed
//         if (k == 0) {
//             return transformationCost;
//         }

//         // Check if rearranging subarrays is beneficial
//         vector<int> sortedArr = arr;
//         vector<int> sortedBrr = brr;
//         sort(sortedArr.begin(), sortedArr.end());
//         sort(sortedBrr.begin(), sortedBrr.end());

//         long long rearrangedCost = 0;
//         for (int i = 0; i < n; i++) {
//             rearrangedCost += abs(sortedArr[i] - sortedBrr[i]);
//         }

//         // Total cost if we use splitting
//         long long splittingCost = rearrangedCost + k;

//         // Return the minimum cost
//         return min(transformationCost, splittingCost);
//     }
// };

        // long long total_cost = 0;
        // long long x=0;
        // int n = arr.size();
        
        // // Calculate the direct modification cost
        // for (int i = 0; i < n; i++) {
        //     total_cost += abs(arr[i] - brr[i]);
        // }

        // // If k is 0, we cannot rearrange, so return direct modification cost
        // if (k == 0) return total_cost;
        
        
        // return total_cost;
