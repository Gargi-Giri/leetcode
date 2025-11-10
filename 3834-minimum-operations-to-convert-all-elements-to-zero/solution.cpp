class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> stack(nums.size()+1,0);
        int top=0,ans=0;
        for(int num : nums){
            while(stack[top] > num){
                top--;
                ans++;
            }
            if(stack[top]!=num){
                stack[++top] = num;
            }
        }
        return ans+top;
    }
};
// class Solution {
// public:
//     int recur(vector<int>&nums){
//         int a = nums[0];
//         vector<int> nums1;

//         for(int i=0;i<nums.size();i++){
//             if(nums[i]<a&&a!=0){
//                 a=nums[i];
//             }
//             nums1.push_back(nums[i]);
//         }
//           return nums1;
//     }
//     int recur1(vector<int> nums1){
//         vector<int>
//         for(int i=0;i<nums1.size();i++){
//             if(nums1[i]==a){
//                 nums1[i]=0;
//             }
//         }     
//     }
//     int minOperations(vector<int>& nums) {
//         int count1 = recur(nums);
//         int out=0;
//         if(count1<nums.size()){
//            out = recur(nums);
//         }
        
//         return out;
//     }
// };

