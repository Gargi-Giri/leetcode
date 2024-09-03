class Solution {
public:
    int getLucky(string s, int k) {
        string result="";
        int out=0;;
        for(int i=0;i<s.length();++i){
            char c=s[i];
            if(c>='a'&&c<='z'){
                int val=c-'a'+1;
                result+=to_string(val);
            }
        }
        for (int i = 0; i < result.length(); ++i) {
            out += result[i] - '0';  
        }
        for (int d = 1; d < k; d++) {  
            int temp = 0;
            while (out > 0) {
                temp += out % 10;
                out /= 10;
            }
            out = temp;
        }
        return out;
    }
};
