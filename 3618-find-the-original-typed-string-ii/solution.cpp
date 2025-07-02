class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int MOD=1e9+7;
        vector<int> groupExtras;
        int64_t totalWays=1;
        int n=word.size();
        for(int i=0;i<n;){
            int j=i;
            while(j<n&&word[j]==word[i]) j++;
            int len=j-i;
            i=j;
            if(len>1){
                groupExtras.push_back(len-1);
                totalWays=(totalWays*len)%MOD;
            }
            k--;
        }
        if(k<=0) return totalWays;
        vector<int64_t> dp(k,0);
        dp[0]=1;
        for(int extra: groupExtras){
            for(int i=1;i<k;++i){
                dp[i]=(dp[i]+dp[i-1])%MOD;
            }
            for(int i=k-1;i>extra;--i){
                dp[i]=(dp[i]-dp[i-extra-1]+MOD)%MOD;
            }
        }
        for(int i=1;i<k;++i){
            dp[i]=(dp[i]+dp[i-1])%MOD;
        }
        return (totalWays-dp[k-1]+MOD)%MOD;
    }
};
