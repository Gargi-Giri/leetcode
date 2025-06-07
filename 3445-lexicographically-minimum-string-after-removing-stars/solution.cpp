class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        
        // Marks whether a character should be removed
        vector<bool> isRemoved(n, false);

        // Stores indices of each character from 'a' to 'z'
        vector<vector<int>> charIndices(26);

        // Traverse the string and handle '*' and characters
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                // Remove the most recent smallest lex character
                for (int j = 0; j < 26; j++) {
                    if (!charIndices[j].empty()) {
                        int lastIdx = charIndices[j].back();
                        charIndices[j].pop_back();
                        isRemoved[lastIdx] = true;
                        break; // Only one character to remove per '*'
                    }
                }
            } else {
                // Track index of the current character
                charIndices[s[i] - 'a'].push_back(i);
            }
        }

        // Build the final string excluding removed characters and '*'
        string result;
        for (int i = 0; i < n; i++) {
            if (s[i] != '*' && !isRemoved[i]) {
                result += s[i];
            }
        }

        return result;
    }
};
