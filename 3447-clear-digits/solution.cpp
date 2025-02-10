class Solution {
public:
    string clearDigits(string s) {
        string out="";
        for(char c:s){
            if(isdigit(c)){
                if(!out.empty()){
                    out.pop_back();
                }
            }
            else{
                out.push_back(c);
            }
        }
        return out;
        //  string out;
        // for (char c : s) {
        //     if (c >= '0' && c <= '9') {
        //         if (!out.empty()) {
        //             out.pop_back(); // Remove the last character if om is not empty
        //         }
        //     } else {
        //         out.push_back(c); // Append the character if it's not a digit
        //     }
        // }
        // return out;
    }
};
