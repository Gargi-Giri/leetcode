class Solution {
// public:
//     int maximumSum(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> sum(n,0);
        // for(int i=0;i<n;i++){
        //     sum[i]=
        // }n=nums
        // int n=nums.size();
        // int currentSum=0;
        // int maxSum=currentSum;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){

        //     }
        // }
        
private:
    int calcIndivSum(int num) {
        int res = 0;
        while (num > 0) {
            res += num % 10;
            num /= 10;
        }

        return res;
    }

public:
    int maximumSum(vector<int>& nums) {
        int maxNum = -1;
        unordered_map<int, int> digitSum;

        for (const int &num : nums) {
            int indivSum = calcIndivSum(num);

            // if it is in the map:
            if (digitSum.find(indivSum) != digitSum.end()) {
                maxNum = max(maxNum, num + digitSum[indivSum]);
                digitSum[indivSum] = max(digitSum[indivSum], num);

            // otherwise, just append the key as indivSum, and value is the number itself
            } else {
                digitSum[indivSum] = num;

            }
        }

        return maxNum;
    }
};
