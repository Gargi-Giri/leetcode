class Solution {
public:
    string reverseVowels(string s) {
       //set<char> vowels={'a','e','i','o','u','A','E','I','O','U'};
        bool isVowel[256]={false};
       string vowels="aeiouAEIOU";
         for(char c:vowels){
            isVowel[(unsigned char)c]=true;
        }
        int left=0;
        int right=s.size()-1;
        while(left<right){
            while(left<right&&!isVowel[(unsigned char)s[left]]){
                left++;
                continue;
            }
            while(left<right&&!isVowel[(unsigned char)s[right]]){
                right--;
                continue;
            }      
            if(left<right){
                char temp=s[left];
                s[left]=s[right];
                s[right]=temp;
                left++;
                right--;
            }
        }
        return s;           
    }
};
/*
swap(char a,char b){
    char temp=a;
    a=b;
    b=temp;
}*/
