class Solution {
public:
    bool isPalindrome(const string &str) {
        int l = 0, r = str.size() - 1;
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++, r--;
        }
        return true;
    }

    int longestPalindrome(string s, string t) {
        int maxLen = 1; // A single character is always a palindrome
        int n = s.size(), m = t.size();

        // Try all substrings of s alone
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                string sub_s = s.substr(i, j - i + 1);
                if (isPalindrome(sub_s)) {
                    maxLen = max(maxLen, (int)sub_s.size());
                }
            }
        }

        // Try all substrings of t alone
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                string sub_t = t.substr(i, j - i + 1);
                if (isPalindrome(sub_t)) {
                    maxLen = max(maxLen, (int)sub_t.size());
                }
            }
        }

        // Try all combinations of substrings from s and t
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                string sub_s = s.substr(i, j - i + 1);

                for (int k = 0; k < m; ++k) {
                    for (int l = k; l < m; ++l) {
                        string sub_t = t.substr(k, l - k + 1);
                        string combined = sub_s + sub_t;
                        if (isPalindrome(combined)) {
                            maxLen = max(maxLen, (int)combined.size());
                        }
                    }
                }
            }
        }

        return maxLen;
    }
};

