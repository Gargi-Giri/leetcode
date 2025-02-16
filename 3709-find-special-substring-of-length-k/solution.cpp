class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        
        for (int i = 0; i <= n - k; i++) {
            if (count(s.begin() + i, s.begin() + i + k, s[i]) == k) { // Check if all characters are same
                if ((i == 0 || s[i - 1] != s[i]) && (i + k == n || s[i + k] != s[i])) { // Check boundaries
                    return true;
                }
            }
        }
        
        return false;
    }
};

