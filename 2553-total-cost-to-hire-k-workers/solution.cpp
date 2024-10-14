class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long hiringCost = 0;

        // Two min-heaps to handle candidates from the front and back
        priority_queue<int, vector<int>, greater<int>> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap;

        int left = 0, right = n - 1;
        
        // Fill heaps with candidates from both sides
        for (int i = 0; i < candidates && left <= right; i++) {
            leftHeap.push(costs[left++]);
            if (left <= right) {
                rightHeap.push(costs[right--]);
            }
        }

        // Hire k workers
        for (int i = 0; i < k; i++) {
            // If left heap has the smaller cost or right heap is empty
            if (!leftHeap.empty() && (rightHeap.empty() || leftHeap.top() <= rightHeap.top())) {
                hiringCost += leftHeap.top();
                leftHeap.pop();
                
                // Add next available element from the left
                if (left <= right) {
                    leftHeap.push(costs[left++]);
                }
            }
            // If right heap has the smaller cost
            else {
                hiringCost += rightHeap.top();
                rightHeap.pop();
                
                // Add next available element from the right
                if (left <= right) {
                    rightHeap.push(costs[right--]);
                }
            }
        }
        
        return hiringCost;
    }
};
// class Solution {
// public:
//     long long totalCost(vector<int>& costs, int k, int candidates) {
//         priority_queue<int, vector<int>, greater<int>> minHeap(costs.begin(),costs.end());
//         long long hiringCost=0;
//         for(int i=0;i<k;i++){
//             int minNum=minHeap.top();
//             minHeap.pop();
//             hiringCost+=minNum;
//         }
//         return hiringCost;
//     }
// };
