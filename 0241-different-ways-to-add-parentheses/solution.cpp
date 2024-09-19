class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        
        vector<int> result;
        
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                // Split the expression into left and right parts
                string leftPart = expression.substr(0, i);
                string rightPart = expression.substr(i + 1);
                
                // Recursively compute the results for both parts
                vector<int> leftResults = diffWaysToCompute(leftPart);
                vector<int> rightResults = diffWaysToCompute(rightPart);
                
                // Combine results based on the current operator
                for (int left : leftResults) {
                    for (int right : rightResults) {
                        if (c == '+') {
                            result.push_back(left + right);
                        } else if (c == '-') {
                            result.push_back(left - right);
                        } else if (c == '*') {
                            result.push_back(left * right);
                        }
                    }
                }
            }
        }
        
        // Base case: if no operators were found, it's a number
        if (result.empty()) {
            result.push_back(stoi(expression));
        }
        
        memo[expression] = result;
        return result;
    }
};

