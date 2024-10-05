#include<algorithm>
#include<string>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
        {
            return false;
        }
        vector<int> s1Count(26,0),s2Count(26,0);
        for(int i=0;i<s1.length();++i){
            s1Count[s1[i]-'a']++;
            s2Count[s2[i]-'a']++;
        }
        for(int i=0;i<s2.length()-s1.length();++i){
            if(s1Count==s2Count){
                return true;
            }
            s2Count[s2[i]-'a']--;
            s2Count[s2[i+s1.length()]-'a']++;
        }
        return s1Count==s2Count;
        // vector<string> permutation;
        // int len=s1.size();
        // if(len<s2.size()){
        //     do{
        //         permutation.push_back(s1);
        //     }
        //     while(next_permutation(s1.begin(),s1.end()));
        //     for(int i=0;i<s2.size()-len;i++){
        //         string sub=s2.substr(i,len);
        //         if(find(permutation.begin(),permutation.end(),sub)!=permutation.end()){
        //             return true;
        //         }
        //     }
        // }
        // return false;
    }
};
