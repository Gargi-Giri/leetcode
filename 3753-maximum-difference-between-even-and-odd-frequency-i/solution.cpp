#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        
        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        int maxOdd = INT_MIN, minEven = INT_MAX;
        bool hasEven = false, hasOdd = false;

        // Find max odd frequency and min even frequency
        for (auto &[ch, count] : freq) {
            if (count % 2 == 1) { // Odd frequency
                maxOdd = max(maxOdd, count);
                hasOdd = true;
            } else { // Even frequency
                minEven = min(minEven, count);
                hasEven = true;
            }
        }

        return (hasOdd && hasEven) ? maxOdd - minEven : 0;
    }
};

