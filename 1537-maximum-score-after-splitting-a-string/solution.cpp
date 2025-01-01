class Solution {
public:
    int maxScore(string s) {
        int total_zeros=0;
        for(char c : s){
            if(c == '0'){
                total_zeros++;
            }
        }
        int ans = -1;
        int zeros = 0;
        int L=s.length();
        for(int i=1 ; i < L ; i++){
            if(s.at(i-1) == '0'){
                zeros++;
                total_zeros--;
            }
            ans = max(ans, (zeros + (L - total_zeros - (i))));
        }
        return ans;
    }
};
