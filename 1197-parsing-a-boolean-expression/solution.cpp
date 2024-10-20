class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c == ')') {
                vector<char> subExpr;
                
                // Collect all values inside the parentheses
                while (!st.empty() && st.top() != '(') {
                    subExpr.push_back(st.top());
                    st.pop();
                }

                st.pop(); // Pop the opening '('
                char operatorChar = st.top(); // Get the operator
                st.pop(); // Pop the operator
                
                char result = subExpr[0]; // Initialize result
                
                if (operatorChar == '&') {
                    // AND operation, start with 't'
                    result = 't';
                    for (char val : subExpr) {
                        if (val == 'f') {
                            result = 'f';
                            break; // If any 'f', the result is 'f'
                        }
                    }
                } else if (operatorChar == '|') {
                    // OR operation, start with 'f'
                    result = 'f';
                    for (char val : subExpr) {
                        if (val == 't') {
                            result = 't';
                            break; // If any 't', the result is 't'
                        }
                    }
                } else if (operatorChar == '!') {
                    // NOT operation, negate the single value
                    result = (subExpr[0] == 't') ? 'f' : 't';
                }
                
                // Push the result of the sub-expression back to the stack
                st.push(result);
            } else if (c != ',') {
                // Ignore commas, push other characters ('t', 'f', '(', '&', '|', '!')
                st.push(c);
            }
        }
        
        // The final result will be the only element left in the stack
        return st.top() == 't';
    }
};

