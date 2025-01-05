#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    long long calculateScore(const string& s) {
    unordered_map<char, vector<int>> unmarkedIndices;
    long long score = 0; // Use long long to handle large scores

    // Iterate through the string
    for (int i = 0; i < s.length(); ++i) {
        char current = s[i];
        char mirrored = 'z' - (current - 'a'); // Calculate mirror character

        if (!unmarkedIndices[mirrored].empty()) {
            // Find the closest unmarked index
            int j = unmarkedIndices[mirrored].back();
            unmarkedIndices[mirrored].pop_back(); // Remove the matched index
            score += static_cast<long long>(i) - j; // Ensure no overflow
        } else {
            // Add the current index to the unmarked indices for the character
            unmarkedIndices[current].push_back(i);
        }
    }

    return score;
}

};

