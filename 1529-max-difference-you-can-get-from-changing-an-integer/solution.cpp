class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        string a=s,b=s;
        char MaxDigToRep=' ';
        for(char c : s){
            if(c!='9'){
                MaxDigToRep=c;
                break;
            }
        }
        if(MaxDigToRep!=' '){
            for(char& c: a){
                if(c==MaxDigToRep)  c='9';
            }
        }
        char MinDigToRep=' ';
        char replaceWith=' ';
        if(s[0]!='1'){
            MinDigToRep=s[0];
            replaceWith='1';
        }
        else{
            for(int i=1;i<s.size();++i){
                if(s[i]!='0'&&s[i]!='1'){
                    MinDigToRep=s[i];
                    replaceWith='0';
                    break;
                }
            }
        }
        if(MinDigToRep!=' '){
            for(char& c: b){
                if(c==MinDigToRep)
                    c=replaceWith;
            }
        }
        return stoi(a)-stoi(b);
    }
};
//num=555;
//a=999
//b=111
//a-b=888
