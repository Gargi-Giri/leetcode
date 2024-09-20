class Solution {
public:
    // Function to calculate the KMP prefix function
    vector<int> computePrefix(string s) {
        int n = s.size();
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = prefix[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = prefix[j - 1];
            }
            if (s[i] == s[j]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }

    // Function to find the shortest palindrome by adding characters to the front
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        // Combine original string with its reverse, separated by a delimiter
        string combined = s + "#" + rev_s;
        
        // Compute prefix array for the combined string
        vector<int> prefix = computePrefix(combined);
        
        // Length of the longest palindromic prefix
        int pal_len = prefix.back();
        
        // Characters to be added to the front
        string to_add = s.substr(pal_len);
        reverse(to_add.begin(), to_add.end());
        
        // Add the required characters in front of the original string
        return to_add + s;
    }
};

