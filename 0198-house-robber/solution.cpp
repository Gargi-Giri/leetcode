class Solution {
public:
int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[n - 1];        
    }
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     int TotMoney=0;
    //     int TotOddMoney=0;
    //     int money=0;
    //     if(n==0){
    //         return 0;
    //     }
    //     if(n%2!=0){
    //     for(int i=0;i<n;i++){
    //         TotMoney+=nums[i];
    //         i=i+1;
    //         TotOddMoney+=nums[i];
    //     }
    //     money=max(TotMoney,TotOddMoney);
    //     }
    //     else{

    //     }
    //     return money;
    // }
};
