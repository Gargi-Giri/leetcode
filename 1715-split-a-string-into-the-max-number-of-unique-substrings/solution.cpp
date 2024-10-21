class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;  // To store unique substrings
        return backtrack(s, 0, seen);
    }

private:
    int backtrack(const string &s, int start, unordered_set<string> &seen) {
        if (start == s.size()) {
            return 0;
        }

        int max_count = 0;
        string current_substr = "";

        for (int end = start; end < s.size(); ++end) {
            current_substr += s[end];

            // If the substring is not already in the 'seen' set
            if (seen.find(current_substr) == seen.end()) {
                seen.insert(current_substr);  // Add the substring to the seen set
                int count = 1 + backtrack(s, end + 1, seen);  // Recur and increment count
                max_count = max(max_count, count);  // Track the maximum number of unique splits
                seen.erase(current_substr);  // Backtrack by removing the substring from the seen set
            }
        }

        return max_count;
    }
};

