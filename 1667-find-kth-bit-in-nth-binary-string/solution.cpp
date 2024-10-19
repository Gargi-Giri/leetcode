class Solution {
private:
    string invert(string x){
        for(int i=0;i<x.size();i++){
            if(x[i]=='0') x[i]='1';
            else if(x[i]=='1') x[i]='0';
        }
        return x;
    }
    string findString(int n){
        if(n==1) return "0";
        vector<string> s(n+1);
        s[1]="0";
        for(int i=2;i<=n;i++){
            string prev=s[i-1];
            string inverted=invert(prev);
            reverse(inverted.begin(),inverted.end());
            s[i]=prev+"1"+inverted;
        }
        return s[n];
    }
public:
    char findKthBit(int n, int k) {
        //string s;
        string s=findString(n);
        return s[k-1];
    }
};
