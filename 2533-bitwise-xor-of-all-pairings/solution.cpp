class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> num;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //         num.push_back(nums1[i]^nums2[j]);
        //     }
        // }
        // int n=num.size();
        // int out=num[0];
        // for(int k=1;k<n;k++){
        //     out^=num[k];
        // }
        // return out;
        int c1 = nums1.size();
        int c2 = nums2.size();
        int x1 = 0, x2 = 0;
        
        if (c1 % 2 != 0) {
            for (int num : nums2) {
                x2 ^= num;
            }
        }
        if (c2 % 2 != 0) {
            for (int num : nums1) {
                x1 ^= num;
            }
        }
        return x1 ^ x2;
    }
};
