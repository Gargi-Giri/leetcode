#include<cmath>
class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0,count1=0;

        for(int i=0;i<s.size();i++){
            // char ch=s[i];
            if(s[i]=='('){
                count++;
            }
            else if(s[i]==')'&&count>0){
                count--;
            }  
            else if(count==0&&s[i]==')'){
                count1++;
            }
            else{
                count++;
            }         
        }
        return count+count1;
    }
};
