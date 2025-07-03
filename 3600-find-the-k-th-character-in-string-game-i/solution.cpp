class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.size()<k){
            string nextpart;
            for(char c : word){
                char nextchar = (c-'a'+1)%26+'a';
                nextpart+=nextchar;
            }
            word+=nextpart;
        }
        return word[k-1];
    }
};
