class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string str;
        vector<string> words;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                str+=s[i];
            }
            else{
                if(!str.empty()){
                    words.push_back(str);
                    str.clear();
                }
            }
            
        }
        if(!str.empty()){
            words.push_back(str);
        }
        reverse(words.begin(),words.end());
        string res;
        for(int i=0;i<words.size();i++){
            res+=words[i];
            if(i!=words.size()-1){
                res+=' ';
            }
        }
        return res;
    }    
};
