class Solution {
public:

int findTheLongestSubstring(string s) {
    unordered_map<int, int> seen;
    seen[0] = -1;  // To handle substrings starting from index 0

    int mask = 0;
    int maxLen = 0;
    
    // Vowel to bit mapping: a -> 0, e -> 1, i -> 2, o -> 3, u -> 4
    for (int i = 0; i < s.length(); ++i) {
        // Update mask based on current character
        if (s[i] == 'a') mask ^= (1 << 0);
        else if (s[i] == 'e') mask ^= (1 << 1);
        else if (s[i] == 'i') mask ^= (1 << 2);
        else if (s[i] == 'o') mask ^= (1 << 3);
        else if (s[i] == 'u') mask ^= (1 << 4);

        // If we've seen this mask before, calculate the length of the substring
        if (seen.find(mask) != seen.end()) {
            maxLen = max(maxLen, i - seen[mask]);
        } else {
            // Otherwise, store the index where we first see this mask
            seen[mask] = i;
        }
    }
    
    return maxLen;

}

};
