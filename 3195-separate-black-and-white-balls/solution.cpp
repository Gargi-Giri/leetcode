class Solution {
public:
    long long minimumSteps(string s) {
        long long swap = 0;
        int black = 0; 
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') 
                swap += (long long) black; 
            else
                black++; 
        }
        return swap;
    }
};

// class Solution {
// public:
//     long long minimumSteps(string s) {
//         int n=s.length();
//         int count=0;
//         int temp=0;
//         bool swapped=true;
//         while(swapped){
//             swapped=false;
//             for(int i=0;i<n-1;i++){
//                 if(s[i]=='1'&&s[i+1]=='0'){
//                     swap(s[i],s[i+1]);
//                 // temp=s[i+1];
//                 // s[i]=temp;
//                 // s[i+1]=s[i];
//                     count++;
//                     swapped=true;
//                 }
//             }
//         }
//         return count;
//     }
// };
