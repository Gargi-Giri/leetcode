class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count=0;
        long long value=0;
        long long power=1;
        for(int i=s.length()-1; i>=0; --i){
            if(s[i]=='0'){
                count++;
            }
            else{
                if(value+power<=k){
                    value+=power;
                    count++;
                }
            }
            //1
            //1*2
            //2*2=4
            //4*2=8
            if(power<=k){
                power*=2;
            }
        }
        return count;
    }
};
