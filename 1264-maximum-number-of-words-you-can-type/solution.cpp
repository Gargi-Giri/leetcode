class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for (char c : brokenLetters) {
            broken.insert(c);
        }

        int count = 0;
        string word;
        stringstream ss(text);  // to split words

        while (ss >> word) {
            bool canType = true;
            for (char c : word) {
                if (broken.count(c)) {  // if any broken letter is found
                    canType = false;
                    break;
                }
            }
            if (canType) count++;
        }
        return count;
    }
};
