class Solution {
public:
    int possibleStringCount(string word) {
        int count=1;
        int n=word.size();
        int i=0;
        while(i<n){
            int j=i;
            while(j<n && word[j]==word[i]){
                j++;
            }
            int len=j-i;
            if(len>1){
                count+=(len-1);
            }
            i=j;
        }
        return count;
    }
};
