class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        string str;
        str.push_back(s[0]);
        for(int i=1;i<n;i++){
            int prev=i-1;
            int next=i+1;

            if(s[i]==s[prev]&&s[i]==s[next]&&s.size()>=2){
                
                //s.erase(remove(s.begin(),s.end(),s[i]),s.end());
            }
            else{
                str.push_back(s[i]);
            }
        }
        return str;
    }
};
