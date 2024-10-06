class Solution {
    public:
    // Helper function to split a sentence into words
    vector<string> splitSentence(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
    
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = splitSentence(sentence1);
        vector<string> words2 = splitSentence(sentence2);
        
        int n1 = words1.size();
        int n2 = words2.size();
        
        int prefixMatch = 0, suffixMatch = 0;
        
        // Match words from the start (prefix match)
        while (prefixMatch < n1 && prefixMatch < n2 && words1[prefixMatch] == words2[prefixMatch]) {
            prefixMatch++;
        }
        
        // Match words from the end (suffix match)
        while (suffixMatch < n1 - prefixMatch && suffixMatch < n2 - prefixMatch && 
               words1[n1 - suffixMatch - 1] == words2[n2 - suffixMatch - 1]) {
            suffixMatch++;
        }
        
        // The total matched words (prefix + suffix) should cover the entire shorter sentence
        return (prefixMatch + suffixMatch) >= std::min(n1, n2);
    }
    // string prefix(string s){
    //     int n=s.size();
    //     string prefix="";
    //     for(int i=0;i<n;i++)
    //     {
    //         if(s[i]==' '){
    //             break;
    //         }
    //         prefix+=s[i];
    //     }
    //     return prefix;
    // }
    // string suffix(string s){
    //     int n=s.size();
    //     string suffix="";
    //     for(int i=n-1;i>=0;i--){
    //         if(s[i]==' '){
    //             break;
    //         }
    //         suffix+=s[i];
    //     }
    //     return suffix;
    // }
    // bool areSentencesSimilar(string sentence1, string sentence2) {
    //     return ((prefix(sentence1)==prefix(sentence2))||(suffix(sentence1)==suffix(sentence2))) ;//return true;
    //     //return false;
    // }
};
