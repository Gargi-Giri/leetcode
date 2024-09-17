class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // To store the frequency of each word
        unordered_map<string, int> wordCount;
        
        // Helper function to split the sentence and count the words
        auto countWords = [&](const string& sentence) {
            stringstream ss(sentence);
            string word;
            while (ss >> word) {
                wordCount[word]++;
            }
        };

        // Count words in both sentences
        countWords(s1);
        countWords(s2);

        // To store the result
        vector<string> result;
        
        // Find words that appear exactly once across both sentences
        for (const auto& entry : wordCount) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};
