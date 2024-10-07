class Solution {
public:
string removeStars(string s) {
        string result="";
        for(char c:s){
            if(c=='*'){
                if(!result.empty()){
                    result.pop_back();
                }
            }
            else{
                result.push_back(c);
            }
        }
        return result;
    }
    // string removeStars(string s) {
    //     stack<char>st;
    //     for(char c:s){
    //         if(c=='*'){
    //             if(!st.empty()){
    //                 st.pop();
    //             }
    //         }
    //         else{
    //             st.push(c);
    //         }
    //     }
    //     string result="";
    //     while(!st.empty()){
    //         result=st.top()+result;
    //         st.pop();
    //     }
    //     return result;
    // }
};
