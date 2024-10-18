class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid + 1 <= nums.size() - 1 && nums[mid + 1] > nums[mid]) {
                start = mid + 1;
            } else if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) {
                end = mid - 1;
            } else {
                return mid;
            }
        }

        return start; 
    //     int n=nums.size();
    //     int ind=0;
    //    /* nums[n]=INT_MIN;
    //     nums[-1]=INT_MIN;*/
    //     if(n==1){
    //         return 0;
    //     }
    //     if(n==2){
    //         if(nums[0]>nums[1]) return 0;
    //         return 1;
    //     }
    //     //int mid=(n+1)/2
    //     for(int i=1;i<n-1;i++){
    //         if(nums[i-1]<nums[i]&&nums[i]>nums[i+1]){
    //             ind=i;
    //             break;
    //         }
    //     }
    //     return ind;
    }
};
