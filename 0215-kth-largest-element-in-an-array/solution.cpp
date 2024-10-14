class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(),nums.end());
        int maxNum=0;
        for(int i=0;i<k;i++){
            maxNum=maxHeap.top();
            maxHeap.pop();
        }
        return maxNum;
    }
};
