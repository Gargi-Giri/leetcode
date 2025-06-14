class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        char maxDigToRep=' ';
        for(char c : s){
            if(c!='9'){
                maxDigToRep=c;
                break;
            }
        }
        string maxStr=s;
        if(maxDigToRep!=' '){
            for(char & c: maxStr){
                if(c==maxDigToRep)  c='9';
            }
        }
        char minDigToRep=s[0];
        string minStr=s;
        for(char & c: minStr){
            if(c==minDigToRep)  c='0';
        }
        return stoi(maxStr)-stoi(minStr);
    }
};
//num=11891
//maxnum=99899
//minnum=00890
//maxnum-minnum=99009
