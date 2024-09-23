class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        unordered_set<string> dict(dictionary.begin(),dictionary.end());
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+1;
            for(int j=0;j<i;++j){
                string substring=s.substr(j,i-j);
                if(dict.find(substring)!=dict.end()){
                    dp[i]=min(dp[i],dp[j]);
                }
            }
        }
        return dp[n];

    //     int n=s.size();
    //     unordered_set<string> dict(dictionary.begin(), dictionary.end());
    //     int count=0;
    //     if(n==0){
    //         return count;
    //     }
    //     else if(dictionary.size()==0||n!=0){
    //         return n;
    //     }
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=i;j++){
    //             string check=s.substr(j,i-j);
    //             if(dict.find(check) != dict.end()){
    //                 count++;
    //             }
    //         }
    //     }
    //    return count;
    }
};
