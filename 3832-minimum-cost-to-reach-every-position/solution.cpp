class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        vector<int> answer(n);
        
        // Initialize the cost for the first person
        answer[0] = cost[0];
        
        for (int i = 1; i < n; ++i) {
            answer[i] = min(answer[i - 1], cost[i]); // Update with minimum swap cost
        }
        
        return answer;
    }
};

