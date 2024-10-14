// #include<cmath>
// class Solution {
// public:
//     int checkNum(vector<int>&nums){
//         int n=nums.size();
//         int check=nums[0];
//         for(int i=1;i<n;i++){
//            // int check=nums[0];
//             if(nums[i]>check){
//                 check=nums[i];
//             }
//         }
//         return check;
//     }
//     int ceil(int val) {
//         return ceil(val / 3.0);  // Use std::ceil for precise ceiling
//     }
//     // int ceil(int val){
//     //     float Val=(float)val/3;
//     //     val=val/3;
//     //     if(Val>val){
//     //         val++;
//     //     }
//     //     return val;
//     // }
//     long long maxKelements(vector<int>& nums, int k) {
//         long long score=0;
//         int n=nums.size();
//         for(int i=0;i<k;i++){
//             int maxNum=checkNum(nums);
//             score+=maxNum;
//             int newVal=ceil(maxNum);
//             for(int j=0;j<n;j++){
//                 if(nums[j]==maxNum){
//                     nums[j]=newVal;
//                     break;
//                 }
//             }
//         }
//         return score;
//     }
// };
class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        // Use a max heap (priority queue in C++)
        std::priority_queue<int> maxHeap(nums.begin(), nums.end());

        long long score = 0;  // Use long long for large values
        for (int i = 0; i < k; i++) {
            // Get the largest element from the heap
            int maxNum = maxHeap.top();
            maxHeap.pop();  // Remove it from the heap
            
            // Add the largest number to the score
            score += maxNum;

            // Compute ceil(maxNum / 3)
            int newVal = std::ceil(maxNum / 3.0);

            // Push the new value back into the heap
            maxHeap.push(newVal);
        }
        return score;
    }
};
