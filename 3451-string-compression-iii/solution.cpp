class Solution {
public:
    string compressedString(string word) {
        string comp;
        int n = word.length();
        int i = 0;

        while (i < n) {
            char currentChar = word[i];
            int count = 0;

            // Count how many times currentChar repeats (up to 9)
            while (i < n && word[i] == currentChar && count < 9) {
                count++;
                i++;
            }

            // Append count and character to the compressed string
            comp += to_string(count) + currentChar;
        }

        return comp;
    }
};

