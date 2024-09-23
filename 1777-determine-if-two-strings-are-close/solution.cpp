class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
        }
        unordered_map<char , int> freq1,freq2;
        for(char c:word1){
            freq1[c]++;
        }
        for(char c:word2){
            freq2[c]++;
        }
        if(freq1.size()!=freq2.size()){
            return false;
        }
        vector<int>counts1,counts2;
        for (const auto& pair : freq1) {
            if (freq2.find(pair.first) == freq2.end()) {
                return false; // Character in word1 not in word2
            }
        }

        for(const auto& pair:freq1){
            counts1.push_back(pair.second);
        }
        for(const auto& pair:freq2){
            counts2.push_back(pair.second);
        }
        sort(counts1.begin(),counts1.end());
        sort(counts2.begin(),counts2.end());
        return counts1==counts2;
    }
};
