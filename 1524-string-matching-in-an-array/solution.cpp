class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string> Ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){              
                if (i != j && words[j].find(words[i]) != std::string::npos) {
                    Ans.push_back(words[i]);
                    break; // Avoid duplicate additions.
                }          
            }
        }     
        return Ans;
    }
};
