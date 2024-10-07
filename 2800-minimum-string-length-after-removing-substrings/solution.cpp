class Solution {
public:
int minLength(string s) {
        stack<char> st;
        for (char c:s) {
            if(!st.empty()&&((st.top()=='A'&&c=='B')||(st.top()=='C'&&c=='D'))){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        return st.size();
    // int minLength(string s) {
    //     stack<char> st;
    //     for (int i = 0; i < s.size(); i++) {
    //         char c=s[i];
    //         if(!st.empty()&&((st.top()=='A'&&c=='B')||(st.top()=='C'&&c=='D'))){
    //             st.pop();
    //         }
    //         else{
    //             st.push(c);
    //         }
    //     }
    //     return st.size();
    }
};
