#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> freq;

        // Count frequency of each digit in the string
        for (char c : s) {
            freq[c]++;
        }

        // Traverse the string to find the first valid adjacent pair
        for (int i = 0; i < s.length() - 1; i++) {
            char first = s[i], second = s[i + 1];

            if (first != second && freq[first] == (first - '0') && freq[second] == (second - '0')) {
                return string() + first + second;
            }
        }

        return "";
    }
};

